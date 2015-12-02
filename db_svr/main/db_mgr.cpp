#include "db_mgr.h"
#include "logger_macro.h"
#include "mysql++/dbdriver.h"
#include <stdio.h>

DbMgr& DbMgr::Instance()
{
	static DbMgr g_sDbMgr;
	return g_sDbMgr;
}

DbMgr::DbMgr(void)
{
}

DbMgr::~DbMgr(void)
{

}

int DbMgr::Init(const string& host, const int& port, const string& db, const string& user, const string& password)
{
	LOG_DEBUG("DbMgr::Init");
	
	m_sHost = host;
	m_uPort = port;
	m_sDb = db;
	m_sUser = user;
	m_sPassword = password;
	m_uMaxUserid = 0;
	
	//连数据库
	if (0 != ConnectToDb())
	{
		LOG_ERROR("ConnectToDb failed");
		return -1;
	}
	
	return LoadDataFromDb();
}

int DbMgr::ConnectToDb()
{
    try
    {
		// 先设置字符集
        m_conn.set_option(new mysqlpp::SetCharsetNameOption("utf8"));
		
        if (!m_conn.connect(m_sDb.c_str(), m_sHost.c_str(), m_sUser.c_str(), m_sPassword.c_str(), m_uPort))
        {
            LOG_ERROR("DB connection failed: " << m_conn.error());
            return -1;
        }
		
		//设置自动重连
		m_conn.set_option(new mysqlpp::ReconnectOption(true));
		
    }
    catch (const mysqlpp::Exception& e)
    {
        LOG_ERROR("Caught mysqlpp exception: " << e.what());
        return -1; 
    }
    catch (const std::exception& e)
    {
        LOG_ERROR("Caught std exception: " <<  e.what());
        return -1; 
    }
    catch (...)
    {
        LOG_ERROR("Caught unknown exception");
        return -1; 
    }

    LOG_DEBUG("Connected to db ");
    return 0;
}

bool DbMgr::LoadDataFromDb()
{
	stringstream ssSql ;
	ssSql << "select * from user_data";
	LOG_DEBUG("DbMgr::LoadDataFromDb sql: " << ssSql.str());

	try
	{
		mysqlpp::Query q = m_conn.query(ssSql.str().c_str());
		
		if (mysqlpp::StoreQueryResult res = q.store())
		{
			for (mysqlpp::StoreQueryResult::const_iterator it = res.begin(); it != res.end(); ++it)
			{   
				mysqlpp::Row row = *it;
				line::UserData* pUserData = new line::UserData();
				
				uint64_t uUserId = pUserData->user_id();
				m_uMaxUserid = m_uMaxUserid > uUserId ? m_uMaxUserid : uUserId;

				//拼字段
				if(AssemblyUserDataFromMysqlRow(pUserData, row))
				{
					m_UserDataMap[uUserId] = pUserData;
				}		
				
			}   

			LOG_DEBUG("Loaded " << res.num_rows() << " user records");
		}
		else
		{
			LOG_ERROR("Failed to query: " << q.error());
			return false;
		}
	}
	catch (const mysqlpp::Exception& e)
	{
		LOG_ERROR("Caught mysqlpp exception: " << e.what());
		return false; 
	}
	catch (const std::exception& e)
	{
		LOG_ERROR("Caught std exception: " <<  e.what());
		return false; 
	}
	catch (...)
	{
		LOG_ERROR("Caught unknown exception");
		return false; 
	}
	
	UserDataMap::iterator iter = m_UserDataMap.begin();
	for(; iter != m_UserDataMap.end(); iter++)
	{
		LOG_DEBUG("user id : " << iter->first);
	}

	return true;
}

bool DbMgr::AssemblyUserDataFromMysqlRow(line::UserData* pUserData, mysqlpp::Row& row)
{
	if(NULL == pUserData || NULL == row)
	{
		LOG_ERROR("empty pointer : DbMgr::AssemblyUserDataFromMysqlRow");
		return false;
	}
	pUserData->set_user_id(row["id"]);
	pUserData->set_user_name(row["user_name"]);
	pUserData->set_encrypted_psw(row["password"]);
	pUserData->set_lover_id(row["lover_id"]);
	
	return true;
}

bool DbMgr::WriteUserDataToDb(uint64_t user_id)
{
	LOG_DEBUG("DbMgr::WriteUserDataToDb ==> user_id : " << user_id);
	UserDataMap::iterator iter = m_UserDataMap.find(user_id);
	if(iter == m_UserDataMap.end())
	{
		LOG_ERROR("can't find user data. user id : " << user_id);
		return false;
	}
	
	line::UserData* pUserData = iter->second;
	stringstream ssSql;
	ssSql << "replace into user_data set ";
	ssSql << "id =" << pUserData->user_id();
	ssSql << ", user_name = '" << pUserData->user_name();
	ssSql << "', password = '" << pUserData->encrypted_psw();
	ssSql << "', lover_id = " << pUserData->lover_id();
	
	try
	{
		mysqlpp::Query q = m_conn.query(ssSql.str());
        if (!q.execute())
        {
            LOG_ERROR("Failed to execute: " << q.error());
            return false;
        }
    }
    catch (const mysqlpp::Exception& e)
    {
        LOG_ERROR("Caught mysqlpp exception: " << e.what());
        return false; 
    }
    catch (const std::exception& e)
    {
        LOG_ERROR("Caught std exception: " <<  e.what());
        return false; 
    }
    catch (...)
    {
        LOG_ERROR("Caught unknown exception");
        return false; 
    }
	
	return true;
}

bool DbMgr::AddUserData(line::UserData* pUserData)
{
	if(!pUserData)
	{
		LOG_ERROR("empty pUserData");
		return false;
	}
	uint64_t user_id = pUserData->user_id();
	if(user_id == 0)
	{
		user_id = GetNewUserId();
		pUserData->set_user_id(user_id);
	}
	else
	{
		UserDataMap::iterator iter = m_UserDataMap.find(user_id);
		if(iter != m_UserDataMap.end())
		{
			LOG_ERROR("user exists. user id : " << user_id);
			return false;
		}
	}
	
	m_UserDataMap[user_id] = pUserData;
	
	return WriteUserDataToDb(pUserData->user_id());
}

line::UserData* DbMgr::FindUserByUsername(const string& user_name)
{
	UserDataMap::iterator iter = m_UserDataMap.begin();
	for(; iter != m_UserDataMap.end(); iter++)
	{
		if(iter->second->user_name() == user_name)
		{
			return iter->second;
		}
	}
	return NULL;
}
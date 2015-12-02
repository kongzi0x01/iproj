#ifndef DB_SVR_DB_MGR_H
#define DB_SVR_DB_MGR_H

#include <stdint.h>
#include <map>
#include <string>
#include <mysql++/mysql++.h>

#include "proto_util.h"
#include "line.pb.h"
using namespace std;

#define UserDataMap map<uint64_t, line::UserData*> 

class DbMgr
{
public:
	static DbMgr& Instance();
	DbMgr(void);
	~DbMgr(void);
	int Init(const string& host, const int& port, const string& db, const string& user, const string& password);
	bool LoadDataFromDb();
	
	line::UserData* FindUserByUsername(const string& user_name);
	bool AddUserData(line::UserData* pUserData);
                                         
private:
	int ConnectToDb();
	bool AssemblyUserDataFromMysqlRow(line::UserData* pUserData, mysqlpp::Row& row);
	bool WriteUserDataToDb(uint64_t user_id);
	bool GetNewUserId(){ return ++m_uMaxUserid;}
	
private:
    // 数据库连接对象
    mysqlpp::Connection m_conn;
	string m_sHost;
	int m_uPort;
	string m_sDb;
	string m_sUser;
	string m_sPassword;
	uint64_t m_uMaxUserid;
	
	UserDataMap m_UserDataMap;
};

#endif

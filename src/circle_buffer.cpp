#include "circle_buffer.h"
#include "logger_macro.h"

#include <string.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CircleBuffer::CircleBuffer(uint32_t bytes)
{
	Init(bytes);
}

CircleBuffer::~CircleBuffer()
{
	Destory();
}

//追加数据
bool CircleBuffer::AppendData(const char* pData, uint32_t uBytes)
{
	if ( GetSpaceSize() < uBytes )
	{
		MigrateDataToHead();
		if ( GetSpaceSize() < uBytes )
			Grow(uBytes-GetSpaceSize());
	}
	memcpy(GetSpace(), pData, uBytes);
	AddDataSize(uBytes);
	return true;
}


//从buffer移除uBytes大小的数据
uint32_t CircleBuffer::RemoveData(uint32_t uBytes)
{
	if ( uBytes == 0 )
		return 0;

	if ( m_uDataSize > uBytes )	
	{
		m_uDataOffset += uBytes;
		m_uDataSize -= uBytes;
		return uBytes;
	}

	m_uDataOffset = m_uDataSize = 0;
	return m_uDataSize;
}

//把数据迁移到buffer的头部，
//把buffer后面的空间空出来
//如果本身数据已经在头部，则返回false
//空间不足且失败时，请考虑调用Grow增长buffer
bool CircleBuffer::MigrateDataToHead()
{
	if ( m_uDataOffset == 0 )
	{
		Grow();
		return true;
	}

	LOG_DEBUG( "CircleBuffer::MigrateDataToHead" << m_uDataOffset << " => 0");
	//printf("%s %d %u => %u\n", __FILE__, __LINE__, m_uDataOffset, 0);

	if ( m_uDataSize <= m_uDataOffset )
	{//copy区域和数据不重叠,直接copy即可
		memcpy(m_pData, m_pData+m_uDataOffset, m_uDataSize);
		m_uDataOffset = 0;
	}
	else
	{//数据和copy区域有重叠
		for( uint32_t i=0; i<m_uDataSize; ++i)
		{
			m_pData[i] = m_pData[m_uDataOffset+i];
		}
		m_uDataOffset = 0;
	}
	return true;
}

//是否已经到达buffer的尾部
//是的话，可以调用MigrateDataToHead把数据迁移到头部，空出空间
bool CircleBuffer::IsReachTail()
{
	return m_uDataSize+m_uDataOffset == m_uSize;
}

void CircleBuffer::Reset()
{
	m_uDataSize = m_uDataOffset = 0;
}

void CircleBuffer::Grow(uint32_t uSize)
{
	//printf("before %s %d grow %u => %u\n", __FILE__, __LINE__, m_uSize/2, m_uSize);
	uSize = uSize%1024 == 0 ? uSize : (uSize/1024+1)*1024;
	uint32_t uBytes = m_uSize + uSize;
	char* pNewData = new char[uBytes];
	memcpy(pNewData, m_pData+m_uDataOffset, m_uDataSize);
	m_uDataOffset = 0;
	m_uSize = uBytes;
	delete[] m_pData;
	m_pData = pNewData;

	//printf("%s %d grow %u => %u\n", __FILE__, __LINE__, m_uSize/2, m_uSize);
	LOG_DEBUG( "CircleBuffer::Grow " << m_uSize << " => " << m_uSize+uSize ); 
}

void CircleBuffer::Init(uint32_t uBytes)
{
	m_uSize = uBytes;
	m_uDataSize = m_uDataOffset = 0;
	m_pData = new char[uBytes];
	//printf("CircleBuffer::Init : %p\n", m_pData);
}

void CircleBuffer::Destory()
{
	if ( m_pData != NULL )
	{
		delete[] m_pData;
		m_pData = NULL;
	}
}


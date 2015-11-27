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

//׷������
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


//��buffer�Ƴ�uBytes��С������
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

//������Ǩ�Ƶ�buffer��ͷ����
//��buffer����Ŀռ�ճ���
//������������Ѿ���ͷ�����򷵻�false
//�ռ䲻����ʧ��ʱ���뿼�ǵ���Grow����buffer
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
	{//copy��������ݲ��ص�,ֱ��copy����
		memcpy(m_pData, m_pData+m_uDataOffset, m_uDataSize);
		m_uDataOffset = 0;
	}
	else
	{//���ݺ�copy�������ص�
		for( uint32_t i=0; i<m_uDataSize; ++i)
		{
			m_pData[i] = m_pData[m_uDataOffset+i];
		}
		m_uDataOffset = 0;
	}
	return true;
}

//�Ƿ��Ѿ�����buffer��β��
//�ǵĻ������Ե���MigrateDataToHead������Ǩ�Ƶ�ͷ�����ճ��ռ�
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


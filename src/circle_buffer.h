#ifndef _NETKIT_CIRCLE_BUFFER_H_
#define _NETKIT_CIRCLE_BUFFER_H_

#include <stdint.h>
#include <string.h>
#include <assert.h>

#define  DEFAULT_BUFFER_SIZE 10240

class CircleBuffer
{
public:
	CircleBuffer(uint32_t uBytes = DEFAULT_BUFFER_SIZE);
	virtual ~CircleBuffer();

	CircleBuffer(const CircleBuffer& other){assert(false);};
	CircleBuffer& operator=(const CircleBuffer& other){assert(false);};
	CircleBuffer& operator+=(const CircleBuffer& other){assert(false);};

public:
	//a demo to show how to append data
	bool AppendData(const char* pData, uint32_t uBytes);

	//��ȡbuffer�����ݵĵ�ַ
	inline char* GetData() 
	{
		return m_pData + m_uDataOffset;
	};
	
	inline uint32_t GetDataOffset(){return m_uDataOffset;}	

	//��buffer�Ƴ�uBytes��С������
	uint32_t RemoveData(uint32_t uBytes);
		
	//��ȡbuffer����ʹ�õ���ʼ��ַ	
	inline char* GetSpace()
	{
		return m_pData + m_uDataOffset + m_uDataSize;
	};	

	inline uint32_t GetDataSize(){ return m_uDataSize;}
	
	//������Ǩ�Ƶ�buffer��ͷ����
	//��buffer����Ŀռ�ճ���
	//������������Ѿ���ͷ�����򷵻�false
	//�ռ䲻����ʧ��ʱ���뿼�ǵ���Grow����buffer
	bool MigrateDataToHead();

	//�Ƿ��Ѿ�����buffer��β��
	//�ǵĻ������Ե���MigrateDataToHead������Ǩ�Ƶ�ͷ�����ճ��ռ�
	bool IsReachTail();	

public:
	void Reset();//��buffer��λ
	inline uint32_t GetSize() {return m_uSize;} ;//��ȡbuffer�ܵĴ�С

	//��ȡ���õĴ�С
	inline uint32_t GetSpaceSize()
	{
		return m_uSize - m_uDataSize - m_uDataOffset;
	};

	void AddDataSize(uint32_t uBytes){m_uDataSize += uBytes;}

	void Grow(uint32_t uSize = DEFAULT_BUFFER_SIZE);//buffer����	

private:
	
	void Init(uint32_t uBytes);//��ʼ��buffer, ����size���ֽ�
	void Destory();//���buffer���ͷ��ڴ�

private:
	char* m_pData;
	uint32_t m_uSize;	//buffer�ܴ�С
	uint32_t m_uDataSize;	//bufferʹ�õĴ�С
	uint32_t m_uDataOffset;		//buffer��ǰʹ�õ�ƫ����	
};

#endif // _NETKIT_CIRCLE_BUFFER_H_


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

	//获取buffer的数据的地址
	inline char* GetData() 
	{
		return m_pData + m_uDataOffset;
	};
	
	inline uint32_t GetDataOffset(){return m_uDataOffset;}	

	//从buffer移除uBytes大小的数据
	uint32_t RemoveData(uint32_t uBytes);
		
	//获取buffer可以使用的起始地址	
	inline char* GetSpace()
	{
		return m_pData + m_uDataOffset + m_uDataSize;
	};	

	inline uint32_t GetDataSize(){ return m_uDataSize;}
	
	//把数据迁移到buffer的头部，
	//把buffer后面的空间空出来
	//如果本身数据已经在头部，则返回false
	//空间不足且失败时，请考虑调用Grow增长buffer
	bool MigrateDataToHead();

	//是否已经到达buffer的尾部
	//是的话，可以调用MigrateDataToHead把数据迁移到头部，空出空间
	bool IsReachTail();	

public:
	void Reset();//把buffer复位
	inline uint32_t GetSize() {return m_uSize;} ;//获取buffer总的大小

	//获取可用的大小
	inline uint32_t GetSpaceSize()
	{
		return m_uSize - m_uDataSize - m_uDataOffset;
	};

	void AddDataSize(uint32_t uBytes){m_uDataSize += uBytes;}

	void Grow(uint32_t uSize = DEFAULT_BUFFER_SIZE);//buffer增长	

private:
	
	void Init(uint32_t uBytes);//初始化buffer, 分配size个字节
	void Destory();//清除buffer，释放内存

private:
	char* m_pData;
	uint32_t m_uSize;	//buffer总大小
	uint32_t m_uDataSize;	//buffer使用的大小
	uint32_t m_uDataOffset;		//buffer当前使用的偏移量	
};

#endif // _NETKIT_CIRCLE_BUFFER_H_


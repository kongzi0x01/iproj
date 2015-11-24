#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "session.h"

class Session;

class Processor
{
public:
	Processor();
	~Processor();
	
public:
	int Deal(Session& pSession);
	int HandleRequest(const char* pszRequeset, uint32_t uSize, Session& session);	
};

#endif
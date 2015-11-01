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
};

#endif
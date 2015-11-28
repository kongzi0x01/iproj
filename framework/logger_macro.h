#ifndef _IPROJ_LOGGER_H_
#define _IPROJ_LOGGER_H_

#ifdef LOGGER
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>

static log4cplus::Logger logger = log4cplus::Logger::getInstance("Server");
#define LOG_TRACE(a) LOG4CPLUS_TRACE(logger, a)
#define LOG_DEBUG(a) LOG4CPLUS_DEBUG(logger, a)
#define LOG_INFO(a) LOG4CPLUS_INFO(logger, a)
#define LOG_WARN(a) LOG4CPLUS_WARN(logger, a)
#define LOG_ERROR(a) LOG4CPLUS_ERROR(logger, a)
#define LOG_FATAL(a) LOG4CPLUS_FATAL(logger, a)

#else // #match ifdef LOGGER  else

#define LOG_TRACE(a)
#define LOG_DEBUG(a) 
#define LOG_INFO(a) 
#define LOG_WARN(a) 
#define LOG_ERROR(a) 
#define LOG_FATAL(a) 

#endif	//match ifdef LOGGER

#endif	//match ifndef _IPROJ_LOGGER_H_ 


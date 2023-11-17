#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// turn off debug and trace logs in release mode
#if KRELEASE == 1
    #define LOG_DEBUG_ENABLED 0
    #define LOG_TRACE_ENABLED 0
#endif


typedef enum {
    LOG_LEVEL_FATAL     = 0,
    LOG_LEVEL_ERROR     = 1,
    LOG_LEVEL_WARN      = 2, 
    LOG_LEVEL_INFO      = 3, 
    LOG_LEVEL_DEBUG     = 4,    // only in debug mode
    LOG_LEVEL_TRACE     = 5     // only in debug mode
} log_level;

b8 initialize_logging();
void shutdown_logging();

KAPI void log_output(log_level level, const char *message, ...);

// ##__VAR_ARGS__ is a compiler specific argument (gcc, clang)
// we wlays wnat to report fatal errors so we define it no matter what
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__)


#ifndef KERROR
    #define KERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__)
#endif

// other log levels are optional and depend on the type of build
// so we check which one to include 


// warning level log
#if LOG_WARN_ENABLED == 1
    // if log warn level is enabled, then pass the message as warning
    #define KWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__)
#else
    // if not, do nothing!
    #define KWARN(message, ...)
#endif


// info level log 
#if LOG_INFO_ENABLED == 1
    // if log info level is enabled, then pass the message as info
    #define KINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__)
#else
    // if not, do nothing!
    #define KINFO(message, ...)
#endif


// debug level log 
#if LOG_DEBUG_ENABLED == 1
    // if log debug level is enabled, then pass the message as debug
    #define KDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)
#else
    // if not, do nothing!
    #define KEBUG(message, ...)
#endif


// trace level log 
#if LOG_TRACE_ENABLED == 1
    // if log trace level is enabled, then pass the message as trace
    #define KTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__)
#else
    // if not, do nothing!
    #define KTRACE(message, ...)
#endif





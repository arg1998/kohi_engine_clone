#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// turn off debug and trace logs in release mode
#if KRELEASE == 1
    #define LOG_DEBUG_ENABELD 0
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
#define KFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VAR_ARGS__)
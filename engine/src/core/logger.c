#include "logger.h"
#include "asserts.h"


//TODO: temporary 
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


b8 initialize_logging(){
    //TODO: implement me!
    return TRUE;
}

void shutdown_logging(){
    //TODO: implement me!
}

void log_output(log_level level, const char * message, ...){
    const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]:  ", "[INFO]:  ", "[DEBUG]: ", "[TRACE]: "};
    // b8 is_error = level < 2;

    char buffer[32000];
    memset(buffer, 0, sizeof(buffer));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(buffer, 32000, message, arg_ptr);
    va_end(arg_ptr);

    char out_message[32000];
    sprintf(out_message, "%s%s\n", level_strings[level], buffer);

    // TODO: platform-specific output.
    printf("%s", out_message);
}


void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line){
    log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, at line: %d\n", expression, message, file, line);
}
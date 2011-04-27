#include "multimon.h"

extern int multimon_debug_level = 0;

#ifdef DEBUG
void verbprintf(int verb_level, const char *fmt, ...)
{
        va_list args;
        
        va_start(args, fmt);
        if (verb_level <= multimon_debug_level)
                vfprintf(stdout, fmt, args);
        va_end(args);
}
#else
void verbprintf(int verb_level, const char *fmt, ...)
{
}
#endif

#ifndef PROC_WHATTIME_H
#define PROC_WHATTIME_H

#include "procps.h"

EXTERN_C_BEGIN

__attribute__ ((visibility ("default"))) extern void print_uptime(int human_readable);
__attribute__ ((visibility ("default"))) extern char *sprint_uptime(int human_readable);

EXTERN_C_END

#endif

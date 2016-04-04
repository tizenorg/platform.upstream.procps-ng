#ifndef PROCPS_PROC_WCHAN_H
#define PROCPS_PROC_WCHAN_H

#include "procps.h"

EXTERN_C_BEGIN

__attribute__ ((visibility ("default"))) extern const char * lookup_wchan(unsigned KLONG address, unsigned pid);
__attribute__ ((visibility ("default"))) extern int   open_psdb(const char *__restrict override);
__attribute__ ((visibility ("default"))) extern int   open_psdb_message(const char *__restrict override, message_fn message);

EXTERN_C_END

#endif

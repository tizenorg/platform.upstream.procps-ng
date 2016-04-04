#ifndef PROCPS_PROC_ALLOC_H
#define PROCPS_PROC_ALLOC_H

#include "procps.h"

EXTERN_C_BEGIN

 /* change xalloc_err_handler to override the default fprintf(stderr... */
__attribute__ ((visibility ("default"))) extern message_fn xalloc_err_handler;

__attribute__ ((visibility ("default"))) extern void *xcalloc(unsigned int size) MALLOC;
__attribute__ ((visibility ("default"))) extern void *xmalloc(size_t size) MALLOC;
__attribute__ ((visibility ("default"))) extern void *xrealloc(void *oldp, unsigned int size) MALLOC;
__attribute__ ((visibility ("default"))) extern char *xstrdup(const char *str) MALLOC;

EXTERN_C_END

#endif

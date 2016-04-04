#ifndef PROC_SIG_H
#define PROC_SIG_H
/*
 * Copyright 1998-2003 by Albert Cahalan; all rights resered.
 * This file may be used subject to the terms and conditions of the
 * GNU Library General Public License Version 2, or any later version
 * at your option, as published by the Free Software Foundation.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Library General Public License for more details.
 */

#include "procps.h"

EXTERN_C_BEGIN

/* return -1 on failure */
__attribute__ ((visibility ("default"))) extern int signal_name_to_number(const char *__restrict name);

__attribute__ ((visibility ("default"))) extern const char *signal_number_to_name(int signo);

__attribute__ ((visibility ("default"))) extern int print_given_signals(int argc, const char *__restrict const *__restrict argv, int max_line);

__attribute__ ((visibility ("default"))) extern char *strtosig(const char *__restrict s);

__attribute__ ((visibility ("default"))) extern void pretty_print_signals(void);

__attribute__ ((visibility ("default"))) extern void unix_print_signals(void);

EXTERN_C_END
#endif

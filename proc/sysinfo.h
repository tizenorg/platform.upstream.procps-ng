#ifndef PROC_SYSINFO_H
#define PROC_SYSINFO_H
#include <sys/types.h>
#include <sys/dir.h>
#include "procps.h"

EXTERN_C_BEGIN

__attribute__ ((visibility ("default"))) extern unsigned long long Hertz;   /* clock tick frequency */
__attribute__ ((visibility ("default"))) extern long smp_num_cpus;          /* number of CPUs */
__attribute__ ((visibility ("default"))) extern int have_privs;             /* boolean, true if setuid or similar */

#if 0
#define JT double
extern void eight_cpu_numbers(JT *uret, JT *nret, JT *sret, JT *iret, JT *wret, JT *xret, JT *yret, JT *zret);
#undef JT
#endif

__attribute__ ((visibility ("default"))) extern int        uptime (double *uptime_secs, double *idle_secs);
__attribute__ ((visibility ("default"))) extern unsigned long getbtime(void);
__attribute__ ((visibility ("default"))) extern void       loadavg(double *av1, double *av5, double *av15);


/* obsolete */
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_shared;
/* old but still kicking -- the important stuff */
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_buffers;
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_cached;
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_free;
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_total;
__attribute__ ((visibility ("default"))) extern unsigned long kb_swap_free;
__attribute__ ((visibility ("default"))) extern unsigned long kb_swap_total;
/* recently introduced */
__attribute__ ((visibility ("default"))) extern unsigned long kb_high_free;
__attribute__ ((visibility ("default"))) extern unsigned long kb_high_total;
__attribute__ ((visibility ("default"))) extern unsigned long kb_low_free;
__attribute__ ((visibility ("default"))) extern unsigned long kb_low_total;
/* 2.4.xx era */
__attribute__ ((visibility ("default"))) extern unsigned long kb_active;
__attribute__ ((visibility ("default"))) extern unsigned long kb_inact_laundry;  // grrr...
__attribute__ ((visibility ("default"))) extern unsigned long kb_inact_dirty;
__attribute__ ((visibility ("default"))) extern unsigned long kb_inact_clean;
__attribute__ ((visibility ("default"))) extern unsigned long kb_inact_target;
__attribute__ ((visibility ("default"))) extern unsigned long kb_swap_cached;  /* late 2.4+ */
/* derived values */
__attribute__ ((visibility ("default"))) extern unsigned long kb_swap_used;
__attribute__ ((visibility ("default"))) extern unsigned long kb_main_used;
/* 2.5.41+ */
__attribute__ ((visibility ("default"))) extern unsigned long kb_writeback;
__attribute__ ((visibility ("default"))) extern unsigned long kb_slab;
__attribute__ ((visibility ("default"))) extern unsigned long nr_reversemaps;
__attribute__ ((visibility ("default"))) extern unsigned long kb_committed_as;
__attribute__ ((visibility ("default"))) extern unsigned long kb_dirty;
__attribute__ ((visibility ("default"))) extern unsigned long kb_inactive;
__attribute__ ((visibility ("default"))) extern unsigned long kb_mapped;
__attribute__ ((visibility ("default"))) extern unsigned long kb_pagetables;

#define BUFFSIZE (64*1024)
typedef unsigned long long jiff;
__attribute__ ((visibility ("default"))) extern void getstat(jiff *__restrict cuse, jiff *__restrict cice, jiff *__restrict csys, jiff *__restrict cide, jiff *__restrict ciow, jiff *__restrict cxxx, jiff *__restrict cyyy, jiff *__restrict czzz,
	     unsigned long *__restrict pin, unsigned long *__restrict pout, unsigned long *__restrict s_in, unsigned long *__restrict sout,
	     unsigned *__restrict intr, unsigned *__restrict ctxt,
	     unsigned int *__restrict running, unsigned int *__restrict blocked,
	     unsigned int *__restrict btime, unsigned int *__restrict processes);

__attribute__ ((visibility ("default"))) extern void meminfo(void);


__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_dirty;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_writeback;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_pagecache;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_page_table_pages;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_reverse_maps;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_mapped;
__attribute__ ((visibility ("default"))) extern unsigned long vm_nr_slab;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgpgin;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgpgout;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pswpin;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pswpout;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgalloc;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgfree;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgactivate;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgdeactivate;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgfault;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgmajfault;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgscan;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgrefill;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pgsteal;
__attribute__ ((visibility ("default"))) extern unsigned long vm_kswapd_steal;
__attribute__ ((visibility ("default"))) extern unsigned long vm_pageoutrun;
__attribute__ ((visibility ("default"))) extern unsigned long vm_allocstall;

__attribute__ ((visibility ("default"))) extern void vminfo(void);

typedef struct disk_stat{
	unsigned long long reads_sectors;
	unsigned long long written_sectors;
	char               disk_name [16];
	unsigned           inprogress_IO;
	unsigned           merged_reads;
	unsigned           merged_writes;
	unsigned           milli_reading;
	unsigned           milli_spent_IO;
	unsigned           milli_writing;
	unsigned           partitions;
	unsigned           reads;
	unsigned           weighted_milli_spent_IO;
	unsigned           writes;
}disk_stat;

typedef struct partition_stat{
	char partition_name [16];
	unsigned long long reads_sectors;
	unsigned           parent_disk;  // index into a struct disk_stat array
	unsigned           reads;
	unsigned           writes;
	unsigned long long requested_writes;
}partition_stat;

__attribute__ ((visibility ("default"))) extern unsigned int getpartitions_num(struct disk_stat *disks, int ndisks);
__attribute__ ((visibility ("default"))) extern unsigned int getdiskstat (struct disk_stat**,struct partition_stat**);

typedef struct slab_cache{
	char name[48];
	unsigned active_objs;
	unsigned num_objs;
	unsigned objsize;
	unsigned objperslab;
}slab_cache;

__attribute__ ((visibility ("default"))) extern unsigned int getslabinfo (struct slab_cache**);

__attribute__ ((visibility ("default"))) extern unsigned get_pid_digits(void) FUNCTION;

__attribute__ ((visibility ("default"))) extern void cpuinfo (void);

EXTERN_C_END
#endif /* SYSINFO_H */

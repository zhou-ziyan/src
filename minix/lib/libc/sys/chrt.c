#include <sys/cdefs.h>
#include "namespace.h"
#include <lib.h>

#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int chrt(long deadline)
{
  struct timespec time;
  message m;
  memset(&m, 0, sizeof(m));

  if (deadline > 0)
  {
    alarm((unsigned int)deadline);/* the alarm */
    clock_gettime(CLOCK_REALTIME, &time);
    deadline = time.tv_sec + deadline;
    m.m2_l1 = deadline; /* store the deadline */
    return (_syscall(PM_PROC_NR, PM_CHRT, &m));
  }

  return 0;
}
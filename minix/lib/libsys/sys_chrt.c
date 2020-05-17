#include "syslib.h"

int sys_chrt(proc_endpoint, deadline)
endpoint_t proc_endpoint;
long deadline;
{
  message m;
  int r;
  
  m.m2_i1 = proc_endpoint;
  m.m2_l1 = deadline;
  r=_kernel_call(SYS_CHRT, &m);
  return r;
}

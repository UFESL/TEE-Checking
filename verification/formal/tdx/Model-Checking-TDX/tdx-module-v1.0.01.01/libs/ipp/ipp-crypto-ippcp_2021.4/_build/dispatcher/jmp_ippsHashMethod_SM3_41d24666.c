#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const IppsHashMethod* (*IPP_PROC)(void);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const IppsHashMethod* in_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* m7_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* n8_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* y8_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* e9_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* l9_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* n0_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* k0_ippsHashMethod_SM3(void);
extern  const IppsHashMethod* k1_ippsHashMethod_SM3(void);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMethod_SM3,
	(IPP_PROC)m7_ippsHashMethod_SM3,
	(IPP_PROC)n8_ippsHashMethod_SM3,
	(IPP_PROC)y8_ippsHashMethod_SM3,
	(IPP_PROC)e9_ippsHashMethod_SM3,
	(IPP_PROC)l9_ippsHashMethod_SM3,
	(IPP_PROC)n0_ippsHashMethod_SM3,
	(IPP_PROC)k0_ippsHashMethod_SM3,
	(IPP_PROC)k1_ippsHashMethod_SM3
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const IppsHashMethod*, ippsHashMethod_SM3,(void))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const IppsHashMethod*, in_ippsHashMethod_SM3,(void))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMethod_SM3]
        jmp  rax
  }
};

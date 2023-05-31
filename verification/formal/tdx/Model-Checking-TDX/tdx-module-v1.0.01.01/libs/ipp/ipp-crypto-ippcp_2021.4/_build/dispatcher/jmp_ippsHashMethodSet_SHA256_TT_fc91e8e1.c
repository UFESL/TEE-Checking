#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  IppStatus (*IPP_PROC)(IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  IppStatus in_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus m7_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus n8_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus y8_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus e9_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus l9_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus n0_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus k0_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
extern  IppStatus k1_ippsHashMethodSet_SHA256_TT(IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)m7_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)n8_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)y8_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)e9_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)l9_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)n0_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)k0_ippsHashMethodSet_SHA256_TT,
	(IPP_PROC)k1_ippsHashMethodSet_SHA256_TT
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( IppStatus, ippsHashMethodSet_SHA256_TT,(IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( IppStatus, in_ippsHashMethodSet_SHA256_TT,(IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMethodSet_SHA256_TT]
        jmp  rax
  }
};

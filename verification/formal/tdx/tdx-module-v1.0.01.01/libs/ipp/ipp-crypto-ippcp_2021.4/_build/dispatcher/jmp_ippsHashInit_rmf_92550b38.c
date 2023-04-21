#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus m7_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus n8_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus y8_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus e9_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus l9_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus n0_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus k0_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
extern IppStatus k1_ippsHashInit_rmf(IppsHashState_rmf* pState, const IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashInit_rmf,
	(IPP_PROC)m7_ippsHashInit_rmf,
	(IPP_PROC)n8_ippsHashInit_rmf,
	(IPP_PROC)y8_ippsHashInit_rmf,
	(IPP_PROC)e9_ippsHashInit_rmf,
	(IPP_PROC)l9_ippsHashInit_rmf,
	(IPP_PROC)n0_ippsHashInit_rmf,
	(IPP_PROC)k0_ippsHashInit_rmf,
	(IPP_PROC)k1_ippsHashInit_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashInit_rmf,(IppsHashState_rmf* pState, const IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashInit_rmf,(IppsHashState_rmf* pState, const IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashInit_rmf]
        jmp  rax
  }
};

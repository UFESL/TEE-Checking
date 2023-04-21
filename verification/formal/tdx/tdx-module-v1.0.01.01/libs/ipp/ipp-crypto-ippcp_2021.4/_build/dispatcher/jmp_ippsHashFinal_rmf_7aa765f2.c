#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, IppsHashState_rmf* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus m7_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus n8_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus y8_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus e9_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus l9_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus n0_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus k0_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
extern IppStatus k1_ippsHashFinal_rmf(Ipp8u* pMD, IppsHashState_rmf* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashFinal_rmf,
	(IPP_PROC)m7_ippsHashFinal_rmf,
	(IPP_PROC)n8_ippsHashFinal_rmf,
	(IPP_PROC)y8_ippsHashFinal_rmf,
	(IPP_PROC)e9_ippsHashFinal_rmf,
	(IPP_PROC)l9_ippsHashFinal_rmf,
	(IPP_PROC)n0_ippsHashFinal_rmf,
	(IPP_PROC)k0_ippsHashFinal_rmf,
	(IPP_PROC)k1_ippsHashFinal_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashFinal_rmf,(Ipp8u* pMD, IppsHashState_rmf* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashFinal_rmf,(Ipp8u* pMD, IppsHashState_rmf* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashFinal_rmf]
        jmp  rax
  }
};

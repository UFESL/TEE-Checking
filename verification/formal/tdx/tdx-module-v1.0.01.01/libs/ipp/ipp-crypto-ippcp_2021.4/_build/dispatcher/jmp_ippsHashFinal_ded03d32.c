#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, IppsHashState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus m7_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus n8_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus y8_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus e9_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus l9_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus n0_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus k0_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
extern IppStatus k1_ippsHashFinal(Ipp8u* pMD, IppsHashState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashFinal,
	(IPP_PROC)m7_ippsHashFinal,
	(IPP_PROC)n8_ippsHashFinal,
	(IPP_PROC)y8_ippsHashFinal,
	(IPP_PROC)e9_ippsHashFinal,
	(IPP_PROC)l9_ippsHashFinal,
	(IPP_PROC)n0_ippsHashFinal,
	(IPP_PROC)k0_ippsHashFinal,
	(IPP_PROC)k1_ippsHashFinal
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashFinal,(Ipp8u* pMD, IppsHashState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashFinal,(Ipp8u* pMD, IppsHashState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashFinal]
        jmp  rax
  }
};

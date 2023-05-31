#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, int len, IppsHashState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus m7_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus n8_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus y8_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus e9_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus l9_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus n0_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus k0_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
extern IppStatus k1_ippsHashUpdate(const Ipp8u* pSrc, int len, IppsHashState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashUpdate,
	(IPP_PROC)m7_ippsHashUpdate,
	(IPP_PROC)n8_ippsHashUpdate,
	(IPP_PROC)y8_ippsHashUpdate,
	(IPP_PROC)e9_ippsHashUpdate,
	(IPP_PROC)l9_ippsHashUpdate,
	(IPP_PROC)n0_ippsHashUpdate,
	(IPP_PROC)k0_ippsHashUpdate,
	(IPP_PROC)k1_ippsHashUpdate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashUpdate,(const Ipp8u* pSrc, int len, IppsHashState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashUpdate,(const Ipp8u* pSrc, int len, IppsHashState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashUpdate]
        jmp  rax
  }
};

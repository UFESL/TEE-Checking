#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsHashState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus m7_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus n8_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus y8_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus e9_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus l9_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus n0_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus k0_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
extern IppStatus k1_ippsHashUnpack(const Ipp8u* pBuffer, IppsHashState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashUnpack,
	(IPP_PROC)m7_ippsHashUnpack,
	(IPP_PROC)n8_ippsHashUnpack,
	(IPP_PROC)y8_ippsHashUnpack,
	(IPP_PROC)e9_ippsHashUnpack,
	(IPP_PROC)l9_ippsHashUnpack,
	(IPP_PROC)n0_ippsHashUnpack,
	(IPP_PROC)k0_ippsHashUnpack,
	(IPP_PROC)k1_ippsHashUnpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashUnpack,(const Ipp8u* pBuffer, IppsHashState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashUnpack,(const Ipp8u* pBuffer, IppsHashState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashUnpack]
        jmp  rax
  }
};

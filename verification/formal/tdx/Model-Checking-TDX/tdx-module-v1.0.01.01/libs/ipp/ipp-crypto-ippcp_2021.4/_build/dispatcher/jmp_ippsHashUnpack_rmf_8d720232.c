#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsHashState_rmf* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus m7_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus n8_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus y8_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus e9_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus l9_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus n0_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus k0_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
extern IppStatus k1_ippsHashUnpack_rmf(const Ipp8u* pBuffer, IppsHashState_rmf* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashUnpack_rmf,
	(IPP_PROC)m7_ippsHashUnpack_rmf,
	(IPP_PROC)n8_ippsHashUnpack_rmf,
	(IPP_PROC)y8_ippsHashUnpack_rmf,
	(IPP_PROC)e9_ippsHashUnpack_rmf,
	(IPP_PROC)l9_ippsHashUnpack_rmf,
	(IPP_PROC)n0_ippsHashUnpack_rmf,
	(IPP_PROC)k0_ippsHashUnpack_rmf,
	(IPP_PROC)k1_ippsHashUnpack_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashUnpack_rmf,(const Ipp8u* pBuffer, IppsHashState_rmf* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashUnpack_rmf,(const Ipp8u* pBuffer, IppsHashState_rmf* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashUnpack_rmf]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus m7_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus n8_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus y8_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus e9_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus l9_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus n0_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus k0_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
extern IppStatus k1_ippsHashGetTag_rmf(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashGetTag_rmf,
	(IPP_PROC)m7_ippsHashGetTag_rmf,
	(IPP_PROC)n8_ippsHashGetTag_rmf,
	(IPP_PROC)y8_ippsHashGetTag_rmf,
	(IPP_PROC)e9_ippsHashGetTag_rmf,
	(IPP_PROC)l9_ippsHashGetTag_rmf,
	(IPP_PROC)n0_ippsHashGetTag_rmf,
	(IPP_PROC)k0_ippsHashGetTag_rmf,
	(IPP_PROC)k1_ippsHashGetTag_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashGetTag_rmf,(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashGetTag_rmf,(Ipp8u* pMD, int tagLen, const IppsHashState_rmf* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashGetTag_rmf]
        jmp  rax
  }
};

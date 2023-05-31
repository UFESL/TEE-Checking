#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus m7_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus n8_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus y8_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus e9_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus l9_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus n0_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus k0_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
extern IppStatus k1_ippsHMACGetTag_rmf(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACGetTag_rmf,
	(IPP_PROC)m7_ippsHMACGetTag_rmf,
	(IPP_PROC)n8_ippsHMACGetTag_rmf,
	(IPP_PROC)y8_ippsHMACGetTag_rmf,
	(IPP_PROC)e9_ippsHMACGetTag_rmf,
	(IPP_PROC)l9_ippsHMACGetTag_rmf,
	(IPP_PROC)n0_ippsHMACGetTag_rmf,
	(IPP_PROC)k0_ippsHMACGetTag_rmf,
	(IPP_PROC)k1_ippsHMACGetTag_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACGetTag_rmf,(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACGetTag_rmf,(Ipp8u* pMD, int mdLen, const IppsHMACState_rmf* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACGetTag_rmf]
        jmp  rax
  }
};

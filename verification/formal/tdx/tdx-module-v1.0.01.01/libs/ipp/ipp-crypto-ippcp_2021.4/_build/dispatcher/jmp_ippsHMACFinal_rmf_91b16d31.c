#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus m7_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus n8_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus y8_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus e9_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus l9_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus n0_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus k0_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
extern IppStatus k1_ippsHMACFinal_rmf(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACFinal_rmf,
	(IPP_PROC)m7_ippsHMACFinal_rmf,
	(IPP_PROC)n8_ippsHMACFinal_rmf,
	(IPP_PROC)y8_ippsHMACFinal_rmf,
	(IPP_PROC)e9_ippsHMACFinal_rmf,
	(IPP_PROC)l9_ippsHMACFinal_rmf,
	(IPP_PROC)n0_ippsHMACFinal_rmf,
	(IPP_PROC)k0_ippsHMACFinal_rmf,
	(IPP_PROC)k1_ippsHMACFinal_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACFinal_rmf,(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACFinal_rmf,(Ipp8u* pMD, int mdLen, IppsHMACState_rmf* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACFinal_rmf]
        jmp  rax
  }
};

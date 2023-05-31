#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus m7_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus n8_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus y8_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus e9_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus l9_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus n0_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus k0_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
extern IppStatus k1_ippsHMACDuplicate_rmf(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACDuplicate_rmf,
	(IPP_PROC)m7_ippsHMACDuplicate_rmf,
	(IPP_PROC)n8_ippsHMACDuplicate_rmf,
	(IPP_PROC)y8_ippsHMACDuplicate_rmf,
	(IPP_PROC)e9_ippsHMACDuplicate_rmf,
	(IPP_PROC)l9_ippsHMACDuplicate_rmf,
	(IPP_PROC)n0_ippsHMACDuplicate_rmf,
	(IPP_PROC)k0_ippsHMACDuplicate_rmf,
	(IPP_PROC)k1_ippsHMACDuplicate_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACDuplicate_rmf,(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACDuplicate_rmf,(const IppsHMACState_rmf* pSrcCtx, IppsHMACState_rmf* pDstCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACDuplicate_rmf]
        jmp  rax
  }
};

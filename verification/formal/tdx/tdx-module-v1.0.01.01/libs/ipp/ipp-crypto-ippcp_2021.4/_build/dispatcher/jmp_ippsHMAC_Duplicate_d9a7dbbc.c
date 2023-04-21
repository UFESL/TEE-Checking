#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus m7_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus n8_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus y8_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus e9_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus l9_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus n0_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus k0_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
extern IppStatus k1_ippsHMAC_Duplicate(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMAC_Duplicate,
	(IPP_PROC)m7_ippsHMAC_Duplicate,
	(IPP_PROC)n8_ippsHMAC_Duplicate,
	(IPP_PROC)y8_ippsHMAC_Duplicate,
	(IPP_PROC)e9_ippsHMAC_Duplicate,
	(IPP_PROC)l9_ippsHMAC_Duplicate,
	(IPP_PROC)n0_ippsHMAC_Duplicate,
	(IPP_PROC)k0_ippsHMAC_Duplicate,
	(IPP_PROC)k1_ippsHMAC_Duplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMAC_Duplicate,(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMAC_Duplicate,(const IppsHMACState* pSrcCtx, IppsHMACState* pDstCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMAC_Duplicate]
        jmp  rax
  }
};

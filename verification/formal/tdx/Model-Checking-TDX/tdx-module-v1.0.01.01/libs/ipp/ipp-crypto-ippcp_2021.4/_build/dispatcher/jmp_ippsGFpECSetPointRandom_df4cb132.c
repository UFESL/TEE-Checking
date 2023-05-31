#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSetPointRandom(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetPointRandom,
	(IPP_PROC)m7_ippsGFpECSetPointRandom,
	(IPP_PROC)n8_ippsGFpECSetPointRandom,
	(IPP_PROC)y8_ippsGFpECSetPointRandom,
	(IPP_PROC)e9_ippsGFpECSetPointRandom,
	(IPP_PROC)l9_ippsGFpECSetPointRandom,
	(IPP_PROC)n0_ippsGFpECSetPointRandom,
	(IPP_PROC)k0_ippsGFpECSetPointRandom,
	(IPP_PROC)k1_ippsGFpECSetPointRandom
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetPointRandom,(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetPointRandom,(IppsGFpECPoint* pPoint, IppsGFpECState* pEC, IppBitSupplier rndFunc, void* pRndParam, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetPointRandom]
        jmp  rax
  }
};

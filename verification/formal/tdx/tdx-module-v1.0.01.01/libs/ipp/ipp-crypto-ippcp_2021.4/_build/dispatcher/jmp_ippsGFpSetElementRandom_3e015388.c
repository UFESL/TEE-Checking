#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsGFpSetElementRandom(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSetElementRandom,
	(IPP_PROC)m7_ippsGFpSetElementRandom,
	(IPP_PROC)n8_ippsGFpSetElementRandom,
	(IPP_PROC)y8_ippsGFpSetElementRandom,
	(IPP_PROC)e9_ippsGFpSetElementRandom,
	(IPP_PROC)l9_ippsGFpSetElementRandom,
	(IPP_PROC)n0_ippsGFpSetElementRandom,
	(IPP_PROC)k0_ippsGFpSetElementRandom,
	(IPP_PROC)k1_ippsGFpSetElementRandom
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSetElementRandom,(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSetElementRandom,(IppsGFpElement* pR, IppsGFpState* pGFp, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSetElementRandom]
        jmp  rax
  }
};

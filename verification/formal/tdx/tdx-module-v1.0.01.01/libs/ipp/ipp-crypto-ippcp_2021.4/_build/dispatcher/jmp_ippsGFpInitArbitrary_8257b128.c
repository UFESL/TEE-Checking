#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpInitArbitrary(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpInitArbitrary,
	(IPP_PROC)m7_ippsGFpInitArbitrary,
	(IPP_PROC)n8_ippsGFpInitArbitrary,
	(IPP_PROC)y8_ippsGFpInitArbitrary,
	(IPP_PROC)e9_ippsGFpInitArbitrary,
	(IPP_PROC)l9_ippsGFpInitArbitrary,
	(IPP_PROC)n0_ippsGFpInitArbitrary,
	(IPP_PROC)k0_ippsGFpInitArbitrary,
	(IPP_PROC)k1_ippsGFpInitArbitrary
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpInitArbitrary,(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpInitArbitrary,(const IppsBigNumState* pPrime, int primeBitSize, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpInitArbitrary]
        jmp  rax
  }
};

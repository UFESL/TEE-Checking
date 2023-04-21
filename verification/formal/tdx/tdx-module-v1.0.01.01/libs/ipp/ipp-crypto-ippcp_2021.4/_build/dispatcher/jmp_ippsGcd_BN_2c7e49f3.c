#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus m7_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus n8_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus y8_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus e9_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus l9_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus n0_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus k0_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
extern IppStatus k1_ippsGcd_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGcd_BN,
	(IPP_PROC)m7_ippsGcd_BN,
	(IPP_PROC)n8_ippsGcd_BN,
	(IPP_PROC)y8_ippsGcd_BN,
	(IPP_PROC)e9_ippsGcd_BN,
	(IPP_PROC)l9_ippsGcd_BN,
	(IPP_PROC)n0_ippsGcd_BN,
	(IPP_PROC)k0_ippsGcd_BN,
	(IPP_PROC)k1_ippsGcd_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGcd_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGcd_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGCD))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGcd_BN]
        jmp  rax
  }
};

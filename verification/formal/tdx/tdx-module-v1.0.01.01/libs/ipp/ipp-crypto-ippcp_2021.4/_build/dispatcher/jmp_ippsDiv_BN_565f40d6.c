#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus m7_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus n8_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus y8_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus e9_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus l9_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus n0_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus k0_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
extern IppStatus k1_ippsDiv_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDiv_BN,
	(IPP_PROC)m7_ippsDiv_BN,
	(IPP_PROC)n8_ippsDiv_BN,
	(IPP_PROC)y8_ippsDiv_BN,
	(IPP_PROC)e9_ippsDiv_BN,
	(IPP_PROC)l9_ippsDiv_BN,
	(IPP_PROC)n0_ippsDiv_BN,
	(IPP_PROC)k0_ippsDiv_BN,
	(IPP_PROC)k1_ippsDiv_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDiv_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDiv_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pQ, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDiv_BN]
        jmp  rax
  }
};

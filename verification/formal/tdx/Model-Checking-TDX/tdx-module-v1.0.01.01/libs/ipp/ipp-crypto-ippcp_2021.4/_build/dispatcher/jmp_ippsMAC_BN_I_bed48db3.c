#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus m7_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus n8_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus y8_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus e9_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus l9_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus n0_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus k0_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus k1_ippsMAC_BN_I(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMAC_BN_I,
	(IPP_PROC)m7_ippsMAC_BN_I,
	(IPP_PROC)n8_ippsMAC_BN_I,
	(IPP_PROC)y8_ippsMAC_BN_I,
	(IPP_PROC)e9_ippsMAC_BN_I,
	(IPP_PROC)l9_ippsMAC_BN_I,
	(IPP_PROC)n0_ippsMAC_BN_I,
	(IPP_PROC)k0_ippsMAC_BN_I,
	(IPP_PROC)k1_ippsMAC_BN_I
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMAC_BN_I,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMAC_BN_I,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMAC_BN_I]
        jmp  rax
  }
};

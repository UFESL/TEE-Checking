#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus m7_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus n8_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus y8_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus e9_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus l9_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus n0_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus k0_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
extern IppStatus k1_ippsModInv_BN(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsModInv_BN,
	(IPP_PROC)m7_ippsModInv_BN,
	(IPP_PROC)n8_ippsModInv_BN,
	(IPP_PROC)y8_ippsModInv_BN,
	(IPP_PROC)e9_ippsModInv_BN,
	(IPP_PROC)l9_ippsModInv_BN,
	(IPP_PROC)n0_ippsModInv_BN,
	(IPP_PROC)k0_ippsModInv_BN,
	(IPP_PROC)k1_ippsModInv_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsModInv_BN,(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsModInv_BN,(IppsBigNumState* pA, IppsBigNumState* pM, IppsBigNumState* pInv))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsModInv_BN]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus m7_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus n8_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus y8_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus e9_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus l9_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus n0_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus k0_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
extern IppStatus k1_ippsSub_BN(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSub_BN,
	(IPP_PROC)m7_ippsSub_BN,
	(IPP_PROC)n8_ippsSub_BN,
	(IPP_PROC)y8_ippsSub_BN,
	(IPP_PROC)e9_ippsSub_BN,
	(IPP_PROC)l9_ippsSub_BN,
	(IPP_PROC)n0_ippsSub_BN,
	(IPP_PROC)k0_ippsSub_BN,
	(IPP_PROC)k1_ippsSub_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSub_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSub_BN,(IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSub_BN]
        jmp  rax
  }
};

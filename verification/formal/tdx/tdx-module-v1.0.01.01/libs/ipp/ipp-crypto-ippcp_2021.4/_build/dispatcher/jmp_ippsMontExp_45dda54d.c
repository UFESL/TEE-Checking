#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus m7_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus n8_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus y8_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus e9_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus l9_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus n0_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus k0_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus k1_ippsMontExp(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontExp,
	(IPP_PROC)m7_ippsMontExp,
	(IPP_PROC)n8_ippsMontExp,
	(IPP_PROC)y8_ippsMontExp,
	(IPP_PROC)e9_ippsMontExp,
	(IPP_PROC)l9_ippsMontExp,
	(IPP_PROC)n0_ippsMontExp,
	(IPP_PROC)k0_ippsMontExp,
	(IPP_PROC)k1_ippsMontExp
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontExp,(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontExp,(const IppsBigNumState* pA, const IppsBigNumState* pE, IppsMontState* m, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontExp]
        jmp  rax
  }
};

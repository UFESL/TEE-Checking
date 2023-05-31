#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus m7_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus n8_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus y8_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus e9_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus l9_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus n0_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus k0_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
extern IppStatus k1_ippsMontMul(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontMul,
	(IPP_PROC)m7_ippsMontMul,
	(IPP_PROC)n8_ippsMontMul,
	(IPP_PROC)y8_ippsMontMul,
	(IPP_PROC)e9_ippsMontMul,
	(IPP_PROC)l9_ippsMontMul,
	(IPP_PROC)n0_ippsMontMul,
	(IPP_PROC)k0_ippsMontMul,
	(IPP_PROC)k1_ippsMontMul
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontMul,(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontMul,(const IppsBigNumState* pA, const IppsBigNumState* pB, IppsMontState* m, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontMul]
        jmp  rax
  }
};

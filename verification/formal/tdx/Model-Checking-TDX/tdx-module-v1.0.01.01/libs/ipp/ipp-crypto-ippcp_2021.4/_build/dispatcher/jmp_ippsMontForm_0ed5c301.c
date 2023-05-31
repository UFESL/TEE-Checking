#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus m7_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus n8_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus y8_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus e9_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus l9_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus n0_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus k0_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
extern IppStatus k1_ippsMontForm(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMontForm,
	(IPP_PROC)m7_ippsMontForm,
	(IPP_PROC)n8_ippsMontForm,
	(IPP_PROC)y8_ippsMontForm,
	(IPP_PROC)e9_ippsMontForm,
	(IPP_PROC)l9_ippsMontForm,
	(IPP_PROC)n0_ippsMontForm,
	(IPP_PROC)k0_ippsMontForm,
	(IPP_PROC)k1_ippsMontForm
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMontForm,(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMontForm,(const IppsBigNumState* pA, IppsMontState* pCtx, IppsBigNumState* pR))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMontForm]
        jmp  rax
  }
};

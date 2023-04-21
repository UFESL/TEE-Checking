#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPSet(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPSet,
	(IPP_PROC)m7_ippsDLPSet,
	(IPP_PROC)n8_ippsDLPSet,
	(IPP_PROC)y8_ippsDLPSet,
	(IPP_PROC)e9_ippsDLPSet,
	(IPP_PROC)l9_ippsDLPSet,
	(IPP_PROC)n0_ippsDLPSet,
	(IPP_PROC)k0_ippsDLPSet,
	(IPP_PROC)k1_ippsDLPSet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPSet,(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPSet,(const IppsBigNumState* pP, const IppsBigNumState* pR, const IppsBigNumState* pG, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPSet]
        jmp  rax
  }
};

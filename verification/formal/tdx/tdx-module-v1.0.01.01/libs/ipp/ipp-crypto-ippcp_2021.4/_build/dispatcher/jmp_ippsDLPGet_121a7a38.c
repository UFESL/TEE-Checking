#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPGet(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPGet,
	(IPP_PROC)m7_ippsDLPGet,
	(IPP_PROC)n8_ippsDLPGet,
	(IPP_PROC)y8_ippsDLPGet,
	(IPP_PROC)e9_ippsDLPGet,
	(IPP_PROC)l9_ippsDLPGet,
	(IPP_PROC)n0_ippsDLPGet,
	(IPP_PROC)k0_ippsDLPGet,
	(IPP_PROC)k1_ippsDLPGet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPGet,(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPGet,(IppsBigNumState* pP, IppsBigNumState* pR, IppsBigNumState* pG, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPGet]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPGetDP(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPGetDP,
	(IPP_PROC)m7_ippsDLPGetDP,
	(IPP_PROC)n8_ippsDLPGetDP,
	(IPP_PROC)y8_ippsDLPGetDP,
	(IPP_PROC)e9_ippsDLPGetDP,
	(IPP_PROC)l9_ippsDLPGetDP,
	(IPP_PROC)n0_ippsDLPGetDP,
	(IPP_PROC)k0_ippsDLPGetDP,
	(IPP_PROC)k1_ippsDLPGetDP
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPGetDP,(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPGetDP,(IppsBigNumState* pDP, IppDLPKeyTag tag, const IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPGetDP]
        jmp  rax
  }
};

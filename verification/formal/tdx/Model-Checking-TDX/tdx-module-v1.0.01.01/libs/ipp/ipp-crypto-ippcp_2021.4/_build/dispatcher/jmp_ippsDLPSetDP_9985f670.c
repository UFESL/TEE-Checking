#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus m7_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus n8_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus y8_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus e9_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus l9_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus n0_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus k0_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
extern IppStatus k1_ippsDLPSetDP(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPSetDP,
	(IPP_PROC)m7_ippsDLPSetDP,
	(IPP_PROC)n8_ippsDLPSetDP,
	(IPP_PROC)y8_ippsDLPSetDP,
	(IPP_PROC)e9_ippsDLPSetDP,
	(IPP_PROC)l9_ippsDLPSetDP,
	(IPP_PROC)n0_ippsDLPSetDP,
	(IPP_PROC)k0_ippsDLPSetDP,
	(IPP_PROC)k1_ippsDLPSetDP
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPSetDP,(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPSetDP,(const IppsBigNumState* pDP, IppDLPKeyTag tag, IppsDLPState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPSetDP]
        jmp  rax
  }
};

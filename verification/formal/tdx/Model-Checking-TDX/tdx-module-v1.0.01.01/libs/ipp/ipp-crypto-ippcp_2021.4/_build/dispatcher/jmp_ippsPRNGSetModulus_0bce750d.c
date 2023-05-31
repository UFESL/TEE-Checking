#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMod, IppsPRNGState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus m7_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus n8_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus y8_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus e9_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus l9_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus n0_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus k0_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
extern IppStatus k1_ippsPRNGSetModulus(const IppsBigNumState* pMod, IppsPRNGState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGSetModulus,
	(IPP_PROC)m7_ippsPRNGSetModulus,
	(IPP_PROC)n8_ippsPRNGSetModulus,
	(IPP_PROC)y8_ippsPRNGSetModulus,
	(IPP_PROC)e9_ippsPRNGSetModulus,
	(IPP_PROC)l9_ippsPRNGSetModulus,
	(IPP_PROC)n0_ippsPRNGSetModulus,
	(IPP_PROC)k0_ippsPRNGSetModulus,
	(IPP_PROC)k1_ippsPRNGSetModulus
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGSetModulus,(const IppsBigNumState* pMod, IppsPRNGState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGSetModulus,(const IppsBigNumState* pMod, IppsPRNGState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGSetModulus]
        jmp  rax
  }
};

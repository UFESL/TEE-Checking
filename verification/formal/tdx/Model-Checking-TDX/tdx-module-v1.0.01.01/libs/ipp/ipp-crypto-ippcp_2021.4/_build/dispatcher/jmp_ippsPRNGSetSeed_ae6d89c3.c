#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus m7_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus n8_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus y8_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus e9_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus l9_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus n0_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus k0_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
extern IppStatus k1_ippsPRNGSetSeed(const IppsBigNumState* pSeed,IppsPRNGState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGSetSeed,
	(IPP_PROC)m7_ippsPRNGSetSeed,
	(IPP_PROC)n8_ippsPRNGSetSeed,
	(IPP_PROC)y8_ippsPRNGSetSeed,
	(IPP_PROC)e9_ippsPRNGSetSeed,
	(IPP_PROC)l9_ippsPRNGSetSeed,
	(IPP_PROC)n0_ippsPRNGSetSeed,
	(IPP_PROC)k0_ippsPRNGSetSeed,
	(IPP_PROC)k1_ippsPRNGSetSeed
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGSetSeed,(const IppsBigNumState* pSeed,IppsPRNGState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGSetSeed,(const IppsBigNumState* pSeed,IppsPRNGState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGSetSeed]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus m7_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus n8_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus y8_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus e9_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus l9_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus n0_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus k0_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
extern IppStatus k1_ippsPRNGGetSeed(const IppsPRNGState* pCtx,IppsBigNumState* pSeed);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGGetSeed,
	(IPP_PROC)m7_ippsPRNGGetSeed,
	(IPP_PROC)n8_ippsPRNGGetSeed,
	(IPP_PROC)y8_ippsPRNGGetSeed,
	(IPP_PROC)e9_ippsPRNGGetSeed,
	(IPP_PROC)l9_ippsPRNGGetSeed,
	(IPP_PROC)n0_ippsPRNGGetSeed,
	(IPP_PROC)k0_ippsPRNGGetSeed,
	(IPP_PROC)k1_ippsPRNGGetSeed
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGGetSeed,(const IppsPRNGState* pCtx,IppsBigNumState* pSeed))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGGetSeed,(const IppsPRNGState* pCtx,IppsBigNumState* pSeed))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGGetSeed]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pAug, IppsPRNGState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus m7_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus n8_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus y8_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus e9_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus l9_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus n0_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus k0_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
extern IppStatus k1_ippsPRNGSetAugment(const IppsBigNumState* pAug, IppsPRNGState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGSetAugment,
	(IPP_PROC)m7_ippsPRNGSetAugment,
	(IPP_PROC)n8_ippsPRNGSetAugment,
	(IPP_PROC)y8_ippsPRNGSetAugment,
	(IPP_PROC)e9_ippsPRNGSetAugment,
	(IPP_PROC)l9_ippsPRNGSetAugment,
	(IPP_PROC)n0_ippsPRNGSetAugment,
	(IPP_PROC)k0_ippsPRNGSetAugment,
	(IPP_PROC)k1_ippsPRNGSetAugment
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGSetAugment,(const IppsBigNumState* pAug, IppsPRNGState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGSetAugment,(const IppsBigNumState* pAug, IppsPRNGState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGSetAugment]
        jmp  rax
  }
};

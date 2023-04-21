#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pH0, IppsPRNGState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus m7_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus n8_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus y8_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus e9_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus l9_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus n0_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus k0_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
extern IppStatus k1_ippsPRNGSetH0(const IppsBigNumState* pH0, IppsPRNGState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGSetH0,
	(IPP_PROC)m7_ippsPRNGSetH0,
	(IPP_PROC)n8_ippsPRNGSetH0,
	(IPP_PROC)y8_ippsPRNGSetH0,
	(IPP_PROC)e9_ippsPRNGSetH0,
	(IPP_PROC)l9_ippsPRNGSetH0,
	(IPP_PROC)n0_ippsPRNGSetH0,
	(IPP_PROC)k0_ippsPRNGSetH0,
	(IPP_PROC)k1_ippsPRNGSetH0
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGSetH0,(const IppsBigNumState* pH0, IppsPRNGState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGSetH0,(const IppsBigNumState* pH0, IppsPRNGState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGSetH0]
        jmp  rax
  }
};

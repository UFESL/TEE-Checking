#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int seedBits, IppsPRNGState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus m7_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus n8_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus y8_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus e9_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus l9_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus n0_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus k0_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
extern IppStatus k1_ippsPRNGInit(int seedBits, IppsPRNGState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGInit,
	(IPP_PROC)m7_ippsPRNGInit,
	(IPP_PROC)n8_ippsPRNGInit,
	(IPP_PROC)y8_ippsPRNGInit,
	(IPP_PROC)e9_ippsPRNGInit,
	(IPP_PROC)l9_ippsPRNGInit,
	(IPP_PROC)n0_ippsPRNGInit,
	(IPP_PROC)k0_ippsPRNGInit,
	(IPP_PROC)k1_ippsPRNGInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGInit,(int seedBits, IppsPRNGState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGInit,(int seedBits, IppsPRNGState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGInit]
        jmp  rax
  }
};

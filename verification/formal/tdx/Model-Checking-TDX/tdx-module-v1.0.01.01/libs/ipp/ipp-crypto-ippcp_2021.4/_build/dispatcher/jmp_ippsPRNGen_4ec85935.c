#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u* pRand, int nBits, void* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus m7_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n8_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus y8_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus e9_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus l9_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n0_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k0_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k1_ippsPRNGen(Ipp32u* pRand, int nBits, void* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGen,
	(IPP_PROC)m7_ippsPRNGen,
	(IPP_PROC)n8_ippsPRNGen,
	(IPP_PROC)y8_ippsPRNGen,
	(IPP_PROC)e9_ippsPRNGen,
	(IPP_PROC)l9_ippsPRNGen,
	(IPP_PROC)n0_ippsPRNGen,
	(IPP_PROC)k0_ippsPRNGen,
	(IPP_PROC)k1_ippsPRNGen
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGen,(Ipp32u* pRand, int nBits, void* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGen,(Ipp32u* pRand, int nBits, void* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGen]
        jmp  rax
  }
};

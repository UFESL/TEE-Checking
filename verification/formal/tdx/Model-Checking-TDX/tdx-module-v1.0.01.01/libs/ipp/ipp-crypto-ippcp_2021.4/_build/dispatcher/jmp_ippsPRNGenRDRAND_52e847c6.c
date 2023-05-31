#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u* pRand, int nBits, void* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus m7_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n8_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus y8_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus e9_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus l9_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus n0_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k0_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
extern IppStatus k1_ippsPRNGenRDRAND(Ipp32u* pRand, int nBits, void* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGenRDRAND,
	(IPP_PROC)m7_ippsPRNGenRDRAND,
	(IPP_PROC)n8_ippsPRNGenRDRAND,
	(IPP_PROC)y8_ippsPRNGenRDRAND,
	(IPP_PROC)e9_ippsPRNGenRDRAND,
	(IPP_PROC)l9_ippsPRNGenRDRAND,
	(IPP_PROC)n0_ippsPRNGenRDRAND,
	(IPP_PROC)k0_ippsPRNGenRDRAND,
	(IPP_PROC)k1_ippsPRNGenRDRAND
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGenRDRAND,(Ipp32u* pRand, int nBits, void* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGenRDRAND,(Ipp32u* pRand, int nBits, void* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGenRDRAND]
        jmp  rax
  }
};

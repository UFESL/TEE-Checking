#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pRand, int nBits, void* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus m7_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus n8_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus y8_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus e9_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus l9_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus n0_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus k0_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
extern IppStatus k1_ippsPRNGenRDRAND_BN(IppsBigNumState* pRand, int nBits, void* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGenRDRAND_BN,
	(IPP_PROC)m7_ippsPRNGenRDRAND_BN,
	(IPP_PROC)n8_ippsPRNGenRDRAND_BN,
	(IPP_PROC)y8_ippsPRNGenRDRAND_BN,
	(IPP_PROC)e9_ippsPRNGenRDRAND_BN,
	(IPP_PROC)l9_ippsPRNGenRDRAND_BN,
	(IPP_PROC)n0_ippsPRNGenRDRAND_BN,
	(IPP_PROC)k0_ippsPRNGenRDRAND_BN,
	(IPP_PROC)k1_ippsPRNGenRDRAND_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGenRDRAND_BN,(IppsBigNumState* pRand, int nBits, void* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGenRDRAND_BN,(IppsBigNumState* pRand, int nBits, void* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGenRDRAND_BN]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsDLPGenerateDSA(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPGenerateDSA,
	(IPP_PROC)m7_ippsDLPGenerateDSA,
	(IPP_PROC)n8_ippsDLPGenerateDSA,
	(IPP_PROC)y8_ippsDLPGenerateDSA,
	(IPP_PROC)e9_ippsDLPGenerateDSA,
	(IPP_PROC)l9_ippsDLPGenerateDSA,
	(IPP_PROC)n0_ippsDLPGenerateDSA,
	(IPP_PROC)k0_ippsDLPGenerateDSA,
	(IPP_PROC)k1_ippsDLPGenerateDSA
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPGenerateDSA,(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPGenerateDSA,(const IppsBigNumState* pSeedIn, int nTrials, IppsDLPState* pCtx, IppsBigNumState* pSeedOut, int* pCounter, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPGenerateDSA]
        jmp  rax
  }
};

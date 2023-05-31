#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsPrimeTest_BN(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeTest_BN,
	(IPP_PROC)m7_ippsPrimeTest_BN,
	(IPP_PROC)n8_ippsPrimeTest_BN,
	(IPP_PROC)y8_ippsPrimeTest_BN,
	(IPP_PROC)e9_ippsPrimeTest_BN,
	(IPP_PROC)l9_ippsPrimeTest_BN,
	(IPP_PROC)n0_ippsPrimeTest_BN,
	(IPP_PROC)k0_ippsPrimeTest_BN,
	(IPP_PROC)k1_ippsPrimeTest_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeTest_BN,(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeTest_BN,(const IppsBigNumState* pPrime, int nTrials, Ipp32u* pResult, IppsPrimeState* pCtx, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeTest_BN]
        jmp  rax
  }
};

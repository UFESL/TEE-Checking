#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus m7_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus n8_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus y8_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus e9_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus l9_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus n0_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus k0_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
extern IppStatus k1_ippsPrimeSet_BN(const IppsBigNumState* pPrime, IppsPrimeState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeSet_BN,
	(IPP_PROC)m7_ippsPrimeSet_BN,
	(IPP_PROC)n8_ippsPrimeSet_BN,
	(IPP_PROC)y8_ippsPrimeSet_BN,
	(IPP_PROC)e9_ippsPrimeSet_BN,
	(IPP_PROC)l9_ippsPrimeSet_BN,
	(IPP_PROC)n0_ippsPrimeSet_BN,
	(IPP_PROC)k0_ippsPrimeSet_BN,
	(IPP_PROC)k1_ippsPrimeSet_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeSet_BN,(const IppsBigNumState* pPrime, IppsPrimeState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeSet_BN,(const IppsBigNumState* pPrime, IppsPrimeState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeSet_BN]
        jmp  rax
  }
};

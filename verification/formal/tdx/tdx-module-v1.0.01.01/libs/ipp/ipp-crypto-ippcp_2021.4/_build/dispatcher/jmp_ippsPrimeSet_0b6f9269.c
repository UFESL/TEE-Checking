#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus m7_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus n8_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus y8_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus e9_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus l9_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus n0_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus k0_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
extern IppStatus k1_ippsPrimeSet(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeSet,
	(IPP_PROC)m7_ippsPrimeSet,
	(IPP_PROC)n8_ippsPrimeSet,
	(IPP_PROC)y8_ippsPrimeSet,
	(IPP_PROC)e9_ippsPrimeSet,
	(IPP_PROC)l9_ippsPrimeSet,
	(IPP_PROC)n0_ippsPrimeSet,
	(IPP_PROC)k0_ippsPrimeSet,
	(IPP_PROC)k1_ippsPrimeSet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeSet,(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeSet,(const Ipp32u* pPrime, int nBits, IppsPrimeState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeSet]
        jmp  rax
  }
};

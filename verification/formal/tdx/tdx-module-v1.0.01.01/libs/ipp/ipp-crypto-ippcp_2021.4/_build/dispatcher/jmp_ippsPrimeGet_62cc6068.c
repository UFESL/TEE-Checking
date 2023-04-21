#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus m7_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus n8_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus y8_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus e9_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus l9_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus n0_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus k0_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
extern IppStatus k1_ippsPrimeGet(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeGet,
	(IPP_PROC)m7_ippsPrimeGet,
	(IPP_PROC)n8_ippsPrimeGet,
	(IPP_PROC)y8_ippsPrimeGet,
	(IPP_PROC)e9_ippsPrimeGet,
	(IPP_PROC)l9_ippsPrimeGet,
	(IPP_PROC)n0_ippsPrimeGet,
	(IPP_PROC)k0_ippsPrimeGet,
	(IPP_PROC)k1_ippsPrimeGet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeGet,(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeGet,(Ipp32u* pPrime, int* pLen, const IppsPrimeState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeGet]
        jmp  rax
  }
};

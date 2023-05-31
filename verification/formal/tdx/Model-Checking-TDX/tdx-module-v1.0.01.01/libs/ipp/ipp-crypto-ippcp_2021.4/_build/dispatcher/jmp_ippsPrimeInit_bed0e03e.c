#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int nMaxBits, IppsPrimeState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus m7_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus n8_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus y8_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus e9_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus l9_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus n0_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus k0_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
extern IppStatus k1_ippsPrimeInit(int nMaxBits, IppsPrimeState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeInit,
	(IPP_PROC)m7_ippsPrimeInit,
	(IPP_PROC)n8_ippsPrimeInit,
	(IPP_PROC)y8_ippsPrimeInit,
	(IPP_PROC)e9_ippsPrimeInit,
	(IPP_PROC)l9_ippsPrimeInit,
	(IPP_PROC)n0_ippsPrimeInit,
	(IPP_PROC)k0_ippsPrimeInit,
	(IPP_PROC)k1_ippsPrimeInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeInit,(int nMaxBits, IppsPrimeState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeInit,(int nMaxBits, IppsPrimeState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeInit]
        jmp  rax
  }
};

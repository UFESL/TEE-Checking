#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int nMaxBits, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus m7_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus n8_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus y8_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus e9_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus l9_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus n0_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus k0_ippsPrimeGetSize(int nMaxBits, int* pSize);
extern IppStatus k1_ippsPrimeGetSize(int nMaxBits, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPrimeGetSize,
	(IPP_PROC)m7_ippsPrimeGetSize,
	(IPP_PROC)n8_ippsPrimeGetSize,
	(IPP_PROC)y8_ippsPrimeGetSize,
	(IPP_PROC)e9_ippsPrimeGetSize,
	(IPP_PROC)l9_ippsPrimeGetSize,
	(IPP_PROC)n0_ippsPrimeGetSize,
	(IPP_PROC)k0_ippsPrimeGetSize,
	(IPP_PROC)k1_ippsPrimeGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPrimeGetSize,(int nMaxBits, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPrimeGetSize,(int nMaxBits, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPrimeGetSize]
        jmp  rax
  }
};

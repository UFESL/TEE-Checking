#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsPRNGGetSize(int* pSize);
extern IppStatus m7_ippsPRNGGetSize(int* pSize);
extern IppStatus n8_ippsPRNGGetSize(int* pSize);
extern IppStatus y8_ippsPRNGGetSize(int* pSize);
extern IppStatus e9_ippsPRNGGetSize(int* pSize);
extern IppStatus l9_ippsPRNGGetSize(int* pSize);
extern IppStatus n0_ippsPRNGGetSize(int* pSize);
extern IppStatus k0_ippsPRNGGetSize(int* pSize);
extern IppStatus k1_ippsPRNGGetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsPRNGGetSize,
	(IPP_PROC)m7_ippsPRNGGetSize,
	(IPP_PROC)n8_ippsPRNGGetSize,
	(IPP_PROC)y8_ippsPRNGGetSize,
	(IPP_PROC)e9_ippsPRNGGetSize,
	(IPP_PROC)l9_ippsPRNGGetSize,
	(IPP_PROC)n0_ippsPRNGGetSize,
	(IPP_PROC)k0_ippsPRNGGetSize,
	(IPP_PROC)k1_ippsPRNGGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsPRNGGetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsPRNGGetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsPRNGGetSize]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int bitSizeP, int bitSizeR, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus m7_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus n8_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus y8_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus e9_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus l9_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus n0_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus k0_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
extern IppStatus k1_ippsDLPGetSize(int bitSizeP, int bitSizeR, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDLPGetSize,
	(IPP_PROC)m7_ippsDLPGetSize,
	(IPP_PROC)n8_ippsDLPGetSize,
	(IPP_PROC)y8_ippsDLPGetSize,
	(IPP_PROC)e9_ippsDLPGetSize,
	(IPP_PROC)l9_ippsDLPGetSize,
	(IPP_PROC)n0_ippsDLPGetSize,
	(IPP_PROC)k0_ippsDLPGetSize,
	(IPP_PROC)k1_ippsDLPGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDLPGetSize,(int bitSizeP, int bitSizeR, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDLPGetSize,(int bitSizeP, int bitSizeR, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDLPGetSize]
        jmp  rax
  }
};

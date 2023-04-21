#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA1GetSize(int* pSize);
extern IppStatus m7_ippsSHA1GetSize(int* pSize);
extern IppStatus n8_ippsSHA1GetSize(int* pSize);
extern IppStatus y8_ippsSHA1GetSize(int* pSize);
extern IppStatus e9_ippsSHA1GetSize(int* pSize);
extern IppStatus l9_ippsSHA1GetSize(int* pSize);
extern IppStatus n0_ippsSHA1GetSize(int* pSize);
extern IppStatus k0_ippsSHA1GetSize(int* pSize);
extern IppStatus k1_ippsSHA1GetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA1GetSize,
	(IPP_PROC)m7_ippsSHA1GetSize,
	(IPP_PROC)n8_ippsSHA1GetSize,
	(IPP_PROC)y8_ippsSHA1GetSize,
	(IPP_PROC)e9_ippsSHA1GetSize,
	(IPP_PROC)l9_ippsSHA1GetSize,
	(IPP_PROC)n0_ippsSHA1GetSize,
	(IPP_PROC)k0_ippsSHA1GetSize,
	(IPP_PROC)k1_ippsSHA1GetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA1GetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA1GetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA1GetSize]
        jmp  rax
  }
};

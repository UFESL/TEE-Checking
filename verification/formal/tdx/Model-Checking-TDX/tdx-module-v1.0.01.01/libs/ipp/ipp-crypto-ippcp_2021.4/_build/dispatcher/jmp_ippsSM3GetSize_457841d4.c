#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSM3GetSize(int* pSize);
extern IppStatus m7_ippsSM3GetSize(int* pSize);
extern IppStatus n8_ippsSM3GetSize(int* pSize);
extern IppStatus y8_ippsSM3GetSize(int* pSize);
extern IppStatus e9_ippsSM3GetSize(int* pSize);
extern IppStatus l9_ippsSM3GetSize(int* pSize);
extern IppStatus n0_ippsSM3GetSize(int* pSize);
extern IppStatus k0_ippsSM3GetSize(int* pSize);
extern IppStatus k1_ippsSM3GetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSM3GetSize,
	(IPP_PROC)m7_ippsSM3GetSize,
	(IPP_PROC)n8_ippsSM3GetSize,
	(IPP_PROC)y8_ippsSM3GetSize,
	(IPP_PROC)e9_ippsSM3GetSize,
	(IPP_PROC)l9_ippsSM3GetSize,
	(IPP_PROC)n0_ippsSM3GetSize,
	(IPP_PROC)k0_ippsSM3GetSize,
	(IPP_PROC)k1_ippsSM3GetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSM3GetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSM3GetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSM3GetSize]
        jmp  rax
  }
};

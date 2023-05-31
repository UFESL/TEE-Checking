#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int *pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSMS4GetSize(int *pSize);
extern IppStatus m7_ippsSMS4GetSize(int *pSize);
extern IppStatus n8_ippsSMS4GetSize(int *pSize);
extern IppStatus y8_ippsSMS4GetSize(int *pSize);
extern IppStatus e9_ippsSMS4GetSize(int *pSize);
extern IppStatus l9_ippsSMS4GetSize(int *pSize);
extern IppStatus n0_ippsSMS4GetSize(int *pSize);
extern IppStatus k0_ippsSMS4GetSize(int *pSize);
extern IppStatus k1_ippsSMS4GetSize(int *pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSMS4GetSize,
	(IPP_PROC)m7_ippsSMS4GetSize,
	(IPP_PROC)n8_ippsSMS4GetSize,
	(IPP_PROC)y8_ippsSMS4GetSize,
	(IPP_PROC)e9_ippsSMS4GetSize,
	(IPP_PROC)l9_ippsSMS4GetSize,
	(IPP_PROC)n0_ippsSMS4GetSize,
	(IPP_PROC)k0_ippsSMS4GetSize,
	(IPP_PROC)k1_ippsSMS4GetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSMS4GetSize,(int *pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSMS4GetSize,(int *pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSMS4GetSize]
        jmp  rax
  }
};

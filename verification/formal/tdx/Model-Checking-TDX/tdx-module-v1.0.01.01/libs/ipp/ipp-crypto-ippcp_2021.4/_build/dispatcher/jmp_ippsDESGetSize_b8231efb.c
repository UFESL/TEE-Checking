#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int *size);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsDESGetSize(int *size);
extern IppStatus m7_ippsDESGetSize(int *size);
extern IppStatus n8_ippsDESGetSize(int *size);
extern IppStatus y8_ippsDESGetSize(int *size);
extern IppStatus e9_ippsDESGetSize(int *size);
extern IppStatus l9_ippsDESGetSize(int *size);
extern IppStatus n0_ippsDESGetSize(int *size);
extern IppStatus k0_ippsDESGetSize(int *size);
extern IppStatus k1_ippsDESGetSize(int *size);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsDESGetSize,
	(IPP_PROC)m7_ippsDESGetSize,
	(IPP_PROC)n8_ippsDESGetSize,
	(IPP_PROC)y8_ippsDESGetSize,
	(IPP_PROC)e9_ippsDESGetSize,
	(IPP_PROC)l9_ippsDESGetSize,
	(IPP_PROC)n0_ippsDESGetSize,
	(IPP_PROC)k0_ippsDESGetSize,
	(IPP_PROC)k1_ippsDESGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsDESGetSize,(int *size))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsDESGetSize,(int *size))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsDESGetSize]
        jmp  rax
  }
};

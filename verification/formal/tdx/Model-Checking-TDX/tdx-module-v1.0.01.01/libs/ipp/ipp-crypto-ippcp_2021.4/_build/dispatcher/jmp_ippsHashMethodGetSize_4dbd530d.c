#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  IppStatus in_ippsHashMethodGetSize(int* pSize);
extern  IppStatus m7_ippsHashMethodGetSize(int* pSize);
extern  IppStatus n8_ippsHashMethodGetSize(int* pSize);
extern  IppStatus y8_ippsHashMethodGetSize(int* pSize);
extern  IppStatus e9_ippsHashMethodGetSize(int* pSize);
extern  IppStatus l9_ippsHashMethodGetSize(int* pSize);
extern  IppStatus n0_ippsHashMethodGetSize(int* pSize);
extern  IppStatus k0_ippsHashMethodGetSize(int* pSize);
extern  IppStatus k1_ippsHashMethodGetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMethodGetSize,
	(IPP_PROC)m7_ippsHashMethodGetSize,
	(IPP_PROC)n8_ippsHashMethodGetSize,
	(IPP_PROC)y8_ippsHashMethodGetSize,
	(IPP_PROC)e9_ippsHashMethodGetSize,
	(IPP_PROC)l9_ippsHashMethodGetSize,
	(IPP_PROC)n0_ippsHashMethodGetSize,
	(IPP_PROC)k0_ippsHashMethodGetSize,
	(IPP_PROC)k1_ippsHashMethodGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( IppStatus, ippsHashMethodGetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( IppStatus, in_ippsHashMethodGetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMethodGetSize]
        jmp  rax
  }
};

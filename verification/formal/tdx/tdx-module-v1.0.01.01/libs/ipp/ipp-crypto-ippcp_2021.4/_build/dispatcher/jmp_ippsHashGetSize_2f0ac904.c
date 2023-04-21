#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashGetSize(int* pSize);
extern IppStatus m7_ippsHashGetSize(int* pSize);
extern IppStatus n8_ippsHashGetSize(int* pSize);
extern IppStatus y8_ippsHashGetSize(int* pSize);
extern IppStatus e9_ippsHashGetSize(int* pSize);
extern IppStatus l9_ippsHashGetSize(int* pSize);
extern IppStatus n0_ippsHashGetSize(int* pSize);
extern IppStatus k0_ippsHashGetSize(int* pSize);
extern IppStatus k1_ippsHashGetSize(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashGetSize,
	(IPP_PROC)m7_ippsHashGetSize,
	(IPP_PROC)n8_ippsHashGetSize,
	(IPP_PROC)y8_ippsHashGetSize,
	(IPP_PROC)e9_ippsHashGetSize,
	(IPP_PROC)l9_ippsHashGetSize,
	(IPP_PROC)n0_ippsHashGetSize,
	(IPP_PROC)k0_ippsHashGetSize,
	(IPP_PROC)k1_ippsHashGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashGetSize,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashGetSize,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashGetSize]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int feBitSize, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus m7_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus n8_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus y8_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus e9_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus l9_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus n0_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus k0_ippsGFpGetSize(int feBitSize, int* pSize);
extern IppStatus k1_ippsGFpGetSize(int feBitSize, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpGetSize,
	(IPP_PROC)m7_ippsGFpGetSize,
	(IPP_PROC)n8_ippsGFpGetSize,
	(IPP_PROC)y8_ippsGFpGetSize,
	(IPP_PROC)e9_ippsGFpGetSize,
	(IPP_PROC)l9_ippsGFpGetSize,
	(IPP_PROC)n0_ippsGFpGetSize,
	(IPP_PROC)k0_ippsGFpGetSize,
	(IPP_PROC)k1_ippsGFpGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpGetSize,(int feBitSize, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpGetSize,(int feBitSize, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpGetSize]
        jmp  rax
  }
};

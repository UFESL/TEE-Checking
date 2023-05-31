#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int feBitSize, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus m7_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus n8_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus y8_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus e9_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus l9_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus n0_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus k0_ippsECCPGetSize(int feBitSize, int* pSize);
extern IppStatus k1_ippsECCPGetSize(int feBitSize, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetSize,
	(IPP_PROC)m7_ippsECCPGetSize,
	(IPP_PROC)n8_ippsECCPGetSize,
	(IPP_PROC)y8_ippsECCPGetSize,
	(IPP_PROC)e9_ippsECCPGetSize,
	(IPP_PROC)l9_ippsECCPGetSize,
	(IPP_PROC)n0_ippsECCPGetSize,
	(IPP_PROC)k0_ippsECCPGetSize,
	(IPP_PROC)k1_ippsECCPGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetSize,(int feBitSize, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetSize,(int feBitSize, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetSize]
        jmp  rax
  }
};

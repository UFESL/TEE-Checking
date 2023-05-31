#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int feBitSize, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus m7_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus n8_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus y8_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus e9_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus l9_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus n0_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus k0_ippsECCPPointGetSize(int feBitSize, int* pSize);
extern IppStatus k1_ippsECCPPointGetSize(int feBitSize, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPPointGetSize,
	(IPP_PROC)m7_ippsECCPPointGetSize,
	(IPP_PROC)n8_ippsECCPPointGetSize,
	(IPP_PROC)y8_ippsECCPPointGetSize,
	(IPP_PROC)e9_ippsECCPPointGetSize,
	(IPP_PROC)l9_ippsECCPPointGetSize,
	(IPP_PROC)n0_ippsECCPPointGetSize,
	(IPP_PROC)k0_ippsECCPPointGetSize,
	(IPP_PROC)k1_ippsECCPPointGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPPointGetSize,(int feBitSize, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPPointGetSize,(int feBitSize, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPPointGetSize]
        jmp  rax
  }
};

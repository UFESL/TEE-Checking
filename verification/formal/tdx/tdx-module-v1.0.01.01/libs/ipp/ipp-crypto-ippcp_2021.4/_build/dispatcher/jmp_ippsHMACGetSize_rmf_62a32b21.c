#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus m7_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus n8_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus y8_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus e9_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus l9_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus n0_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus k0_ippsHMACGetSize_rmf(int* pSize);
extern IppStatus k1_ippsHMACGetSize_rmf(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMACGetSize_rmf,
	(IPP_PROC)m7_ippsHMACGetSize_rmf,
	(IPP_PROC)n8_ippsHMACGetSize_rmf,
	(IPP_PROC)y8_ippsHMACGetSize_rmf,
	(IPP_PROC)e9_ippsHMACGetSize_rmf,
	(IPP_PROC)l9_ippsHMACGetSize_rmf,
	(IPP_PROC)n0_ippsHMACGetSize_rmf,
	(IPP_PROC)k0_ippsHMACGetSize_rmf,
	(IPP_PROC)k1_ippsHMACGetSize_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMACGetSize_rmf,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMACGetSize_rmf,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMACGetSize_rmf]
        jmp  rax
  }
};

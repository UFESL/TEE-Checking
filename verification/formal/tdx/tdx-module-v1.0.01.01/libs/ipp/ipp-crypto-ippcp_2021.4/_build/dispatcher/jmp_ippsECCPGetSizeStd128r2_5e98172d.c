#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus m7_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus n8_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus y8_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus e9_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus l9_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus n0_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus k0_ippsECCPGetSizeStd128r2(int* pSize);
extern IppStatus k1_ippsECCPGetSizeStd128r2(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetSizeStd128r2,
	(IPP_PROC)m7_ippsECCPGetSizeStd128r2,
	(IPP_PROC)n8_ippsECCPGetSizeStd128r2,
	(IPP_PROC)y8_ippsECCPGetSizeStd128r2,
	(IPP_PROC)e9_ippsECCPGetSizeStd128r2,
	(IPP_PROC)l9_ippsECCPGetSizeStd128r2,
	(IPP_PROC)n0_ippsECCPGetSizeStd128r2,
	(IPP_PROC)k0_ippsECCPGetSizeStd128r2,
	(IPP_PROC)k1_ippsECCPGetSizeStd128r2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetSizeStd128r2,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetSizeStd128r2,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetSizeStd128r2]
        jmp  rax
  }
};

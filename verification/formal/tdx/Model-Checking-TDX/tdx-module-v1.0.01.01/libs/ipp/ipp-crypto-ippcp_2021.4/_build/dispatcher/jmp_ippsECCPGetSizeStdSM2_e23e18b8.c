#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus m7_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus n8_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus y8_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus e9_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus l9_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus n0_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus k0_ippsECCPGetSizeStdSM2(int* pSize);
extern IppStatus k1_ippsECCPGetSizeStdSM2(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetSizeStdSM2,
	(IPP_PROC)m7_ippsECCPGetSizeStdSM2,
	(IPP_PROC)n8_ippsECCPGetSizeStdSM2,
	(IPP_PROC)y8_ippsECCPGetSizeStdSM2,
	(IPP_PROC)e9_ippsECCPGetSizeStdSM2,
	(IPP_PROC)l9_ippsECCPGetSizeStdSM2,
	(IPP_PROC)n0_ippsECCPGetSizeStdSM2,
	(IPP_PROC)k0_ippsECCPGetSizeStdSM2,
	(IPP_PROC)k1_ippsECCPGetSizeStdSM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetSizeStdSM2,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetSizeStdSM2,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetSizeStdSM2]
        jmp  rax
  }
};

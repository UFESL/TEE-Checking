#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus m7_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus n8_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus y8_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus e9_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus l9_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus n0_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus k0_ippsECCPGetSizeStd192r1(int* pSize);
extern IppStatus k1_ippsECCPGetSizeStd192r1(int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetSizeStd192r1,
	(IPP_PROC)m7_ippsECCPGetSizeStd192r1,
	(IPP_PROC)n8_ippsECCPGetSizeStd192r1,
	(IPP_PROC)y8_ippsECCPGetSizeStd192r1,
	(IPP_PROC)e9_ippsECCPGetSizeStd192r1,
	(IPP_PROC)l9_ippsECCPGetSizeStd192r1,
	(IPP_PROC)n0_ippsECCPGetSizeStd192r1,
	(IPP_PROC)k0_ippsECCPGetSizeStd192r1,
	(IPP_PROC)k1_ippsECCPGetSizeStd192r1
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetSizeStd192r1,(int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetSizeStd192r1,(int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetSizeStd192r1]
        jmp  rax
  }
};

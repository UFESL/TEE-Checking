#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsSM3State* pSrcState, IppsSM3State* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus m7_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus n8_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus y8_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus e9_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus l9_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus n0_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus k0_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
extern IppStatus k1_ippsSM3Duplicate(const IppsSM3State* pSrcState, IppsSM3State* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSM3Duplicate,
	(IPP_PROC)m7_ippsSM3Duplicate,
	(IPP_PROC)n8_ippsSM3Duplicate,
	(IPP_PROC)y8_ippsSM3Duplicate,
	(IPP_PROC)e9_ippsSM3Duplicate,
	(IPP_PROC)l9_ippsSM3Duplicate,
	(IPP_PROC)n0_ippsSM3Duplicate,
	(IPP_PROC)k0_ippsSM3Duplicate,
	(IPP_PROC)k1_ippsSM3Duplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSM3Duplicate,(const IppsSM3State* pSrcState, IppsSM3State* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSM3Duplicate,(const IppsSM3State* pSrcState, IppsSM3State* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSM3Duplicate]
        jmp  rax
  }
};

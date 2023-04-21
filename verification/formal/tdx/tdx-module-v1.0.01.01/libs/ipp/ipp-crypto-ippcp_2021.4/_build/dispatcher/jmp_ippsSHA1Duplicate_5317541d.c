#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus m7_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus n8_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus y8_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus e9_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus l9_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus n0_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus k0_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
extern IppStatus k1_ippsSHA1Duplicate(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA1Duplicate,
	(IPP_PROC)m7_ippsSHA1Duplicate,
	(IPP_PROC)n8_ippsSHA1Duplicate,
	(IPP_PROC)y8_ippsSHA1Duplicate,
	(IPP_PROC)e9_ippsSHA1Duplicate,
	(IPP_PROC)l9_ippsSHA1Duplicate,
	(IPP_PROC)n0_ippsSHA1Duplicate,
	(IPP_PROC)k0_ippsSHA1Duplicate,
	(IPP_PROC)k1_ippsSHA1Duplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA1Duplicate,(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA1Duplicate,(const IppsSHA1State* pSrcState, IppsSHA1State* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA1Duplicate]
        jmp  rax
  }
};

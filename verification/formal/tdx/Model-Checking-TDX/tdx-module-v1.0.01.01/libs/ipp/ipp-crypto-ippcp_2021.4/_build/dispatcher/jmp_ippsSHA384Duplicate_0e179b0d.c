#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus m7_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus n8_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus y8_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus e9_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus l9_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus n0_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus k0_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
extern IppStatus k1_ippsSHA384Duplicate(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA384Duplicate,
	(IPP_PROC)m7_ippsSHA384Duplicate,
	(IPP_PROC)n8_ippsSHA384Duplicate,
	(IPP_PROC)y8_ippsSHA384Duplicate,
	(IPP_PROC)e9_ippsSHA384Duplicate,
	(IPP_PROC)l9_ippsSHA384Duplicate,
	(IPP_PROC)n0_ippsSHA384Duplicate,
	(IPP_PROC)k0_ippsSHA384Duplicate,
	(IPP_PROC)k1_ippsSHA384Duplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA384Duplicate,(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA384Duplicate,(const IppsSHA384State* pSrcState, IppsSHA384State* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA384Duplicate]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus m7_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus n8_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus y8_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus e9_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus l9_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus n0_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus k0_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
extern IppStatus k1_ippsSM3GetTag(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSM3GetTag,
	(IPP_PROC)m7_ippsSM3GetTag,
	(IPP_PROC)n8_ippsSM3GetTag,
	(IPP_PROC)y8_ippsSM3GetTag,
	(IPP_PROC)e9_ippsSM3GetTag,
	(IPP_PROC)l9_ippsSM3GetTag,
	(IPP_PROC)n0_ippsSM3GetTag,
	(IPP_PROC)k0_ippsSM3GetTag,
	(IPP_PROC)k1_ippsSM3GetTag
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSM3GetTag,(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSM3GetTag,(Ipp8u* pTag, Ipp32u tagLen, const IppsSM3State* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSM3GetTag]
        jmp  rax
  }
};

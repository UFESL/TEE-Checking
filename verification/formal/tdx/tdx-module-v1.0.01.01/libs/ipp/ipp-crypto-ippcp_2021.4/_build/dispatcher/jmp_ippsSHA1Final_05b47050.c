#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pMD, IppsSHA1State* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus m7_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus n8_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus y8_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus e9_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus l9_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus n0_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus k0_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
extern IppStatus k1_ippsSHA1Final(Ipp8u* pMD, IppsSHA1State* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA1Final,
	(IPP_PROC)m7_ippsSHA1Final,
	(IPP_PROC)n8_ippsSHA1Final,
	(IPP_PROC)y8_ippsSHA1Final,
	(IPP_PROC)e9_ippsSHA1Final,
	(IPP_PROC)l9_ippsSHA1Final,
	(IPP_PROC)n0_ippsSHA1Final,
	(IPP_PROC)k0_ippsSHA1Final,
	(IPP_PROC)k1_ippsSHA1Final
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA1Final,(Ipp8u* pMD, IppsSHA1State* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA1Final,(Ipp8u* pMD, IppsSHA1State* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA1Final]
        jmp  rax
  }
};

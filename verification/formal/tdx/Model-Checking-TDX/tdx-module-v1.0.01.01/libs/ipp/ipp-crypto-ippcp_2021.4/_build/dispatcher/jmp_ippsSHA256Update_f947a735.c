#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, int len, IppsSHA256State* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus m7_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus n8_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus y8_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus e9_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus l9_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus n0_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus k0_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
extern IppStatus k1_ippsSHA256Update(const Ipp8u* pSrc, int len, IppsSHA256State* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA256Update,
	(IPP_PROC)m7_ippsSHA256Update,
	(IPP_PROC)n8_ippsSHA256Update,
	(IPP_PROC)y8_ippsSHA256Update,
	(IPP_PROC)e9_ippsSHA256Update,
	(IPP_PROC)l9_ippsSHA256Update,
	(IPP_PROC)n0_ippsSHA256Update,
	(IPP_PROC)k0_ippsSHA256Update,
	(IPP_PROC)k1_ippsSHA256Update
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA256Update,(const Ipp8u* pSrc, int len, IppsSHA256State* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA256Update,(const Ipp8u* pSrc, int len, IppsSHA256State* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA256Update]
        jmp  rax
  }
};

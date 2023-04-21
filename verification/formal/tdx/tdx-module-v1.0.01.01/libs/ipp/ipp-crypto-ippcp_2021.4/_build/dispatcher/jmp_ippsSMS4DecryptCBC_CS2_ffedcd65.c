#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus m7_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus n8_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus y8_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus e9_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus l9_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus n0_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus k0_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
extern IppStatus k1_ippsSMS4DecryptCBC_CS2(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)m7_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)n8_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)y8_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)e9_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)l9_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)n0_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)k0_ippsSMS4DecryptCBC_CS2,
	(IPP_PROC)k1_ippsSMS4DecryptCBC_CS2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSMS4DecryptCBC_CS2,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSMS4DecryptCBC_CS2,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, const Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSMS4DecryptCBC_CS2]
        jmp  rax
  }
};

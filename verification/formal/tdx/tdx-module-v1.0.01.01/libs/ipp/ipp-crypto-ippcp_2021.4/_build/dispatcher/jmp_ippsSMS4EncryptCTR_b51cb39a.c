#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus m7_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n8_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus y8_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus e9_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus l9_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n0_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k0_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k1_ippsSMS4EncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSMS4EncryptCTR,
	(IPP_PROC)m7_ippsSMS4EncryptCTR,
	(IPP_PROC)n8_ippsSMS4EncryptCTR,
	(IPP_PROC)y8_ippsSMS4EncryptCTR,
	(IPP_PROC)e9_ippsSMS4EncryptCTR,
	(IPP_PROC)l9_ippsSMS4EncryptCTR,
	(IPP_PROC)n0_ippsSMS4EncryptCTR,
	(IPP_PROC)k0_ippsSMS4EncryptCTR,
	(IPP_PROC)k1_ippsSMS4EncryptCTR
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSMS4EncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSMS4EncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsSMS4Spec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSMS4EncryptCTR]
        jmp  rax
  }
};

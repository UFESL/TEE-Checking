#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus m7_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n8_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus y8_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus e9_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus l9_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n0_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k0_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k1_ippsTDESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESEncryptCTR,
	(IPP_PROC)m7_ippsTDESEncryptCTR,
	(IPP_PROC)n8_ippsTDESEncryptCTR,
	(IPP_PROC)y8_ippsTDESEncryptCTR,
	(IPP_PROC)e9_ippsTDESEncryptCTR,
	(IPP_PROC)l9_ippsTDESEncryptCTR,
	(IPP_PROC)n0_ippsTDESEncryptCTR,
	(IPP_PROC)k0_ippsTDESEncryptCTR,
	(IPP_PROC)k1_ippsTDESEncryptCTR
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESEncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESEncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pCtrValue, int ctrNumBitSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESEncryptCTR]
        jmp  rax
  }
};

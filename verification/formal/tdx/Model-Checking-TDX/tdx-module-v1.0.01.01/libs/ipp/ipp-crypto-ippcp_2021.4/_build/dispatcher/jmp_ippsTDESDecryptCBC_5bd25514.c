#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus m7_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n8_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus y8_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus e9_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus l9_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n0_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k0_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k1_ippsTDESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESDecryptCBC,
	(IPP_PROC)m7_ippsTDESDecryptCBC,
	(IPP_PROC)n8_ippsTDESDecryptCBC,
	(IPP_PROC)y8_ippsTDESDecryptCBC,
	(IPP_PROC)e9_ippsTDESDecryptCBC,
	(IPP_PROC)l9_ippsTDESDecryptCBC,
	(IPP_PROC)n0_ippsTDESDecryptCBC,
	(IPP_PROC)k0_ippsTDESDecryptCBC,
	(IPP_PROC)k1_ippsTDESDecryptCBC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESDecryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESDecryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESDecryptCBC]
        jmp  rax
  }
};

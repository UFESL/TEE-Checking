#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus m7_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n8_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus y8_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus e9_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus l9_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n0_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k0_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k1_ippsTDESEncryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESEncryptCBC,
	(IPP_PROC)m7_ippsTDESEncryptCBC,
	(IPP_PROC)n8_ippsTDESEncryptCBC,
	(IPP_PROC)y8_ippsTDESEncryptCBC,
	(IPP_PROC)e9_ippsTDESEncryptCBC,
	(IPP_PROC)l9_ippsTDESEncryptCBC,
	(IPP_PROC)n0_ippsTDESEncryptCBC,
	(IPP_PROC)k0_ippsTDESEncryptCBC,
	(IPP_PROC)k1_ippsTDESEncryptCBC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESEncryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESEncryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESEncryptCBC]
        jmp  rax
  }
};

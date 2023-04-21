#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus m7_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n8_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus y8_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus e9_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus l9_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus n0_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k0_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
extern IppStatus k1_ippsTDESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESEncryptCFB,
	(IPP_PROC)m7_ippsTDESEncryptCFB,
	(IPP_PROC)n8_ippsTDESEncryptCFB,
	(IPP_PROC)y8_ippsTDESEncryptCFB,
	(IPP_PROC)e9_ippsTDESEncryptCFB,
	(IPP_PROC)l9_ippsTDESEncryptCFB,
	(IPP_PROC)n0_ippsTDESEncryptCFB,
	(IPP_PROC)k0_ippsTDESEncryptCFB,
	(IPP_PROC)k1_ippsTDESEncryptCFB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESEncryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESEncryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, const Ipp8u* pIV, IppsCPPadding padding))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESEncryptCFB]
        jmp  rax
  }
};

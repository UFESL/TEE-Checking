#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus m7_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus n8_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus y8_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus e9_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus l9_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus n0_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus k0_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
extern IppStatus k1_ippsTDESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESEncryptOFB,
	(IPP_PROC)m7_ippsTDESEncryptOFB,
	(IPP_PROC)n8_ippsTDESEncryptOFB,
	(IPP_PROC)y8_ippsTDESEncryptOFB,
	(IPP_PROC)e9_ippsTDESEncryptOFB,
	(IPP_PROC)l9_ippsTDESEncryptOFB,
	(IPP_PROC)n0_ippsTDESEncryptOFB,
	(IPP_PROC)k0_ippsTDESEncryptOFB,
	(IPP_PROC)k1_ippsTDESEncryptOFB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESEncryptOFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESEncryptOFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESEncryptOFB]
        jmp  rax
  }
};

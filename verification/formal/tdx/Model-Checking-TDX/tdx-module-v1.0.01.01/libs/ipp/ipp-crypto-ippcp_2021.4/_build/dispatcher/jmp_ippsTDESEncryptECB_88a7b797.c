#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus m7_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus n8_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus y8_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus e9_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus l9_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus n0_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus k0_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus k1_ippsTDESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESEncryptECB,
	(IPP_PROC)m7_ippsTDESEncryptECB,
	(IPP_PROC)n8_ippsTDESEncryptECB,
	(IPP_PROC)y8_ippsTDESEncryptECB,
	(IPP_PROC)e9_ippsTDESEncryptECB,
	(IPP_PROC)l9_ippsTDESEncryptECB,
	(IPP_PROC)n0_ippsTDESEncryptECB,
	(IPP_PROC)k0_ippsTDESEncryptECB,
	(IPP_PROC)k1_ippsTDESEncryptECB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESEncryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESEncryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESEncryptECB]
        jmp  rax
  }
};

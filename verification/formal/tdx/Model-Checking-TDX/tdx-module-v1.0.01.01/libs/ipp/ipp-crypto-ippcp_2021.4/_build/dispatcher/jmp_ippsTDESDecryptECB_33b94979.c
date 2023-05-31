#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus m7_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus n8_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus y8_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus e9_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus l9_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus n0_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus k0_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
extern IppStatus k1_ippsTDESDecryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsTDESDecryptECB,
	(IPP_PROC)m7_ippsTDESDecryptECB,
	(IPP_PROC)n8_ippsTDESDecryptECB,
	(IPP_PROC)y8_ippsTDESDecryptECB,
	(IPP_PROC)e9_ippsTDESDecryptECB,
	(IPP_PROC)l9_ippsTDESDecryptECB,
	(IPP_PROC)n0_ippsTDESDecryptECB,
	(IPP_PROC)k0_ippsTDESDecryptECB,
	(IPP_PROC)k1_ippsTDESDecryptECB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsTDESDecryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsTDESDecryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsDESSpec* pCtx1, const IppsDESSpec* pCtx2, const IppsDESSpec* pCtx3, IppsCPPadding padding))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsTDESDecryptECB]
        jmp  rax
  }
};

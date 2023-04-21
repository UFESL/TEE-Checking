#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus m7_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n8_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus y8_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus e9_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus l9_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n0_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k0_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k1_ippsAESDecryptCBC(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESDecryptCBC,
	(IPP_PROC)m7_ippsAESDecryptCBC,
	(IPP_PROC)n8_ippsAESDecryptCBC,
	(IPP_PROC)y8_ippsAESDecryptCBC,
	(IPP_PROC)e9_ippsAESDecryptCBC,
	(IPP_PROC)l9_ippsAESDecryptCBC,
	(IPP_PROC)n0_ippsAESDecryptCBC,
	(IPP_PROC)k0_ippsAESDecryptCBC,
	(IPP_PROC)k1_ippsAESDecryptCBC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESDecryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESDecryptCBC,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESDecryptCBC]
        jmp  rax
  }
};

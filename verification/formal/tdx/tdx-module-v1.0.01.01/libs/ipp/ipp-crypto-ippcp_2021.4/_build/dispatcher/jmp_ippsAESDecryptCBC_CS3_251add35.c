#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus m7_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n8_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus y8_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus e9_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus l9_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n0_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k0_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k1_ippsAESDecryptCBC_CS3(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESDecryptCBC_CS3,
	(IPP_PROC)m7_ippsAESDecryptCBC_CS3,
	(IPP_PROC)n8_ippsAESDecryptCBC_CS3,
	(IPP_PROC)y8_ippsAESDecryptCBC_CS3,
	(IPP_PROC)e9_ippsAESDecryptCBC_CS3,
	(IPP_PROC)l9_ippsAESDecryptCBC_CS3,
	(IPP_PROC)n0_ippsAESDecryptCBC_CS3,
	(IPP_PROC)k0_ippsAESDecryptCBC_CS3,
	(IPP_PROC)k1_ippsAESDecryptCBC_CS3
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESDecryptCBC_CS3,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESDecryptCBC_CS3,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESDecryptCBC_CS3]
        jmp  rax
  }
};

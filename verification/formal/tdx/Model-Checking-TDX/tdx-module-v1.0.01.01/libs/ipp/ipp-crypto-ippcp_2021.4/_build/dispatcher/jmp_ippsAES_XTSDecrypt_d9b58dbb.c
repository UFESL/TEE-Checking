#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus m7_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus n8_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus y8_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus e9_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus l9_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus n0_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus k0_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
extern IppStatus k1_ippsAES_XTSDecrypt(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_XTSDecrypt,
	(IPP_PROC)m7_ippsAES_XTSDecrypt,
	(IPP_PROC)n8_ippsAES_XTSDecrypt,
	(IPP_PROC)y8_ippsAES_XTSDecrypt,
	(IPP_PROC)e9_ippsAES_XTSDecrypt,
	(IPP_PROC)l9_ippsAES_XTSDecrypt,
	(IPP_PROC)n0_ippsAES_XTSDecrypt,
	(IPP_PROC)k0_ippsAES_XTSDecrypt,
	(IPP_PROC)k1_ippsAES_XTSDecrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_XTSDecrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_XTSDecrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int bitSizeLen, const IppsAES_XTSSpec* pCtx, const Ipp8u* pTweak, int startCipherBlkNo))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_XTSDecrypt]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus m7_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus n8_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus y8_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus e9_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus l9_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus n0_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus k0_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus k1_ippsRSAEncrypt_PKCSv15(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)m7_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)n8_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)y8_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)e9_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)l9_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)n0_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)k0_ippsRSAEncrypt_PKCSv15,
	(IPP_PROC)k1_ippsRSAEncrypt_PKCSv15
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSAEncrypt_PKCSv15,(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSAEncrypt_PKCSv15,(const Ipp8u* pSrc, int srcLen, const Ipp8u* pRndPS, Ipp8u* pDst, const IppsRSAPublicKeyState* pKey, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSAEncrypt_PKCSv15]
        jmp  rax
  }
};

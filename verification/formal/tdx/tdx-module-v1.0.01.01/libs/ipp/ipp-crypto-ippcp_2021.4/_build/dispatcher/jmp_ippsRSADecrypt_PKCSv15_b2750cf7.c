#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus m7_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus n8_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus y8_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus e9_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus l9_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus n0_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus k0_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
extern IppStatus k1_ippsRSADecrypt_PKCSv15(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)m7_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)n8_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)y8_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)e9_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)l9_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)n0_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)k0_ippsRSADecrypt_PKCSv15,
	(IPP_PROC)k1_ippsRSADecrypt_PKCSv15
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRSADecrypt_PKCSv15,(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRSADecrypt_PKCSv15,(const Ipp8u* pSrc, Ipp8u* pDst, int* pDstLen, const IppsRSAPrivateKeyState* pKey, Ipp8u* pBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRSADecrypt_PKCSv15]
        jmp  rax
  }
};

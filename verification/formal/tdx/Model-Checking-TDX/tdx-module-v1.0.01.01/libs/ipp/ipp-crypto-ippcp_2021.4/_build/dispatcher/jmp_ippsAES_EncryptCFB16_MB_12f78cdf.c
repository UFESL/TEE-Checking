#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus m7_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus n8_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus y8_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus e9_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus l9_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus n0_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus k0_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
extern IppStatus k1_ippsAES_EncryptCFB16_MB(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)m7_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)n8_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)y8_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)e9_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)l9_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)n0_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)k0_ippsAES_EncryptCFB16_MB,
	(IPP_PROC)k1_ippsAES_EncryptCFB16_MB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_EncryptCFB16_MB,(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_EncryptCFB16_MB,(const Ipp8u* pSrc[], Ipp8u* pDst[], int len[], const IppsAESSpec* pCtx[], const Ipp8u* pIV[], IppStatus status[], int numBuffers))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_EncryptCFB16_MB]
        jmp  rax
  }
};

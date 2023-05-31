#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus m7_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n8_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus y8_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus e9_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus l9_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n0_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k0_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k1_ippsAESEncryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESEncryptCFB,
	(IPP_PROC)m7_ippsAESEncryptCFB,
	(IPP_PROC)n8_ippsAESEncryptCFB,
	(IPP_PROC)y8_ippsAESEncryptCFB,
	(IPP_PROC)e9_ippsAESEncryptCFB,
	(IPP_PROC)l9_ippsAESEncryptCFB,
	(IPP_PROC)n0_ippsAESEncryptCFB,
	(IPP_PROC)k0_ippsAESEncryptCFB,
	(IPP_PROC)k1_ippsAESEncryptCFB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESEncryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESEncryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESEncryptCFB]
        jmp  rax
  }
};

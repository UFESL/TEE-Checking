#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus m7_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n8_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus y8_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus e9_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus l9_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus n0_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k0_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
extern IppStatus k1_ippsAESDecryptCFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESDecryptCFB,
	(IPP_PROC)m7_ippsAESDecryptCFB,
	(IPP_PROC)n8_ippsAESDecryptCFB,
	(IPP_PROC)y8_ippsAESDecryptCFB,
	(IPP_PROC)e9_ippsAESDecryptCFB,
	(IPP_PROC)l9_ippsAESDecryptCFB,
	(IPP_PROC)n0_ippsAESDecryptCFB,
	(IPP_PROC)k0_ippsAESDecryptCFB,
	(IPP_PROC)k1_ippsAESDecryptCFB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESDecryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESDecryptCFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int cfbBlkSize, const IppsAESSpec* pCtx, const Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESDecryptCFB]
        jmp  rax
  }
};

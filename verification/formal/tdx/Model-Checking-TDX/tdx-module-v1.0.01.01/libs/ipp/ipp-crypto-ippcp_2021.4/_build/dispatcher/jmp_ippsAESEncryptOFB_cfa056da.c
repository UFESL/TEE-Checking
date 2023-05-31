#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus m7_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus n8_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus y8_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus e9_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus l9_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus n0_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus k0_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
extern IppStatus k1_ippsAESEncryptOFB(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESEncryptOFB,
	(IPP_PROC)m7_ippsAESEncryptOFB,
	(IPP_PROC)n8_ippsAESEncryptOFB,
	(IPP_PROC)y8_ippsAESEncryptOFB,
	(IPP_PROC)e9_ippsAESEncryptOFB,
	(IPP_PROC)l9_ippsAESEncryptOFB,
	(IPP_PROC)n0_ippsAESEncryptOFB,
	(IPP_PROC)k0_ippsAESEncryptOFB,
	(IPP_PROC)k1_ippsAESEncryptOFB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESEncryptOFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESEncryptOFB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, int ofbBlkSize, const IppsAESSpec* pCtx, Ipp8u* pIV))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESEncryptOFB]
        jmp  rax
  }
};

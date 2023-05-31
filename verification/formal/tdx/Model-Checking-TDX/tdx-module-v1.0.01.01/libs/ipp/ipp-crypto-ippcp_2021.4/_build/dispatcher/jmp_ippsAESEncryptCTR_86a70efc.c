#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus m7_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n8_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus y8_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus e9_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus l9_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus n0_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k0_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
extern IppStatus k1_ippsAESEncryptCTR(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESEncryptCTR,
	(IPP_PROC)m7_ippsAESEncryptCTR,
	(IPP_PROC)n8_ippsAESEncryptCTR,
	(IPP_PROC)y8_ippsAESEncryptCTR,
	(IPP_PROC)e9_ippsAESEncryptCTR,
	(IPP_PROC)l9_ippsAESEncryptCTR,
	(IPP_PROC)n0_ippsAESEncryptCTR,
	(IPP_PROC)k0_ippsAESEncryptCTR,
	(IPP_PROC)k1_ippsAESEncryptCTR
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESEncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESEncryptCTR,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx, Ipp8u* pCtrValue, int ctrNumBitSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESEncryptCTR]
        jmp  rax
  }
};

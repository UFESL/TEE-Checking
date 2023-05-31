#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus m7_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus n8_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus y8_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus e9_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus l9_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus n0_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus k0_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
extern IppStatus k1_ippsAESEncryptECB(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAESEncryptECB,
	(IPP_PROC)m7_ippsAESEncryptECB,
	(IPP_PROC)n8_ippsAESEncryptECB,
	(IPP_PROC)y8_ippsAESEncryptECB,
	(IPP_PROC)e9_ippsAESEncryptECB,
	(IPP_PROC)l9_ippsAESEncryptECB,
	(IPP_PROC)n0_ippsAESEncryptECB,
	(IPP_PROC)k0_ippsAESEncryptECB,
	(IPP_PROC)k1_ippsAESEncryptECB
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAESEncryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAESEncryptECB,(const Ipp8u* pSrc, Ipp8u* pDst, int len, const IppsAESSpec* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAESEncryptECB]
        jmp  rax
  }
};

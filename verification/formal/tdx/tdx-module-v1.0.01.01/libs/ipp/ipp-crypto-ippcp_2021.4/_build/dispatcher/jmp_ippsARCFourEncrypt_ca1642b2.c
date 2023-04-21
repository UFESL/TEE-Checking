#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus m7_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus n8_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus y8_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus e9_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus l9_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus n0_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus k0_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus k1_ippsARCFourEncrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourEncrypt,
	(IPP_PROC)m7_ippsARCFourEncrypt,
	(IPP_PROC)n8_ippsARCFourEncrypt,
	(IPP_PROC)y8_ippsARCFourEncrypt,
	(IPP_PROC)e9_ippsARCFourEncrypt,
	(IPP_PROC)l9_ippsARCFourEncrypt,
	(IPP_PROC)n0_ippsARCFourEncrypt,
	(IPP_PROC)k0_ippsARCFourEncrypt,
	(IPP_PROC)k1_ippsARCFourEncrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourEncrypt,(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourEncrypt,(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourEncrypt]
        jmp  rax
  }
};

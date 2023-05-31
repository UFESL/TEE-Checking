#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus m7_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus n8_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus y8_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus e9_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus l9_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus n0_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus k0_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
extern IppStatus k1_ippsARCFourDecrypt(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourDecrypt,
	(IPP_PROC)m7_ippsARCFourDecrypt,
	(IPP_PROC)n8_ippsARCFourDecrypt,
	(IPP_PROC)y8_ippsARCFourDecrypt,
	(IPP_PROC)e9_ippsARCFourDecrypt,
	(IPP_PROC)l9_ippsARCFourDecrypt,
	(IPP_PROC)n0_ippsARCFourDecrypt,
	(IPP_PROC)k0_ippsARCFourDecrypt,
	(IPP_PROC)k1_ippsARCFourDecrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourDecrypt,(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourDecrypt,(const Ipp8u *pSrc, Ipp8u *pDst, int length, IppsARCFourState *pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourDecrypt]
        jmp  rax
  }
};

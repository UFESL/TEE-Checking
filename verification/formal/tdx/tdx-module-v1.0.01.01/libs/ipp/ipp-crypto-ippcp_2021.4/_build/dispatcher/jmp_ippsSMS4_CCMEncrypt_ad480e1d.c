#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus m7_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus n8_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus y8_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus e9_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus l9_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus n0_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus k0_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
extern IppStatus k1_ippsSMS4_CCMEncrypt(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSMS4_CCMEncrypt,
	(IPP_PROC)m7_ippsSMS4_CCMEncrypt,
	(IPP_PROC)n8_ippsSMS4_CCMEncrypt,
	(IPP_PROC)y8_ippsSMS4_CCMEncrypt,
	(IPP_PROC)e9_ippsSMS4_CCMEncrypt,
	(IPP_PROC)l9_ippsSMS4_CCMEncrypt,
	(IPP_PROC)n0_ippsSMS4_CCMEncrypt,
	(IPP_PROC)k0_ippsSMS4_CCMEncrypt,
	(IPP_PROC)k1_ippsSMS4_CCMEncrypt
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSMS4_CCMEncrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSMS4_CCMEncrypt,(const Ipp8u* pSrc, Ipp8u* pDst, int len, IppsSMS4_CCMState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSMS4_CCMEncrypt]
        jmp  rax
  }
};

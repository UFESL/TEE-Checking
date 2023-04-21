#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int len, Ipp8u* pMD);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus m7_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus n8_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus y8_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus e9_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus l9_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus n0_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus k0_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus k1_ippsSHA384MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSHA384MessageDigest,
	(IPP_PROC)m7_ippsSHA384MessageDigest,
	(IPP_PROC)n8_ippsSHA384MessageDigest,
	(IPP_PROC)y8_ippsSHA384MessageDigest,
	(IPP_PROC)e9_ippsSHA384MessageDigest,
	(IPP_PROC)l9_ippsSHA384MessageDigest,
	(IPP_PROC)n0_ippsSHA384MessageDigest,
	(IPP_PROC)k0_ippsSHA384MessageDigest,
	(IPP_PROC)k1_ippsSHA384MessageDigest
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSHA384MessageDigest,(const Ipp8u* pMsg, int len, Ipp8u* pMD))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSHA384MessageDigest,(const Ipp8u* pMsg, int len, Ipp8u* pMD))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSHA384MessageDigest]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int len, Ipp8u* pMD);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus m7_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus n8_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus y8_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus e9_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus l9_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus n0_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus k0_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
extern IppStatus k1_ippsSM3MessageDigest(const Ipp8u* pMsg, int len, Ipp8u* pMD);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSM3MessageDigest,
	(IPP_PROC)m7_ippsSM3MessageDigest,
	(IPP_PROC)n8_ippsSM3MessageDigest,
	(IPP_PROC)y8_ippsSM3MessageDigest,
	(IPP_PROC)e9_ippsSM3MessageDigest,
	(IPP_PROC)l9_ippsSM3MessageDigest,
	(IPP_PROC)n0_ippsSM3MessageDigest,
	(IPP_PROC)k0_ippsSM3MessageDigest,
	(IPP_PROC)k1_ippsSM3MessageDigest
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSM3MessageDigest,(const Ipp8u* pMsg, int len, Ipp8u* pMD))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSM3MessageDigest,(const Ipp8u* pMsg, int len, Ipp8u* pMD))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSM3MessageDigest]
        jmp  rax
  }
};

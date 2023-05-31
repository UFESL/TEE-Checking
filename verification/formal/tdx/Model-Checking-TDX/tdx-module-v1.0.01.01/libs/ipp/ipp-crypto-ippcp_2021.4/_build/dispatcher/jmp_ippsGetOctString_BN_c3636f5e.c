#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus m7_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus n8_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus y8_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus e9_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus l9_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus n0_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus k0_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
extern IppStatus k1_ippsGetOctString_BN(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGetOctString_BN,
	(IPP_PROC)m7_ippsGetOctString_BN,
	(IPP_PROC)n8_ippsGetOctString_BN,
	(IPP_PROC)y8_ippsGetOctString_BN,
	(IPP_PROC)e9_ippsGetOctString_BN,
	(IPP_PROC)l9_ippsGetOctString_BN,
	(IPP_PROC)n0_ippsGetOctString_BN,
	(IPP_PROC)k0_ippsGetOctString_BN,
	(IPP_PROC)k1_ippsGetOctString_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGetOctString_BN,(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGetOctString_BN,(Ipp8u* pStr, int strLen, const IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGetOctString_BN]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus m7_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus n8_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus y8_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus e9_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus l9_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus n0_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus k0_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
extern IppStatus k1_ippsSetOctString_BN(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSetOctString_BN,
	(IPP_PROC)m7_ippsSetOctString_BN,
	(IPP_PROC)n8_ippsSetOctString_BN,
	(IPP_PROC)y8_ippsSetOctString_BN,
	(IPP_PROC)e9_ippsSetOctString_BN,
	(IPP_PROC)l9_ippsSetOctString_BN,
	(IPP_PROC)n0_ippsSetOctString_BN,
	(IPP_PROC)k0_ippsSetOctString_BN,
	(IPP_PROC)k1_ippsSetOctString_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSetOctString_BN,(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSetOctString_BN,(const Ipp8u* pStr, int strLen, IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSetOctString_BN]
        jmp  rax
  }
};

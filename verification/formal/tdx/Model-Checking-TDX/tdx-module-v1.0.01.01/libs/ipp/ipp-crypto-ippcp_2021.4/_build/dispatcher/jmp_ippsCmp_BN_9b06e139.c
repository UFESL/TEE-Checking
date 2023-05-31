#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus m7_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus n8_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus y8_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus e9_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus l9_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus n0_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus k0_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
extern IppStatus k1_ippsCmp_BN(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsCmp_BN,
	(IPP_PROC)m7_ippsCmp_BN,
	(IPP_PROC)n8_ippsCmp_BN,
	(IPP_PROC)y8_ippsCmp_BN,
	(IPP_PROC)e9_ippsCmp_BN,
	(IPP_PROC)l9_ippsCmp_BN,
	(IPP_PROC)n0_ippsCmp_BN,
	(IPP_PROC)k0_ippsCmp_BN,
	(IPP_PROC)k1_ippsCmp_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsCmp_BN,(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsCmp_BN,(const IppsBigNumState* pA, const IppsBigNumState* pB, Ipp32u* pResult))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsCmp_BN]
        jmp  rax
  }
};

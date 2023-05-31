#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pBN, Ipp32u* pResult);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus m7_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus n8_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus y8_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus e9_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus l9_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus n0_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus k0_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
extern IppStatus k1_ippsCmpZero_BN(const IppsBigNumState* pBN, Ipp32u* pResult);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsCmpZero_BN,
	(IPP_PROC)m7_ippsCmpZero_BN,
	(IPP_PROC)n8_ippsCmpZero_BN,
	(IPP_PROC)y8_ippsCmpZero_BN,
	(IPP_PROC)e9_ippsCmpZero_BN,
	(IPP_PROC)l9_ippsCmpZero_BN,
	(IPP_PROC)n0_ippsCmpZero_BN,
	(IPP_PROC)k0_ippsCmpZero_BN,
	(IPP_PROC)k1_ippsCmpZero_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsCmpZero_BN,(const IppsBigNumState* pBN, Ipp32u* pResult))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsCmpZero_BN,(const IppsBigNumState* pBN, Ipp32u* pResult))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsCmpZero_BN]
        jmp  rax
  }
};

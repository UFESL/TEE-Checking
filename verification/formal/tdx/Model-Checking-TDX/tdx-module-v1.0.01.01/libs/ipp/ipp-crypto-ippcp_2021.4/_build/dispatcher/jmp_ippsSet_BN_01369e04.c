#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus m7_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus n8_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus y8_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus e9_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus l9_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus n0_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus k0_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
extern IppStatus k1_ippsSet_BN(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsSet_BN,
	(IPP_PROC)m7_ippsSet_BN,
	(IPP_PROC)n8_ippsSet_BN,
	(IPP_PROC)y8_ippsSet_BN,
	(IPP_PROC)e9_ippsSet_BN,
	(IPP_PROC)l9_ippsSet_BN,
	(IPP_PROC)n0_ippsSet_BN,
	(IPP_PROC)k0_ippsSet_BN,
	(IPP_PROC)k1_ippsSet_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsSet_BN,(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsSet_BN,(IppsBigNumSGN sgn, int length, const Ipp32u* pData, IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsSet_BN]
        jmp  rax
  }
};

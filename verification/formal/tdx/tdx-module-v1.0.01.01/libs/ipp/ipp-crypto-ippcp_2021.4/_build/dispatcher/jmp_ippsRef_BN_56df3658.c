#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus m7_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus n8_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus y8_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus e9_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus l9_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus n0_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus k0_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
extern IppStatus k1_ippsRef_BN(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsRef_BN,
	(IPP_PROC)m7_ippsRef_BN,
	(IPP_PROC)n8_ippsRef_BN,
	(IPP_PROC)y8_ippsRef_BN,
	(IPP_PROC)e9_ippsRef_BN,
	(IPP_PROC)l9_ippsRef_BN,
	(IPP_PROC)n0_ippsRef_BN,
	(IPP_PROC)k0_ippsRef_BN,
	(IPP_PROC)k1_ippsRef_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsRef_BN,(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsRef_BN,(IppsBigNumSGN* pSgn, int* bitSize, Ipp32u** const ppData, const IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsRef_BN]
        jmp  rax
  }
};

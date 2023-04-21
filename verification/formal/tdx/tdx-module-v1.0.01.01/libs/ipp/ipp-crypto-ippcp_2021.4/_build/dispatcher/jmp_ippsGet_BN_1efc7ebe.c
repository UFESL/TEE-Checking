#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus m7_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus n8_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus y8_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus e9_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus l9_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus n0_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus k0_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
extern IppStatus k1_ippsGet_BN(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGet_BN,
	(IPP_PROC)m7_ippsGet_BN,
	(IPP_PROC)n8_ippsGet_BN,
	(IPP_PROC)y8_ippsGet_BN,
	(IPP_PROC)e9_ippsGet_BN,
	(IPP_PROC)l9_ippsGet_BN,
	(IPP_PROC)n0_ippsGet_BN,
	(IPP_PROC)k0_ippsGet_BN,
	(IPP_PROC)k1_ippsGet_BN
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGet_BN,(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGet_BN,(IppsBigNumSGN* pSgn, int* pLength, Ipp32u* pData, const IppsBigNumState* pBN))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGet_BN]
        jmp  rax
  }
};

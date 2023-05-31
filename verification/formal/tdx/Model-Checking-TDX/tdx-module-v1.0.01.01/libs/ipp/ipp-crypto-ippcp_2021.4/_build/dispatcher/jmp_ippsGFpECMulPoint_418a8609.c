#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECMulPoint(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECMulPoint,
	(IPP_PROC)m7_ippsGFpECMulPoint,
	(IPP_PROC)n8_ippsGFpECMulPoint,
	(IPP_PROC)y8_ippsGFpECMulPoint,
	(IPP_PROC)e9_ippsGFpECMulPoint,
	(IPP_PROC)l9_ippsGFpECMulPoint,
	(IPP_PROC)n0_ippsGFpECMulPoint,
	(IPP_PROC)k0_ippsGFpECMulPoint,
	(IPP_PROC)k1_ippsGFpECMulPoint
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECMulPoint,(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECMulPoint,(const IppsGFpECPoint* pP, const IppsBigNumState* pN, IppsGFpECPoint* pR, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECMulPoint]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECTstPointInSubgroup(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)m7_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)n8_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)y8_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)e9_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)l9_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)n0_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)k0_ippsGFpECTstPointInSubgroup,
	(IPP_PROC)k1_ippsGFpECTstPointInSubgroup
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECTstPointInSubgroup,(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECTstPointInSubgroup,(const IppsGFpECPoint* pP, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECTstPointInSubgroup]
        jmp  rax
  }
};

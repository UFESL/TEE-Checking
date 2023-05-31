#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECVerify(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECVerify,
	(IPP_PROC)m7_ippsGFpECVerify,
	(IPP_PROC)n8_ippsGFpECVerify,
	(IPP_PROC)y8_ippsGFpECVerify,
	(IPP_PROC)e9_ippsGFpECVerify,
	(IPP_PROC)l9_ippsGFpECVerify,
	(IPP_PROC)n0_ippsGFpECVerify,
	(IPP_PROC)k0_ippsGFpECVerify,
	(IPP_PROC)k1_ippsGFpECVerify
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECVerify,(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECVerify,(IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECVerify]
        jmp  rax
  }
};

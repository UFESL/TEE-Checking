#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSignNR(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSignNR,
	(IPP_PROC)m7_ippsGFpECSignNR,
	(IPP_PROC)n8_ippsGFpECSignNR,
	(IPP_PROC)y8_ippsGFpECSignNR,
	(IPP_PROC)e9_ippsGFpECSignNR,
	(IPP_PROC)l9_ippsGFpECSignNR,
	(IPP_PROC)n0_ippsGFpECSignNR,
	(IPP_PROC)k0_ippsGFpECSignNR,
	(IPP_PROC)k1_ippsGFpECSignNR
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSignNR,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSignNR,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSignNR]
        jmp  rax
  }
};

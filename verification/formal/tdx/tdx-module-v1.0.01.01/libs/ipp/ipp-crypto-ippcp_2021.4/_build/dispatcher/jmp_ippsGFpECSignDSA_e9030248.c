#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSignDSA(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSignDSA,
	(IPP_PROC)m7_ippsGFpECSignDSA,
	(IPP_PROC)n8_ippsGFpECSignDSA,
	(IPP_PROC)y8_ippsGFpECSignDSA,
	(IPP_PROC)e9_ippsGFpECSignDSA,
	(IPP_PROC)l9_ippsGFpECSignDSA,
	(IPP_PROC)n0_ippsGFpECSignDSA,
	(IPP_PROC)k0_ippsGFpECSignDSA,
	(IPP_PROC)k1_ippsGFpECSignDSA
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSignDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSignDSA,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSignDSA]
        jmp  rax
  }
};

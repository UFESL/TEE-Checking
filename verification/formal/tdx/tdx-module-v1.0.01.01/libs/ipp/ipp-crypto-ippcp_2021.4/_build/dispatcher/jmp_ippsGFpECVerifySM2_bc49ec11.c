#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECVerifySM2(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECVerifySM2,
	(IPP_PROC)m7_ippsGFpECVerifySM2,
	(IPP_PROC)n8_ippsGFpECVerifySM2,
	(IPP_PROC)y8_ippsGFpECVerifySM2,
	(IPP_PROC)e9_ippsGFpECVerifySM2,
	(IPP_PROC)l9_ippsGFpECVerifySM2,
	(IPP_PROC)n0_ippsGFpECVerifySM2,
	(IPP_PROC)k0_ippsGFpECVerifySM2,
	(IPP_PROC)k1_ippsGFpECVerifySM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECVerifySM2,(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECVerifySM2,(const IppsBigNumState* pMsgDigest, const IppsGFpECPoint* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECVerifySM2]
        jmp  rax
  }
};

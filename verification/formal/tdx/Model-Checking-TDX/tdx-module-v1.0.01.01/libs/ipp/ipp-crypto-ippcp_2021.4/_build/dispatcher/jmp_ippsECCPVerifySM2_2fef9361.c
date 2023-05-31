#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPVerifySM2(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPVerifySM2,
	(IPP_PROC)m7_ippsECCPVerifySM2,
	(IPP_PROC)n8_ippsECCPVerifySM2,
	(IPP_PROC)y8_ippsECCPVerifySM2,
	(IPP_PROC)e9_ippsECCPVerifySM2,
	(IPP_PROC)l9_ippsECCPVerifySM2,
	(IPP_PROC)n0_ippsECCPVerifySM2,
	(IPP_PROC)k0_ippsECCPVerifySM2,
	(IPP_PROC)k1_ippsECCPVerifySM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPVerifySM2,(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPVerifySM2,(const IppsBigNumState* pMsgDigest, const IppsECCPPointState* pRegPublic, const IppsBigNumState* pSignR, const IppsBigNumState* pSignS, IppECResult* pResult, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPVerifySM2]
        jmp  rax
  }
};

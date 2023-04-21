#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSignSM2(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSignSM2,
	(IPP_PROC)m7_ippsECCPSignSM2,
	(IPP_PROC)n8_ippsECCPSignSM2,
	(IPP_PROC)y8_ippsECCPSignSM2,
	(IPP_PROC)e9_ippsECCPSignSM2,
	(IPP_PROC)l9_ippsECCPSignSM2,
	(IPP_PROC)n0_ippsECCPSignSM2,
	(IPP_PROC)k0_ippsECCPSignSM2,
	(IPP_PROC)k1_ippsECCPSignSM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSignSM2,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSignSM2,(const IppsBigNumState* pMsgDigest, const IppsBigNumState* pRegPrivate, IppsBigNumState* pEphPrivate, IppsBigNumState* pSignR, IppsBigNumState* pSignS, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSignSM2]
        jmp  rax
  }
};

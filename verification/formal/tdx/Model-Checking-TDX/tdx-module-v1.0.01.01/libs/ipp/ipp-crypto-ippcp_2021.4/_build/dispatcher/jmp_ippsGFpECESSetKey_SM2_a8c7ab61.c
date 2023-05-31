#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus m7_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus n8_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus y8_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus e9_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus l9_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus n0_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus k0_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
extern IppStatus k1_ippsGFpECESSetKey_SM2(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECESSetKey_SM2,
	(IPP_PROC)m7_ippsGFpECESSetKey_SM2,
	(IPP_PROC)n8_ippsGFpECESSetKey_SM2,
	(IPP_PROC)y8_ippsGFpECESSetKey_SM2,
	(IPP_PROC)e9_ippsGFpECESSetKey_SM2,
	(IPP_PROC)l9_ippsGFpECESSetKey_SM2,
	(IPP_PROC)n0_ippsGFpECESSetKey_SM2,
	(IPP_PROC)k0_ippsGFpECESSetKey_SM2,
	(IPP_PROC)k1_ippsGFpECESSetKey_SM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECESSetKey_SM2,(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECESSetKey_SM2,(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppsECESState_SM2* pState, IppsGFpECState* pEC, Ipp8u* pEcScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECESSetKey_SM2]
        jmp  rax
  }
};

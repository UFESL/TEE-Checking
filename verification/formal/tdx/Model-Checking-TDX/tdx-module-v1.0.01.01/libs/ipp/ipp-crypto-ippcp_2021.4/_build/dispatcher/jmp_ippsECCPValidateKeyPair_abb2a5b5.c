#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPValidateKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPValidateKeyPair,
	(IPP_PROC)m7_ippsECCPValidateKeyPair,
	(IPP_PROC)n8_ippsECCPValidateKeyPair,
	(IPP_PROC)y8_ippsECCPValidateKeyPair,
	(IPP_PROC)e9_ippsECCPValidateKeyPair,
	(IPP_PROC)l9_ippsECCPValidateKeyPair,
	(IPP_PROC)n0_ippsECCPValidateKeyPair,
	(IPP_PROC)k0_ippsECCPValidateKeyPair,
	(IPP_PROC)k1_ippsECCPValidateKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPValidateKeyPair,(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPValidateKeyPair,(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppECResult* pResult, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPValidateKeyPair]
        jmp  rax
  }
};

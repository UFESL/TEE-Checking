#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPPublicKey(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPPublicKey,
	(IPP_PROC)m7_ippsECCPPublicKey,
	(IPP_PROC)n8_ippsECCPPublicKey,
	(IPP_PROC)y8_ippsECCPPublicKey,
	(IPP_PROC)e9_ippsECCPPublicKey,
	(IPP_PROC)l9_ippsECCPPublicKey,
	(IPP_PROC)n0_ippsECCPPublicKey,
	(IPP_PROC)k0_ippsECCPPublicKey,
	(IPP_PROC)k1_ippsECCPPublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPPublicKey,(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPPublicKey,(const IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPPublicKey]
        jmp  rax
  }
};

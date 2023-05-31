#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSharedSecretDHC,
	(IPP_PROC)m7_ippsECCPSharedSecretDHC,
	(IPP_PROC)n8_ippsECCPSharedSecretDHC,
	(IPP_PROC)y8_ippsECCPSharedSecretDHC,
	(IPP_PROC)e9_ippsECCPSharedSecretDHC,
	(IPP_PROC)l9_ippsECCPSharedSecretDHC,
	(IPP_PROC)n0_ippsECCPSharedSecretDHC,
	(IPP_PROC)k0_ippsECCPSharedSecretDHC,
	(IPP_PROC)k1_ippsECCPSharedSecretDHC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSharedSecretDHC,(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSharedSecretDHC,(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSharedSecretDHC]
        jmp  rax
  }
};

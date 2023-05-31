#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSharedSecretDH,
	(IPP_PROC)m7_ippsECCPSharedSecretDH,
	(IPP_PROC)n8_ippsECCPSharedSecretDH,
	(IPP_PROC)y8_ippsECCPSharedSecretDH,
	(IPP_PROC)e9_ippsECCPSharedSecretDH,
	(IPP_PROC)l9_ippsECCPSharedSecretDH,
	(IPP_PROC)n0_ippsECCPSharedSecretDH,
	(IPP_PROC)k0_ippsECCPSharedSecretDH,
	(IPP_PROC)k1_ippsECCPSharedSecretDH
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSharedSecretDH,(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSharedSecretDH,(const IppsBigNumState* pPrivateA, const IppsECCPPointState* pPublicB, IppsBigNumState* pShare, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSharedSecretDH]
        jmp  rax
  }
};

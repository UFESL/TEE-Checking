#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSharedSecretDHC(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSharedSecretDHC,
	(IPP_PROC)m7_ippsGFpECSharedSecretDHC,
	(IPP_PROC)n8_ippsGFpECSharedSecretDHC,
	(IPP_PROC)y8_ippsGFpECSharedSecretDHC,
	(IPP_PROC)e9_ippsGFpECSharedSecretDHC,
	(IPP_PROC)l9_ippsGFpECSharedSecretDHC,
	(IPP_PROC)n0_ippsGFpECSharedSecretDHC,
	(IPP_PROC)k0_ippsGFpECSharedSecretDHC,
	(IPP_PROC)k1_ippsGFpECSharedSecretDHC
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSharedSecretDHC,(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSharedSecretDHC,(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSharedSecretDHC]
        jmp  rax
  }
};

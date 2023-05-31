#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSharedSecretDH(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSharedSecretDH,
	(IPP_PROC)m7_ippsGFpECSharedSecretDH,
	(IPP_PROC)n8_ippsGFpECSharedSecretDH,
	(IPP_PROC)y8_ippsGFpECSharedSecretDH,
	(IPP_PROC)e9_ippsGFpECSharedSecretDH,
	(IPP_PROC)l9_ippsGFpECSharedSecretDH,
	(IPP_PROC)n0_ippsGFpECSharedSecretDH,
	(IPP_PROC)k0_ippsGFpECSharedSecretDH,
	(IPP_PROC)k1_ippsGFpECSharedSecretDH
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSharedSecretDH,(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSharedSecretDH,(const IppsBigNumState* pPrivateA, const IppsGFpECPoint* pPublicB, IppsBigNumState* pShare, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSharedSecretDH]
        jmp  rax
  }
};

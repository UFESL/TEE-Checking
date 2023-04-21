#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECPublicKey(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECPublicKey,
	(IPP_PROC)m7_ippsGFpECPublicKey,
	(IPP_PROC)n8_ippsGFpECPublicKey,
	(IPP_PROC)y8_ippsGFpECPublicKey,
	(IPP_PROC)e9_ippsGFpECPublicKey,
	(IPP_PROC)l9_ippsGFpECPublicKey,
	(IPP_PROC)n0_ippsGFpECPublicKey,
	(IPP_PROC)k0_ippsGFpECPublicKey,
	(IPP_PROC)k1_ippsGFpECPublicKey
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECPublicKey,(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECPublicKey,(const IppsBigNumState* pPrivate, IppsGFpECPoint* pPublic, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECPublicKey]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECTstKeyPair(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECTstKeyPair,
	(IPP_PROC)m7_ippsGFpECTstKeyPair,
	(IPP_PROC)n8_ippsGFpECTstKeyPair,
	(IPP_PROC)y8_ippsGFpECTstKeyPair,
	(IPP_PROC)e9_ippsGFpECTstKeyPair,
	(IPP_PROC)l9_ippsGFpECTstKeyPair,
	(IPP_PROC)n0_ippsGFpECTstKeyPair,
	(IPP_PROC)k0_ippsGFpECTstKeyPair,
	(IPP_PROC)k1_ippsGFpECTstKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECTstKeyPair,(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECTstKeyPair,(const IppsBigNumState* pPrivate, const IppsGFpECPoint* pPublic, IppECResult* pResult, IppsGFpECState* pEC, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECTstKeyPair]
        jmp  rax
  }
};

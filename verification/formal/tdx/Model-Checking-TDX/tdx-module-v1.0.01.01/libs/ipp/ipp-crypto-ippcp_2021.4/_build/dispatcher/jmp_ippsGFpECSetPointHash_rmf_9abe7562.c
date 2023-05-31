#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpECSetPointHash_rmf(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)m7_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)n8_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)y8_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)e9_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)l9_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)n0_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)k0_ippsGFpECSetPointHash_rmf,
	(IPP_PROC)k1_ippsGFpECSetPointHash_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetPointHash_rmf,(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetPointHash_rmf,(Ipp32u hdr, const Ipp8u* pMsg, int msgLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC, const IppsHashMethod* pMethod, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetPointHash_rmf]
        jmp  rax
  }
};

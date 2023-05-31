#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus m7_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus n8_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus y8_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus e9_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus l9_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus n0_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus k0_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
extern IppStatus k1_ippsHashDuplicate_rmf(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashDuplicate_rmf,
	(IPP_PROC)m7_ippsHashDuplicate_rmf,
	(IPP_PROC)n8_ippsHashDuplicate_rmf,
	(IPP_PROC)y8_ippsHashDuplicate_rmf,
	(IPP_PROC)e9_ippsHashDuplicate_rmf,
	(IPP_PROC)l9_ippsHashDuplicate_rmf,
	(IPP_PROC)n0_ippsHashDuplicate_rmf,
	(IPP_PROC)k0_ippsHashDuplicate_rmf,
	(IPP_PROC)k1_ippsHashDuplicate_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashDuplicate_rmf,(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashDuplicate_rmf,(const IppsHashState_rmf* pSrcState, IppsHashState_rmf* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashDuplicate_rmf]
        jmp  rax
  }
};

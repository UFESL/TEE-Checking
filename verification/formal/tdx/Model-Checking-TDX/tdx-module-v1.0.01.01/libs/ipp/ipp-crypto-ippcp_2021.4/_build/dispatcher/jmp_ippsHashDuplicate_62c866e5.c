#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsHashState* pSrcState, IppsHashState* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus m7_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus n8_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus y8_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus e9_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus l9_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus n0_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus k0_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
extern IppStatus k1_ippsHashDuplicate(const IppsHashState* pSrcState, IppsHashState* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashDuplicate,
	(IPP_PROC)m7_ippsHashDuplicate,
	(IPP_PROC)n8_ippsHashDuplicate,
	(IPP_PROC)y8_ippsHashDuplicate,
	(IPP_PROC)e9_ippsHashDuplicate,
	(IPP_PROC)l9_ippsHashDuplicate,
	(IPP_PROC)n0_ippsHashDuplicate,
	(IPP_PROC)k0_ippsHashDuplicate,
	(IPP_PROC)k1_ippsHashDuplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashDuplicate,(const IppsHashState* pSrcState, IppsHashState* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashDuplicate,(const IppsHashState* pSrcState, IppsHashState* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashDuplicate]
        jmp  rax
  }
};

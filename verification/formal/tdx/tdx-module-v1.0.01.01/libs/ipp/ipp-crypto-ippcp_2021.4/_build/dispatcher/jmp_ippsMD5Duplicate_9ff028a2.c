#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsMD5State* pSrcState, IppsMD5State* pDstState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus m7_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus n8_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus y8_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus e9_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus l9_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus n0_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus k0_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
extern IppStatus k1_ippsMD5Duplicate(const IppsMD5State* pSrcState, IppsMD5State* pDstState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsMD5Duplicate,
	(IPP_PROC)m7_ippsMD5Duplicate,
	(IPP_PROC)n8_ippsMD5Duplicate,
	(IPP_PROC)y8_ippsMD5Duplicate,
	(IPP_PROC)e9_ippsMD5Duplicate,
	(IPP_PROC)l9_ippsMD5Duplicate,
	(IPP_PROC)n0_ippsMD5Duplicate,
	(IPP_PROC)k0_ippsMD5Duplicate,
	(IPP_PROC)k1_ippsMD5Duplicate
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsMD5Duplicate,(const IppsMD5State* pSrcState, IppsMD5State* pDstState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsMD5Duplicate,(const IppsMD5State* pSrcState, IppsMD5State* pDstState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsMD5Duplicate]
        jmp  rax
  }
};

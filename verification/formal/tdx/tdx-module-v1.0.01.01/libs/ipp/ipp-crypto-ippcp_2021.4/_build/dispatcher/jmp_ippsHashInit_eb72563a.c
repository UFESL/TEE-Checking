#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsHashState* pState, IppHashAlgId hashAlg);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus m7_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus n8_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus y8_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus e9_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus l9_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus n0_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus k0_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
extern IppStatus k1_ippsHashInit(IppsHashState* pState, IppHashAlgId hashAlg);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashInit,
	(IPP_PROC)m7_ippsHashInit,
	(IPP_PROC)n8_ippsHashInit,
	(IPP_PROC)y8_ippsHashInit,
	(IPP_PROC)e9_ippsHashInit,
	(IPP_PROC)l9_ippsHashInit,
	(IPP_PROC)n0_ippsHashInit,
	(IPP_PROC)k0_ippsHashInit,
	(IPP_PROC)k1_ippsHashInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashInit,(IppsHashState* pState, IppHashAlgId hashAlg))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashInit,(IppsHashState* pState, IppHashAlgId hashAlg))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashInit]
        jmp  rax
  }
};

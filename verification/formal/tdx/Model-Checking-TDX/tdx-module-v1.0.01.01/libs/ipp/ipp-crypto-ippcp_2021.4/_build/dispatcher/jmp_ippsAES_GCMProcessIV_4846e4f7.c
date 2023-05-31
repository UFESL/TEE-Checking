#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus m7_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus n8_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus y8_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus e9_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus l9_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus n0_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus k0_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
extern IppStatus k1_ippsAES_GCMProcessIV(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_GCMProcessIV,
	(IPP_PROC)m7_ippsAES_GCMProcessIV,
	(IPP_PROC)n8_ippsAES_GCMProcessIV,
	(IPP_PROC)y8_ippsAES_GCMProcessIV,
	(IPP_PROC)e9_ippsAES_GCMProcessIV,
	(IPP_PROC)l9_ippsAES_GCMProcessIV,
	(IPP_PROC)n0_ippsAES_GCMProcessIV,
	(IPP_PROC)k0_ippsAES_GCMProcessIV,
	(IPP_PROC)k1_ippsAES_GCMProcessIV
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_GCMProcessIV,(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_GCMProcessIV,(const Ipp8u* pIV, int ivLen, IppsAES_GCMState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_GCMProcessIV]
        jmp  rax
  }
};

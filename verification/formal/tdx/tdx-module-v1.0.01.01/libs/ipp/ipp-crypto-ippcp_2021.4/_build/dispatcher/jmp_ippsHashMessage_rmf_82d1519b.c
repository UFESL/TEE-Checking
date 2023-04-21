#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus m7_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus n8_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus y8_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus e9_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus l9_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus n0_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus k0_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
extern IppStatus k1_ippsHashMessage_rmf(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMessage_rmf,
	(IPP_PROC)m7_ippsHashMessage_rmf,
	(IPP_PROC)n8_ippsHashMessage_rmf,
	(IPP_PROC)y8_ippsHashMessage_rmf,
	(IPP_PROC)e9_ippsHashMessage_rmf,
	(IPP_PROC)l9_ippsHashMessage_rmf,
	(IPP_PROC)n0_ippsHashMessage_rmf,
	(IPP_PROC)k0_ippsHashMessage_rmf,
	(IPP_PROC)k1_ippsHashMessage_rmf
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashMessage_rmf,(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashMessage_rmf,(const Ipp8u* pMsg, int len, Ipp8u* pMD, const IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMessage_rmf]
        jmp  rax
  }
};

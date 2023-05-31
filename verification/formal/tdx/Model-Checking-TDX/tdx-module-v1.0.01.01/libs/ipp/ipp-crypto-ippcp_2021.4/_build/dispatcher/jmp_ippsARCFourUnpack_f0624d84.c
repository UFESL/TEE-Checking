#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsARCFourState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus m7_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus n8_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus y8_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus e9_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus l9_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus n0_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus k0_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
extern IppStatus k1_ippsARCFourUnpack(const Ipp8u* pBuffer, IppsARCFourState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourUnpack,
	(IPP_PROC)m7_ippsARCFourUnpack,
	(IPP_PROC)n8_ippsARCFourUnpack,
	(IPP_PROC)y8_ippsARCFourUnpack,
	(IPP_PROC)e9_ippsARCFourUnpack,
	(IPP_PROC)l9_ippsARCFourUnpack,
	(IPP_PROC)n0_ippsARCFourUnpack,
	(IPP_PROC)k0_ippsARCFourUnpack,
	(IPP_PROC)k1_ippsARCFourUnpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourUnpack,(const Ipp8u* pBuffer, IppsARCFourState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourUnpack,(const Ipp8u* pBuffer, IppsARCFourState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourUnpack]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus m7_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus n8_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus y8_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus e9_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus l9_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus n0_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus k0_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
extern IppStatus k1_ippsAES_CCMGetTag(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsAES_CCMGetTag,
	(IPP_PROC)m7_ippsAES_CCMGetTag,
	(IPP_PROC)n8_ippsAES_CCMGetTag,
	(IPP_PROC)y8_ippsAES_CCMGetTag,
	(IPP_PROC)e9_ippsAES_CCMGetTag,
	(IPP_PROC)l9_ippsAES_CCMGetTag,
	(IPP_PROC)n0_ippsAES_CCMGetTag,
	(IPP_PROC)k0_ippsAES_CCMGetTag,
	(IPP_PROC)k1_ippsAES_CCMGetTag
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsAES_CCMGetTag,(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsAES_CCMGetTag,(Ipp8u* pTag, int tagLen, const IppsAES_CCMState* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsAES_CCMGetTag]
        jmp  rax
  }
};

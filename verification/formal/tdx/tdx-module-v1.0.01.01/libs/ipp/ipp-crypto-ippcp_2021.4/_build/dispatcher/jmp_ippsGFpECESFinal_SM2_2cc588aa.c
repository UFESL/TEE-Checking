#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus m7_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus n8_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus y8_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus e9_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus l9_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus n0_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus k0_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
extern IppStatus k1_ippsGFpECESFinal_SM2(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECESFinal_SM2,
	(IPP_PROC)m7_ippsGFpECESFinal_SM2,
	(IPP_PROC)n8_ippsGFpECESFinal_SM2,
	(IPP_PROC)y8_ippsGFpECESFinal_SM2,
	(IPP_PROC)e9_ippsGFpECESFinal_SM2,
	(IPP_PROC)l9_ippsGFpECESFinal_SM2,
	(IPP_PROC)n0_ippsGFpECESFinal_SM2,
	(IPP_PROC)k0_ippsGFpECESFinal_SM2,
	(IPP_PROC)k1_ippsGFpECESFinal_SM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECESFinal_SM2,(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECESFinal_SM2,(Ipp8u* pTag, int tagLen, IppsECESState_SM2* pState))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECESFinal_SM2]
        jmp  rax
  }
};

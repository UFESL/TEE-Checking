#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpGetElementOctString(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpGetElementOctString,
	(IPP_PROC)m7_ippsGFpGetElementOctString,
	(IPP_PROC)n8_ippsGFpGetElementOctString,
	(IPP_PROC)y8_ippsGFpGetElementOctString,
	(IPP_PROC)e9_ippsGFpGetElementOctString,
	(IPP_PROC)l9_ippsGFpGetElementOctString,
	(IPP_PROC)n0_ippsGFpGetElementOctString,
	(IPP_PROC)k0_ippsGFpGetElementOctString,
	(IPP_PROC)k1_ippsGFpGetElementOctString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpGetElementOctString,(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpGetElementOctString,(const IppsGFpElement* pA, Ipp8u* pStr, int strSize, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpGetElementOctString]
        jmp  rax
  }
};

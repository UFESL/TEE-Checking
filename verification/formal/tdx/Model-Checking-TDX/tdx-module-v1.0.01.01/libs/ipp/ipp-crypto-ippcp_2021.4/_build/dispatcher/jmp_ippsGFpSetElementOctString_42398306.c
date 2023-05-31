#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSetElementOctString(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSetElementOctString,
	(IPP_PROC)m7_ippsGFpSetElementOctString,
	(IPP_PROC)n8_ippsGFpSetElementOctString,
	(IPP_PROC)y8_ippsGFpSetElementOctString,
	(IPP_PROC)e9_ippsGFpSetElementOctString,
	(IPP_PROC)l9_ippsGFpSetElementOctString,
	(IPP_PROC)n0_ippsGFpSetElementOctString,
	(IPP_PROC)k0_ippsGFpSetElementOctString,
	(IPP_PROC)k1_ippsGFpSetElementOctString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSetElementOctString,(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSetElementOctString,(const Ipp8u* pStr, int strSize, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSetElementOctString]
        jmp  rax
  }
};

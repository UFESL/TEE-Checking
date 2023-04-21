#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus m7_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus n8_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus y8_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus e9_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus l9_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus n0_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus k0_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
extern IppStatus k1_ippsGFpMultiExp(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpMultiExp,
	(IPP_PROC)m7_ippsGFpMultiExp,
	(IPP_PROC)n8_ippsGFpMultiExp,
	(IPP_PROC)y8_ippsGFpMultiExp,
	(IPP_PROC)e9_ippsGFpMultiExp,
	(IPP_PROC)l9_ippsGFpMultiExp,
	(IPP_PROC)n0_ippsGFpMultiExp,
	(IPP_PROC)k0_ippsGFpMultiExp,
	(IPP_PROC)k1_ippsGFpMultiExp
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpMultiExp,(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpMultiExp,(const IppsGFpElement* const ppElmA[], const IppsBigNumState* const ppE[], int nItems, IppsGFpElement* pR, IppsGFpState* pGFp, Ipp8u* pScratchBuffer))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpMultiExp]
        jmp  rax
  }
};

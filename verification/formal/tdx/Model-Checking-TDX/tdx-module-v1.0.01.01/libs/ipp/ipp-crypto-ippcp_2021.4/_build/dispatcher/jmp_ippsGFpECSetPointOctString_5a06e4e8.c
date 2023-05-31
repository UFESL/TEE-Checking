#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECSetPointOctString(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetPointOctString,
	(IPP_PROC)m7_ippsGFpECSetPointOctString,
	(IPP_PROC)n8_ippsGFpECSetPointOctString,
	(IPP_PROC)y8_ippsGFpECSetPointOctString,
	(IPP_PROC)e9_ippsGFpECSetPointOctString,
	(IPP_PROC)l9_ippsGFpECSetPointOctString,
	(IPP_PROC)n0_ippsGFpECSetPointOctString,
	(IPP_PROC)k0_ippsGFpECSetPointOctString,
	(IPP_PROC)k1_ippsGFpECSetPointOctString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetPointOctString,(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetPointOctString,(const Ipp8u* pStr, int strLen, IppsGFpECPoint* pPoint, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetPointOctString]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGetPointOctString(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetPointOctString,
	(IPP_PROC)m7_ippsGFpECGetPointOctString,
	(IPP_PROC)n8_ippsGFpECGetPointOctString,
	(IPP_PROC)y8_ippsGFpECGetPointOctString,
	(IPP_PROC)e9_ippsGFpECGetPointOctString,
	(IPP_PROC)l9_ippsGFpECGetPointOctString,
	(IPP_PROC)n0_ippsGFpECGetPointOctString,
	(IPP_PROC)k0_ippsGFpECGetPointOctString,
	(IPP_PROC)k1_ippsGFpECGetPointOctString
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetPointOctString,(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetPointOctString,(const IppsGFpECPoint* pPoint, Ipp8u* pStr, int strLen, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetPointOctString]
        jmp  rax
  }
};

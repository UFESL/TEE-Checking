#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const Ipp8u* pBuffer, IppsHMACState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus m7_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus n8_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus y8_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus e9_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus l9_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus n0_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus k0_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
extern IppStatus k1_ippsHMAC_Unpack(const Ipp8u* pBuffer, IppsHMACState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHMAC_Unpack,
	(IPP_PROC)m7_ippsHMAC_Unpack,
	(IPP_PROC)n8_ippsHMAC_Unpack,
	(IPP_PROC)y8_ippsHMAC_Unpack,
	(IPP_PROC)e9_ippsHMAC_Unpack,
	(IPP_PROC)l9_ippsHMAC_Unpack,
	(IPP_PROC)n0_ippsHMAC_Unpack,
	(IPP_PROC)k0_ippsHMAC_Unpack,
	(IPP_PROC)k1_ippsHMAC_Unpack
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHMAC_Unpack,(const Ipp8u* pBuffer, IppsHMACState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHMAC_Unpack,(const Ipp8u* pBuffer, IppsHMACState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHMAC_Unpack]
        jmp  rax
  }
};

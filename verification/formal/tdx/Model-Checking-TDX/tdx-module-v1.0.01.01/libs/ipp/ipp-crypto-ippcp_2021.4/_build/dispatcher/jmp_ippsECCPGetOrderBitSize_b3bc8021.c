#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int* pBitSize, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPGetOrderBitSize(int* pBitSize, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGetOrderBitSize,
	(IPP_PROC)m7_ippsECCPGetOrderBitSize,
	(IPP_PROC)n8_ippsECCPGetOrderBitSize,
	(IPP_PROC)y8_ippsECCPGetOrderBitSize,
	(IPP_PROC)e9_ippsECCPGetOrderBitSize,
	(IPP_PROC)l9_ippsECCPGetOrderBitSize,
	(IPP_PROC)n0_ippsECCPGetOrderBitSize,
	(IPP_PROC)k0_ippsECCPGetOrderBitSize,
	(IPP_PROC)k1_ippsECCPGetOrderBitSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGetOrderBitSize,(int* pBitSize, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGetOrderBitSize,(int* pBitSize, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGetOrderBitSize]
        jmp  rax
  }
};

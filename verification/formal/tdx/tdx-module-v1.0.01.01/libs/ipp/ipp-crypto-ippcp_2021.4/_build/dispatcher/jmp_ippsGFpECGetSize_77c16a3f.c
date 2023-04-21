#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGFp, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus m7_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus n8_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus y8_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus e9_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus l9_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus n0_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus k0_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
extern IppStatus k1_ippsGFpECGetSize(const IppsGFpState* pGFp, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetSize,
	(IPP_PROC)m7_ippsGFpECGetSize,
	(IPP_PROC)n8_ippsGFpECGetSize,
	(IPP_PROC)y8_ippsGFpECGetSize,
	(IPP_PROC)e9_ippsGFpECGetSize,
	(IPP_PROC)l9_ippsGFpECGetSize,
	(IPP_PROC)n0_ippsGFpECGetSize,
	(IPP_PROC)k0_ippsGFpECGetSize,
	(IPP_PROC)k1_ippsGFpECGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetSize,(const IppsGFpState* pGFp, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetSize,(const IppsGFpState* pGFp, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetSize]
        jmp  rax
  }
};

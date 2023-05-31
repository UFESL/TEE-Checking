#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGFp, int* pElementSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus m7_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus n8_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus y8_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus e9_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus l9_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus n0_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus k0_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
extern IppStatus k1_ippsGFpElementGetSize(const IppsGFpState* pGFp, int* pElementSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpElementGetSize,
	(IPP_PROC)m7_ippsGFpElementGetSize,
	(IPP_PROC)n8_ippsGFpElementGetSize,
	(IPP_PROC)y8_ippsGFpElementGetSize,
	(IPP_PROC)e9_ippsGFpElementGetSize,
	(IPP_PROC)l9_ippsGFpElementGetSize,
	(IPP_PROC)n0_ippsGFpElementGetSize,
	(IPP_PROC)k0_ippsGFpElementGetSize,
	(IPP_PROC)k1_ippsGFpElementGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpElementGetSize,(const IppsGFpState* pGFp, int* pElementSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpElementGetSize,(const IppsGFpState* pGFp, int* pElementSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpElementGetSize]
        jmp  rax
  }
};

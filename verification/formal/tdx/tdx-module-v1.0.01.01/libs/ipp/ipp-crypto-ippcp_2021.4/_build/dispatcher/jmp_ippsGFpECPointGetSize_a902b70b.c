#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpECState* pEC, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus m7_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus n8_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus y8_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus e9_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus l9_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus n0_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus k0_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
extern IppStatus k1_ippsGFpECPointGetSize(const IppsGFpECState* pEC, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECPointGetSize,
	(IPP_PROC)m7_ippsGFpECPointGetSize,
	(IPP_PROC)n8_ippsGFpECPointGetSize,
	(IPP_PROC)y8_ippsGFpECPointGetSize,
	(IPP_PROC)e9_ippsGFpECPointGetSize,
	(IPP_PROC)l9_ippsGFpECPointGetSize,
	(IPP_PROC)n0_ippsGFpECPointGetSize,
	(IPP_PROC)k0_ippsGFpECPointGetSize,
	(IPP_PROC)k1_ippsGFpECPointGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECPointGetSize,(const IppsGFpECState* pEC, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECPointGetSize,(const IppsGFpECState* pEC, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECPointGetSize]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus m7_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus n8_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus y8_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus e9_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus l9_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus n0_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus k0_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
extern IppStatus k1_ippsHashMethodGetInfo(IppsHashInfo* pInfo, const IppsHashMethod* pMethod);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsHashMethodGetInfo,
	(IPP_PROC)m7_ippsHashMethodGetInfo,
	(IPP_PROC)n8_ippsHashMethodGetInfo,
	(IPP_PROC)y8_ippsHashMethodGetInfo,
	(IPP_PROC)e9_ippsHashMethodGetInfo,
	(IPP_PROC)l9_ippsHashMethodGetInfo,
	(IPP_PROC)n0_ippsHashMethodGetInfo,
	(IPP_PROC)k0_ippsHashMethodGetInfo,
	(IPP_PROC)k1_ippsHashMethodGetInfo
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsHashMethodGetInfo,(IppsHashInfo* pInfo, const IppsHashMethod* pMethod))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsHashMethodGetInfo,(IppsHashInfo* pInfo, const IppsHashMethod* pMethod))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsHashMethodGetInfo]
        jmp  rax
  }
};

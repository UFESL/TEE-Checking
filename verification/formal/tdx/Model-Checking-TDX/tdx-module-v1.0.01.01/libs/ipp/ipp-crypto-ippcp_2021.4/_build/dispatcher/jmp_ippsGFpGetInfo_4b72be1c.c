#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpGetInfo(IppsGFpInfo* pInfo, const IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpGetInfo,
	(IPP_PROC)m7_ippsGFpGetInfo,
	(IPP_PROC)n8_ippsGFpGetInfo,
	(IPP_PROC)y8_ippsGFpGetInfo,
	(IPP_PROC)e9_ippsGFpGetInfo,
	(IPP_PROC)l9_ippsGFpGetInfo,
	(IPP_PROC)n0_ippsGFpGetInfo,
	(IPP_PROC)k0_ippsGFpGetInfo,
	(IPP_PROC)k1_ippsGFpGetInfo
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpGetInfo,(IppsGFpInfo* pInfo, const IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpGetInfo,(IppsGFpInfo* pInfo, const IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpGetInfo]
        jmp  rax
  }
};

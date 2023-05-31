#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGetInfo_GF(IppsGFpInfo* pInfo, const IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetInfo_GF,
	(IPP_PROC)m7_ippsGFpECGetInfo_GF,
	(IPP_PROC)n8_ippsGFpECGetInfo_GF,
	(IPP_PROC)y8_ippsGFpECGetInfo_GF,
	(IPP_PROC)e9_ippsGFpECGetInfo_GF,
	(IPP_PROC)l9_ippsGFpECGetInfo_GF,
	(IPP_PROC)n0_ippsGFpECGetInfo_GF,
	(IPP_PROC)k0_ippsGFpECGetInfo_GF,
	(IPP_PROC)k1_ippsGFpECGetInfo_GF
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetInfo_GF,(IppsGFpInfo* pInfo, const IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetInfo_GF,(IppsGFpInfo* pInfo, const IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetInfo_GF]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGFp, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECInitStd224r1(const IppsGFpState* pGFp, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECInitStd224r1,
	(IPP_PROC)m7_ippsGFpECInitStd224r1,
	(IPP_PROC)n8_ippsGFpECInitStd224r1,
	(IPP_PROC)y8_ippsGFpECInitStd224r1,
	(IPP_PROC)e9_ippsGFpECInitStd224r1,
	(IPP_PROC)l9_ippsGFpECInitStd224r1,
	(IPP_PROC)n0_ippsGFpECInitStd224r1,
	(IPP_PROC)k0_ippsGFpECInitStd224r1,
	(IPP_PROC)k1_ippsGFpECInitStd224r1
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECInitStd224r1,(const IppsGFpState* pGFp, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECInitStd224r1,(const IppsGFpState* pGFp, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECInitStd224r1]
        jmp  rax
  }
};

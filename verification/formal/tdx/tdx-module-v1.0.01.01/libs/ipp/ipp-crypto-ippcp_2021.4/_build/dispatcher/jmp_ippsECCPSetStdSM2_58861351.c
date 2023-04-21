#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetStdSM2(IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetStdSM2(IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetStdSM2,
	(IPP_PROC)m7_ippsECCPSetStdSM2,
	(IPP_PROC)n8_ippsECCPSetStdSM2,
	(IPP_PROC)y8_ippsECCPSetStdSM2,
	(IPP_PROC)e9_ippsECCPSetStdSM2,
	(IPP_PROC)l9_ippsECCPSetStdSM2,
	(IPP_PROC)n0_ippsECCPSetStdSM2,
	(IPP_PROC)k0_ippsECCPSetStdSM2,
	(IPP_PROC)k1_ippsECCPSetStdSM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetStdSM2,(IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetStdSM2,(IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetStdSM2]
        jmp  rax
  }
};

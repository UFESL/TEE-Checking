#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus m7_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus n8_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus y8_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus e9_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus l9_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus n0_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus k0_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
extern IppStatus k1_ippsECCPBindGxyTblStdSM2(IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)m7_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)n8_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)y8_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)e9_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)l9_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)n0_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)k0_ippsECCPBindGxyTblStdSM2,
	(IPP_PROC)k1_ippsECCPBindGxyTblStdSM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPBindGxyTblStdSM2,(IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPBindGxyTblStdSM2,(IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPBindGxyTblStdSM2]
        jmp  rax
  }
};

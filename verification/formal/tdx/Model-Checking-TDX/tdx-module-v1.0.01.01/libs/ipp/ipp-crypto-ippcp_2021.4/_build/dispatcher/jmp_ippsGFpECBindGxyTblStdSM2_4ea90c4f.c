#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECBindGxyTblStdSM2(IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)m7_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)n8_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)y8_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)e9_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)l9_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)n0_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)k0_ippsGFpECBindGxyTblStdSM2,
	(IPP_PROC)k1_ippsGFpECBindGxyTblStdSM2
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECBindGxyTblStdSM2,(IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECBindGxyTblStdSM2,(IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECBindGxyTblStdSM2]
        jmp  rax
  }
};

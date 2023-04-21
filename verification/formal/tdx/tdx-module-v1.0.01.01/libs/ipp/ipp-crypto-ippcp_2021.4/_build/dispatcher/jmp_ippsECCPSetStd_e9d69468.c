#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppECCType flag, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetStd(IppECCType flag, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetStd,
	(IPP_PROC)m7_ippsECCPSetStd,
	(IPP_PROC)n8_ippsECCPSetStd,
	(IPP_PROC)y8_ippsECCPSetStd,
	(IPP_PROC)e9_ippsECCPSetStd,
	(IPP_PROC)l9_ippsECCPSetStd,
	(IPP_PROC)n0_ippsECCPSetStd,
	(IPP_PROC)k0_ippsECCPSetStd,
	(IPP_PROC)k1_ippsECCPSetStd
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetStd,(IppECCType flag, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetStd,(IppECCType flag, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetStd]
        jmp  rax
  }
};

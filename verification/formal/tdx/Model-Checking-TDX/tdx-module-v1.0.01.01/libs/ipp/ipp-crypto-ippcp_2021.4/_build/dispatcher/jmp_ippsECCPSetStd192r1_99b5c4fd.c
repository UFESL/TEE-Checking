#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetStd192r1(IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetStd192r1(IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetStd192r1,
	(IPP_PROC)m7_ippsECCPSetStd192r1,
	(IPP_PROC)n8_ippsECCPSetStd192r1,
	(IPP_PROC)y8_ippsECCPSetStd192r1,
	(IPP_PROC)e9_ippsECCPSetStd192r1,
	(IPP_PROC)l9_ippsECCPSetStd192r1,
	(IPP_PROC)n0_ippsECCPSetStd192r1,
	(IPP_PROC)k0_ippsECCPSetStd192r1,
	(IPP_PROC)k1_ippsECCPSetStd192r1
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetStd192r1,(IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetStd192r1,(IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetStd192r1]
        jmp  rax
  }
};

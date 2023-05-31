#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int feBitSize, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPInit(int feBitSize, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPInit,
	(IPP_PROC)m7_ippsECCPInit,
	(IPP_PROC)n8_ippsECCPInit,
	(IPP_PROC)y8_ippsECCPInit,
	(IPP_PROC)e9_ippsECCPInit,
	(IPP_PROC)l9_ippsECCPInit,
	(IPP_PROC)n0_ippsECCPInit,
	(IPP_PROC)k0_ippsECCPInit,
	(IPP_PROC)k1_ippsECCPInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPInit,(int feBitSize, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPInit,(int feBitSize, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPInit]
        jmp  rax
  }
};

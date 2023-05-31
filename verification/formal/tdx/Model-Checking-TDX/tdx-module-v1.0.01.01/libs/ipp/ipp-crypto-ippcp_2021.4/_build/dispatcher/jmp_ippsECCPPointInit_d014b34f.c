#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int feBitSize, IppsECCPPointState* pPoint);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus m7_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus n8_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus y8_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus e9_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus l9_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus n0_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus k0_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
extern IppStatus k1_ippsECCPPointInit(int feBitSize, IppsECCPPointState* pPoint);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPPointInit,
	(IPP_PROC)m7_ippsECCPPointInit,
	(IPP_PROC)n8_ippsECCPPointInit,
	(IPP_PROC)y8_ippsECCPPointInit,
	(IPP_PROC)e9_ippsECCPPointInit,
	(IPP_PROC)l9_ippsECCPPointInit,
	(IPP_PROC)n0_ippsECCPPointInit,
	(IPP_PROC)k0_ippsECCPPointInit,
	(IPP_PROC)k1_ippsECCPPointInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPPointInit,(int feBitSize, IppsECCPPointState* pPoint))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPPointInit,(int feBitSize, IppsECCPPointState* pPoint))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPPointInit]
        jmp  rax
  }
};

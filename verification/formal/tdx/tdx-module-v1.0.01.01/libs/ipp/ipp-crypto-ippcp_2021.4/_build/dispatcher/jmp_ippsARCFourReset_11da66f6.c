#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsARCFourState* pCtx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus m7_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus n8_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus y8_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus e9_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus l9_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus n0_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus k0_ippsARCFourReset(IppsARCFourState* pCtx);
extern IppStatus k1_ippsARCFourReset(IppsARCFourState* pCtx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsARCFourReset,
	(IPP_PROC)m7_ippsARCFourReset,
	(IPP_PROC)n8_ippsARCFourReset,
	(IPP_PROC)y8_ippsARCFourReset,
	(IPP_PROC)e9_ippsARCFourReset,
	(IPP_PROC)l9_ippsARCFourReset,
	(IPP_PROC)n0_ippsARCFourReset,
	(IPP_PROC)k0_ippsARCFourReset,
	(IPP_PROC)k1_ippsARCFourReset
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsARCFourReset,(IppsARCFourState* pCtx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsARCFourReset,(IppsARCFourState* pCtx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsARCFourReset]
        jmp  rax
  }
};

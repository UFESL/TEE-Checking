#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPGet(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGet,
	(IPP_PROC)m7_ippsECCPGet,
	(IPP_PROC)n8_ippsECCPGet,
	(IPP_PROC)y8_ippsECCPGet,
	(IPP_PROC)e9_ippsECCPGet,
	(IPP_PROC)l9_ippsECCPGet,
	(IPP_PROC)n0_ippsECCPGet,
	(IPP_PROC)k0_ippsECCPGet,
	(IPP_PROC)k1_ippsECCPGet
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGet,(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGet,(IppsBigNumState* pPrime, IppsBigNumState* pA, IppsBigNumState* pB, IppsBigNumState* pGX,IppsBigNumState* pGY,IppsBigNumState* pOrder, int* cofactor, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGet]
        jmp  rax
  }
};

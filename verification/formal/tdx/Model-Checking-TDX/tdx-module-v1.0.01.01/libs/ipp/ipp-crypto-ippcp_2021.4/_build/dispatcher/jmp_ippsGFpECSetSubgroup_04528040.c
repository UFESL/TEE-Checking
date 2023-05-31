#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECSetSubgroup(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECSetSubgroup,
	(IPP_PROC)m7_ippsGFpECSetSubgroup,
	(IPP_PROC)n8_ippsGFpECSetSubgroup,
	(IPP_PROC)y8_ippsGFpECSetSubgroup,
	(IPP_PROC)e9_ippsGFpECSetSubgroup,
	(IPP_PROC)l9_ippsGFpECSetSubgroup,
	(IPP_PROC)n0_ippsGFpECSetSubgroup,
	(IPP_PROC)k0_ippsGFpECSetSubgroup,
	(IPP_PROC)k1_ippsGFpECSetSubgroup
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECSetSubgroup,(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECSetSubgroup,(const IppsGFpElement* pX, const IppsGFpElement* pY, const IppsBigNumState* pOrder, const IppsBigNumState* pCofactor, IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECSetSubgroup]
        jmp  rax
  }
};

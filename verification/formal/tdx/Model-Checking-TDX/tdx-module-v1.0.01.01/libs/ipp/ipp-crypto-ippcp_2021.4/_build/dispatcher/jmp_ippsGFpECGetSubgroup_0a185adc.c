#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus m7_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus n8_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus y8_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus e9_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus l9_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus n0_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus k0_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
extern IppStatus k1_ippsGFpECGetSubgroup(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECGetSubgroup,
	(IPP_PROC)m7_ippsGFpECGetSubgroup,
	(IPP_PROC)n8_ippsGFpECGetSubgroup,
	(IPP_PROC)y8_ippsGFpECGetSubgroup,
	(IPP_PROC)e9_ippsGFpECGetSubgroup,
	(IPP_PROC)l9_ippsGFpECGetSubgroup,
	(IPP_PROC)n0_ippsGFpECGetSubgroup,
	(IPP_PROC)k0_ippsGFpECGetSubgroup,
	(IPP_PROC)k1_ippsGFpECGetSubgroup
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECGetSubgroup,(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECGetSubgroup,(IppsGFpState** const ppGFp, IppsGFpElement* pX, IppsGFpElement* pY, IppsBigNumState* pOrder,IppsBigNumState* pCofactor, const IppsGFpECState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECGetSubgroup]
        jmp  rax
  }
};

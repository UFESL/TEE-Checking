#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpAdd(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpAdd,
	(IPP_PROC)m7_ippsGFpAdd,
	(IPP_PROC)n8_ippsGFpAdd,
	(IPP_PROC)y8_ippsGFpAdd,
	(IPP_PROC)e9_ippsGFpAdd,
	(IPP_PROC)l9_ippsGFpAdd,
	(IPP_PROC)n0_ippsGFpAdd,
	(IPP_PROC)k0_ippsGFpAdd,
	(IPP_PROC)k1_ippsGFpAdd
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpAdd,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpAdd,(const IppsGFpElement* pA, const IppsGFpElement* pB, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpAdd]
        jmp  rax
  }
};

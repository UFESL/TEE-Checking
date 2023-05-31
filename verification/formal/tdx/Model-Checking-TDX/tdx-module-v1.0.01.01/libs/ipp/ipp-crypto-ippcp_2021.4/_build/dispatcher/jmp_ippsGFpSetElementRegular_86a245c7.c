#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus m7_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n8_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus y8_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus e9_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus l9_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus n0_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k0_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
extern IppStatus k1_ippsGFpSetElementRegular(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpSetElementRegular,
	(IPP_PROC)m7_ippsGFpSetElementRegular,
	(IPP_PROC)n8_ippsGFpSetElementRegular,
	(IPP_PROC)y8_ippsGFpSetElementRegular,
	(IPP_PROC)e9_ippsGFpSetElementRegular,
	(IPP_PROC)l9_ippsGFpSetElementRegular,
	(IPP_PROC)n0_ippsGFpSetElementRegular,
	(IPP_PROC)k0_ippsGFpSetElementRegular,
	(IPP_PROC)k1_ippsGFpSetElementRegular
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpSetElementRegular,(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpSetElementRegular,(const IppsBigNumState* pBN, IppsGFpElement* pR, IppsGFpState* pGFp))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpSetElementRegular]
        jmp  rax
  }
};

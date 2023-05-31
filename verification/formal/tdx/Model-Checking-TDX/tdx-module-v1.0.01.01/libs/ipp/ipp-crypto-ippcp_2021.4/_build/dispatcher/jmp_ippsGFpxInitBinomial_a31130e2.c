#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus m7_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus n8_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus y8_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus e9_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus l9_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus n0_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus k0_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus k1_ippsGFpxInitBinomial(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpxInitBinomial,
	(IPP_PROC)m7_ippsGFpxInitBinomial,
	(IPP_PROC)n8_ippsGFpxInitBinomial,
	(IPP_PROC)y8_ippsGFpxInitBinomial,
	(IPP_PROC)e9_ippsGFpxInitBinomial,
	(IPP_PROC)l9_ippsGFpxInitBinomial,
	(IPP_PROC)n0_ippsGFpxInitBinomial,
	(IPP_PROC)k0_ippsGFpxInitBinomial,
	(IPP_PROC)k1_ippsGFpxInitBinomial
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpxInitBinomial,(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpxInitBinomial,(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* pGroundElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpxInitBinomial]
        jmp  rax
  }
};

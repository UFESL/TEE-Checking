#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus m7_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus n8_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus y8_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus e9_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus l9_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus n0_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus k0_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
extern IppStatus k1_ippsGFpxInit(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpxInit,
	(IPP_PROC)m7_ippsGFpxInit,
	(IPP_PROC)n8_ippsGFpxInit,
	(IPP_PROC)y8_ippsGFpxInit,
	(IPP_PROC)e9_ippsGFpxInit,
	(IPP_PROC)l9_ippsGFpxInit,
	(IPP_PROC)n0_ippsGFpxInit,
	(IPP_PROC)k0_ippsGFpxInit,
	(IPP_PROC)k1_ippsGFpxInit
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpxInit,(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpxInit,(const IppsGFpState* pGroundGF, int extDeg, const IppsGFpElement* const ppGroundElm[], int nElm, const IppsGFpMethod* pGFpMethod, IppsGFpState* pGFpx))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpxInit]
        jmp  rax
  }
};

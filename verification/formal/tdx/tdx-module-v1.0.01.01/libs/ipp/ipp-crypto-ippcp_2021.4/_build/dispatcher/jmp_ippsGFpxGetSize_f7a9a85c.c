#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsGFpState* pGroundGF, int degree, int* pSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus m7_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus n8_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus y8_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus e9_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus l9_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus n0_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus k0_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
extern IppStatus k1_ippsGFpxGetSize(const IppsGFpState* pGroundGF, int degree, int* pSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpxGetSize,
	(IPP_PROC)m7_ippsGFpxGetSize,
	(IPP_PROC)n8_ippsGFpxGetSize,
	(IPP_PROC)y8_ippsGFpxGetSize,
	(IPP_PROC)e9_ippsGFpxGetSize,
	(IPP_PROC)l9_ippsGFpxGetSize,
	(IPP_PROC)n0_ippsGFpxGetSize,
	(IPP_PROC)k0_ippsGFpxGetSize,
	(IPP_PROC)k1_ippsGFpxGetSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpxGetSize,(const IppsGFpState* pGroundGF, int degree, int* pSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpxGetSize,(const IppsGFpState* pGroundGF, int degree, int* pSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpxGetSize]
        jmp  rax
  }
};

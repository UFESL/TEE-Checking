#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPMulPointScalar(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPMulPointScalar,
	(IPP_PROC)m7_ippsECCPMulPointScalar,
	(IPP_PROC)n8_ippsECCPMulPointScalar,
	(IPP_PROC)y8_ippsECCPMulPointScalar,
	(IPP_PROC)e9_ippsECCPMulPointScalar,
	(IPP_PROC)l9_ippsECCPMulPointScalar,
	(IPP_PROC)n0_ippsECCPMulPointScalar,
	(IPP_PROC)k0_ippsECCPMulPointScalar,
	(IPP_PROC)k1_ippsECCPMulPointScalar
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPMulPointScalar,(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPMulPointScalar,(const IppsECCPPointState* pP, const IppsBigNumState* pK, IppsECCPPointState* pR, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPMulPointScalar]
        jmp  rax
  }
};

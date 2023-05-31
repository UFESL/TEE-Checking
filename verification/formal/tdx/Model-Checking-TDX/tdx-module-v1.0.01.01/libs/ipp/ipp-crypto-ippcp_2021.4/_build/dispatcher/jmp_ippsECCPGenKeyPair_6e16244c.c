#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus m7_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n8_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus y8_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus e9_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus l9_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus n0_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k0_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
extern IppStatus k1_ippsECCPGenKeyPair(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPGenKeyPair,
	(IPP_PROC)m7_ippsECCPGenKeyPair,
	(IPP_PROC)n8_ippsECCPGenKeyPair,
	(IPP_PROC)y8_ippsECCPGenKeyPair,
	(IPP_PROC)e9_ippsECCPGenKeyPair,
	(IPP_PROC)l9_ippsECCPGenKeyPair,
	(IPP_PROC)n0_ippsECCPGenKeyPair,
	(IPP_PROC)k0_ippsECCPGenKeyPair,
	(IPP_PROC)k1_ippsECCPGenKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPGenKeyPair,(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPGenKeyPair,(IppsBigNumState* pPrivate, IppsECCPPointState* pPublic, IppsECCPState* pEC, IppBitSupplier rndFunc, void* pRndParam))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPGenKeyPair]
        jmp  rax
  }
};

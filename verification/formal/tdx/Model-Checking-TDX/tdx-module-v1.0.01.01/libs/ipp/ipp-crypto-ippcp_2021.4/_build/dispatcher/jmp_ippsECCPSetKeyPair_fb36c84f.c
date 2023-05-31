#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus m7_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus n8_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus y8_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus e9_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus l9_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus n0_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus k0_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
extern IppStatus k1_ippsECCPSetKeyPair(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsECCPSetKeyPair,
	(IPP_PROC)m7_ippsECCPSetKeyPair,
	(IPP_PROC)n8_ippsECCPSetKeyPair,
	(IPP_PROC)y8_ippsECCPSetKeyPair,
	(IPP_PROC)e9_ippsECCPSetKeyPair,
	(IPP_PROC)l9_ippsECCPSetKeyPair,
	(IPP_PROC)n0_ippsECCPSetKeyPair,
	(IPP_PROC)k0_ippsECCPSetKeyPair,
	(IPP_PROC)k1_ippsECCPSetKeyPair
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsECCPSetKeyPair,(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsECCPSetKeyPair,(const IppsBigNumState* pPrivate, const IppsECCPPointState* pPublic, IppBool regular, IppsECCPState* pEC))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsECCPSetKeyPair]
        jmp  rax
  }
};

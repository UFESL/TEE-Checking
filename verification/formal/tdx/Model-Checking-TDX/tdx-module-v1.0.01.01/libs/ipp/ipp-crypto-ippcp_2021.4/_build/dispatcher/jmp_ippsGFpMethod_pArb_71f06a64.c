#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const IppsGFpMethod* (*IPP_PROC)(void);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const IppsGFpMethod* in_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* m7_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* n8_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* y8_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* e9_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* l9_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* n0_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* k0_ippsGFpMethod_pArb(void);
extern  const IppsGFpMethod* k1_ippsGFpMethod_pArb(void);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpMethod_pArb,
	(IPP_PROC)m7_ippsGFpMethod_pArb,
	(IPP_PROC)n8_ippsGFpMethod_pArb,
	(IPP_PROC)y8_ippsGFpMethod_pArb,
	(IPP_PROC)e9_ippsGFpMethod_pArb,
	(IPP_PROC)l9_ippsGFpMethod_pArb,
	(IPP_PROC)n0_ippsGFpMethod_pArb,
	(IPP_PROC)k0_ippsGFpMethod_pArb,
	(IPP_PROC)k1_ippsGFpMethod_pArb
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const IppsGFpMethod*, ippsGFpMethod_pArb,(void))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const IppsGFpMethod*, in_ippsGFpMethod_pArb,(void))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpMethod_pArb]
        jmp  rax
  }
};

#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef  const IppsGFpMethod* (*IPP_PROC)(void);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern  const IppsGFpMethod* in_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* m7_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* n8_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* y8_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* e9_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* l9_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* n0_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* k0_ippsGFpxMethod_com(void);
extern  const IppsGFpMethod* k1_ippsGFpxMethod_com(void);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpxMethod_com,
	(IPP_PROC)m7_ippsGFpxMethod_com,
	(IPP_PROC)n8_ippsGFpxMethod_com,
	(IPP_PROC)y8_ippsGFpxMethod_com,
	(IPP_PROC)e9_ippsGFpxMethod_com,
	(IPP_PROC)l9_ippsGFpxMethod_com,
	(IPP_PROC)n0_ippsGFpxMethod_com,
	(IPP_PROC)k0_ippsGFpxMethod_com,
	(IPP_PROC)k1_ippsGFpxMethod_com
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI( const IppsGFpMethod*, ippsGFpxMethod_com,(void))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI( const IppsGFpMethod*, in_ippsGFpxMethod_com,(void))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpxMethod_com]
        jmp  rax
  }
};

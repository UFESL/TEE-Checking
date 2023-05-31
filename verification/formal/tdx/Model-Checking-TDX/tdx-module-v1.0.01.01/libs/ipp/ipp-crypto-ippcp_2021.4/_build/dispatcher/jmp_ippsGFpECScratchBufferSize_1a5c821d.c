#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus m7_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus n8_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus y8_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus e9_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus l9_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus n0_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus k0_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
extern IppStatus k1_ippsGFpECScratchBufferSize(int nScalars, const IppsGFpECState* pEC, int* pBufferSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpECScratchBufferSize,
	(IPP_PROC)m7_ippsGFpECScratchBufferSize,
	(IPP_PROC)n8_ippsGFpECScratchBufferSize,
	(IPP_PROC)y8_ippsGFpECScratchBufferSize,
	(IPP_PROC)e9_ippsGFpECScratchBufferSize,
	(IPP_PROC)l9_ippsGFpECScratchBufferSize,
	(IPP_PROC)n0_ippsGFpECScratchBufferSize,
	(IPP_PROC)k0_ippsGFpECScratchBufferSize,
	(IPP_PROC)k1_ippsGFpECScratchBufferSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpECScratchBufferSize,(int nScalars, const IppsGFpECState* pEC, int* pBufferSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpECScratchBufferSize,(int nScalars, const IppsGFpECState* pEC, int* pBufferSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpECScratchBufferSize]
        jmp  rax
  }
};

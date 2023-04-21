#include "ippcp.h"

#pragma warning(disable : 1478 1786) // deprecated

typedef IppStatus (*IPP_PROC)(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);

extern int ippcpJumpIndexForMergedLibs;
extern IppStatus ippcpSafeInit( void );

extern IppStatus in_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus m7_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus n8_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus y8_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus e9_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus l9_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus n0_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus k0_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
extern IppStatus k1_ippsGFpScratchBufferSize(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize);
static IPP_PROC arraddr[] =
{
	(IPP_PROC)in_ippsGFpScratchBufferSize,
	(IPP_PROC)m7_ippsGFpScratchBufferSize,
	(IPP_PROC)n8_ippsGFpScratchBufferSize,
	(IPP_PROC)y8_ippsGFpScratchBufferSize,
	(IPP_PROC)e9_ippsGFpScratchBufferSize,
	(IPP_PROC)l9_ippsGFpScratchBufferSize,
	(IPP_PROC)n0_ippsGFpScratchBufferSize,
	(IPP_PROC)k0_ippsGFpScratchBufferSize,
	(IPP_PROC)k1_ippsGFpScratchBufferSize
};
#undef  IPPAPI
#define IPPAPI(type,name,arg) __declspec(naked) type name arg
IPPAPI(IppStatus, ippsGFpScratchBufferSize,(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize))
{
    register unsigned long long i __asm__("rax");
    i = (unsigned long long)arraddr[ippcpJumpIndexForMergedLibs+1];
    _asm{ jmp rax }
};
IPPAPI(IppStatus, in_ippsGFpScratchBufferSize,(int nExponents, int ExpBitSize, const IppsGFpState* pGFp, int* pBufferSize))
{
   __asm{
        call ippcpSafeInit
        mov  rax, qword ptr [ippsGFpScratchBufferSize]
        jmp  rax
  }
};

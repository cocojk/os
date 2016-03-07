#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "/usr/cross/lib/gcc/x86_64-pc-linux/4.8.2/include/stdarg.h"
#include "Types.h"

// 매크로 
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)<(y))?(x):(y))

// 함수
void kMemSet(void* pvDestination, BYTE bData, int iSize);
int kMemCpy(void* pvDestination,const void* pvSource,int iSize);
int kMemCmp(const void* pvDestination,const void* pvSource,int iSize);
BOOL kSetInterruptFlag(BOOL bEnableInterrupt);
void kCheckTotalRAMSize(void);
QWORD kGetTotalRAMSize(void);
void kReverseString(char* pcBuffer);
long kAToI(const char* pcBuffer,int iRadix);
QWORD kHexStringToQword(const char* pcBuffer);
long kDecimalStringToLong(const char* pcBuffer);
int kIToA(long lvalue,char* pcBuffer,int iRadix);
int kHexToString(QWORD qwValue,char* Buffer);
int kDecimalTostring(long lValue,char* pcBuffer);
int kSPrintf(char* pcBuffer,const char* pcFormatString,...);
int kVSPrintf(char* pcBuffer,const char* pcFormatString,va_list ap);
QWORD kGetTickCount(void);
void kSleep(QWORD qwMillisecond);

// 변수
extern volatile QWORD g_qwTickCount;
#endif /*__UTILITY_H__*/

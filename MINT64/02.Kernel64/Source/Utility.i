# 1 "Utility.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "Utility.h"



# 1 "/usr/cross/lib/gcc/x86_64-pc-linux/4.4.5/include/stdarg.h" 1
# 40 "/usr/cross/lib/gcc/x86_64-pc-linux/4.4.5/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
# 102 "/usr/cross/lib/gcc/x86_64-pc-linux/4.4.5/include/stdarg.h"
typedef __gnuc_va_list va_list;
# 5 "Utility.h" 2
# 1 "Types.h" 1
# 17 "Types.h"
#pragma pack(push,1)

typedef struct kCharactorStruct
{
 unsigned char bCharactor;
 unsigned char bAttribute;
} CHARACTER;

#pragma pack(pop)
# 6 "Utility.h" 2






void kMemSet(void* pvDestination, unsigned char bData, int iSize);
int kMemCpy(void* pvDestination,const void* pvSource,int iSize);
int kMemCmp(const void* pvDestination,const void* pvSource,int iSize);
unsigned char kSetInterruptFlag(unsigned char bEnableInterrupt);
void kCheckTotalRAMSize(void);
unsigned long kGetTotalRAMSize(void);
void kReverseString(char* pcBuffer);
long kAToI(const char* pcBuffer,int iRadix);
unsigned long kHexStringToQword(const char* pcBuffer);
long kDecimalStringToLong(const char* pcBuffer);
int kIToA(long lvalue,char* pcBuffer,int iRadix);
int kHexToString(unsigned long qwValue,char* Buffer);
int kDecimalTostring(long lValue,char* pcBuffer);
int kSPrintf(char* pcBuffer,const char* pcFormatString,...);
int kVSPrintf(char* pcBuffer,const char* pcFormatString,va_list ap);
unsigned long kGetTickCount(void);
void kSleep(unsigned long qwMillisecond);
inline void kMemSetWord(void* pvDestination,unsigned short wData,int iWordSize);



extern volatile unsigned long g_qwTickCount;

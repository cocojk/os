#ifndef __SYNCHRONIZATION_H__
#define __SYNCHRONIZATION_H__

#include "Types.h"

// 구조체 
// 1바이트로 정렬 
#pragma pack(push,1)

// 뮤텍스 자료구조 
typedef struct kMutextStruct
{
	// 태스크 ID와 잠금을 수행한 횟수 
	volatile QWORD qwTaskID;
	volatile DWORD dwLockCount;

	// 잠금 플래그
	volatile BOOL bLockFlag;

	// 자료구조의 크기를 8바이트 단위로 맞추려고 추가한 필드 
	BYTE vbPadding[3];
} MUTEX;

// 스핀락 자료구조 
typedef struct kSpinLockStrcut
{
	// 로컬 APIC ID와 잠금을 수행한 횟수 
	volatile DWORD dwLockCount;
	volatile BYTE bAPICID;

	// 잠금 플래그 
	volatile BOOL bLockFlag;

	// 인터럽트 플래그 
	volatile BOOL bInterruptFlag;

	// 자료구조의 크기를 8바이트 단위로 맞추려고 추가한 필드 
	BYTE bvPadding[1];
} SPINLOCK;

#pragma pack(pop)

// 함수
#if 0
BOOL kLockForSystemData(void);
void kUnlockForSystemData(BOOL bInterruptFlag);
#endif

void kInitializeMutex(MUTEX* pstMutex);
void kLock(MUTEX* pstMutex);
void kUnlock(MUTEX* pstMutex);

void kInitializeSpinLock(SPINLOCK* pstSpinLock);
void kLockForSpinLock(SPINLOCK* pstSpinLock);
void kUnlockForSpinLock(SPINLOCK* pstSpinLock);

#endif /*__SYNCHRONIZATION_H__*/
#ifndef __PAGE_H__
#define __PAGE_H__

#include "Types.h"

// 매크로
#define PAGE_FLAGS_P	0x00000001		// Present
#define PAGE_FLAGS_RW	0x00000002		// Read/Write
#define PAGE_FLAGS_US	0x00000004		// User/Supervisor(플래그 설정시 유저 레벨)
#define PAGE_FLAGS_PWT	0x00000008		// Page level write-through
#define PAGE_FLAGS_PCD	0x00000010		// Page level cache disable
#define PAGE_FLAGS_A	0x00000020		// accessed
#define PAGE_FLAGS_D	0x00000040		// Dirty
#define PAGE_FLAGS_PS	0x00000080		// Page Size
#define PAGE_FLAGS_G	0x00000100		// Global
#define PAGE_FLAGS_PAT	0x00001000		// Page Attribute Table Index
#define PAGE_FLAGS_EXB	0x80000000		// Execute Disable 비트
#define PAGE_FLAGS_DEFAULT	(PAGE_FLAGS_P | PAGE_FLAGS_RW)
#define PAGE_TABLESIZE	0x1000
#define PAGE_MAXENTRYCOUNT	512
#define PAGE_DEFAULTSIZE	0x200000

// 구조체
// 기존의 바이트 기준을 스택에 push 해준 다음에, 1바이트 단위로 처리한 다음 끝나는 부분에서 원래의 바이트 단위를 pop 해준다는 의미
#pragma pack (push,1)

typedef struct kPageTableEntryStruct
{
	// PML4T와 PDPTE의 경우
	// 1비트 P,RW,US,PWT,PCD,A 3비트 reserved 3비트 avail, 20비트 base address
	// PDE의 경우 
	// 1비트 P,RW,US,PWT,PCD,A,D,PS,G, 3비트 avail, 1비트 PAT, 8비트 Avail, 11비트 base address
	DWORD dwAttributeAndLowerBaseAddress;
	// 8비트 Upper BaseAddress, 12비트 reserved, 11비트 avail, 1비트 EXB
	DWORD dwUpperBaseAddressAndEXB;
} PML4ENTRY,PDPTENTRY,PDENTRY,PTENTRY;

#pragma pack (pop)

// 함수
void kInitializePageTables(void);
void kSetPageEntryData(PTENTRY* pstEntry, DWORD dwUpperBaseAddress, DWORD dwLowerBaseAddess,DWORD dwLowerFlags, DWORD dwUpperFlags);

#endif /*__PAGE_H__*/

#ifndef __TYPES_H__
#define __TYPES_H__

#define BYTE	unsigned char
#define WORD	unsigned short
#define DWORD	unsigned int
#define QWORD	unsigned long
#define BOOL	unsigned char

#define TRUE	1
#define FALSE	0
#define NULL	0

// stddef.h 헤더에 포함된 offsetof() 매크로의 내용 
#define offsetof(TYPE,MEMBER) __builtin_offsetof(TYPE,MEMBER)

#pragma pack(push,1)

typedef struct kCharactorStruct
{
	BYTE bCharactor;
	BYTE bAttribute;
} CHARACTER;

#pragma pack(pop)
// pragma pack은 구조체의 크기 정렬에 관련된 지시어로 구조체의 크기를 1바이트로 정렬하여 추가적인 메모리 공간을 더 할당하지 않게합니다.

#endif /*__TYPES_H__*/


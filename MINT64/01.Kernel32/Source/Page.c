#include "Page.h"

// IA-32e 모드 커널을 위한 페이지 테이블 생성
void kInitializePageTables(void)
{
	PML4ENTRY* pstPML4Entry;
	PDPTENTRY* pstPDPTEntry;
	PDENTRY* pstPDEntry;
	DWORD dwMappingAddress;
	int i;

	// PML4 테이블 생성
	// 첫 번째 엔트리 외에 나머지 모두 0으로 초기화
	// PML4와 PDPTE의 경우 13번째 비트부터 base address가 된다. 또한 이 테이블의 크기는 4KB이기 때문에 상위 13비트만 의미가 있는 숫자가 된다.(4KB단위로 잘려지기 때문에 0x101000 0x102000 0x103000와 같은 물리주소를 갖게된다. 따라서 하위 12비트는 저장할 이유가 없다.)
	// 따라서 LowerAddress에 0x101000과 같이 물리 주소 그대로 넣어주게되면, 하위 12비트는 attribute비트로 처리가 되는데, 0x000의 값을 갖고  상위 13비트부터는 base address(4KB가 곱해져야하는)가 되게 된다. 위 예제 0x101000 0x102000 0x103000의 경우 상위 13비트 즉, 0x101,0x102,0x103이 base address에 저장된다.
	pstPML4Entry = (PML4ENTRY*)0x100000;
	kSetPageEntryData(&(pstPML4Entry[0]),0x00,0x101000,PAGE_FLAGS_DEFAULT,0);
	for(i=1;i<PAGE_MAXENTRYCOUNT;i++)
	{
		kSetPageEntryData(&(pstPML4Entry[i]),0,0,0,0);


	}

	// 페이지 디렉터리 포인터 테이블 생성
	// 하나의 PDPT로 512GB까지 매핑 가능하므로 하나로 충분함
	// 64개의 엔트리로 설정하여 64GB까지 매핑함
	pstPDPTEntry =(PDPTENTRY*)0x101000;
	for(i=0;i<64;i++)
	{
		kSetPageEntryData(&(pstPDPTEntry[i]),0,0x102000+(i*PAGE_TABLESIZE),PAGE_FLAGS_DEFAULT,0);
	}

	for(i=64;i<PAGE_MAXENTRYCOUNT;i++)
	{
		kSetPageEntryData(&(pstPDPTEntry[i]),0,0,0,0);
	}

	// 페이지 디렉터리 테이블 생성
	// 하나의 페이지 디렉터리가 1GB까지 매핑 가능 
	// 여유있게 64개의 디렉터리를 생성하여 총 64GB까지 지원
	// PDE의 경우 21번째비트부터 base address가 된다. 왜냐하면 우리는 2MB 페이징을 쓰기 때문에, 물리 주소가 0x200000 0x400000 0x600000 와 같은 단위로 잘려지게 된다. 따라서 22번쨰비트부터 값이 변하는 의미있는 비트가 된다. (모두 짝수이기때문에 21번째 비트는 0으로 고정되기때문) 
	// 따라서 LowerAddress에 0x200000같은 물리 주소를 그대로 넣어주게되면, 하위 21비트는 attribute비트로 처리가 되는데, 0x000000의 값을 갖고 상위 22비트부터는 base address(2MB가 곱해져야하는)가 되게 된다. 위 예제 0x200000 0x400000 0x600000의 경우 상위 22비트부터 즉, 0x01 0x02 0x03이 base address에 저장된다.
	pstPDEntry=(PDENTRY*)0x102000;
	dwMappingAddress=0;

	
	for(i=0;i<PAGE_MAXENTRYCOUNT*64;i++)
	{
		// 32비트로는 상위 어드레스를 표현할 수 없으므로, MB 단위로 계산한 다음 최종 결과를 다시 4KB로 나누어 32비트 이상의 어드레스를 계산함
		kSetPageEntryData(&(pstPDEntry[i]),(i*(PAGE_DEFAULTSIZE>>20))>>12,dwMappingAddress,PAGE_FLAGS_DEFAULT|PAGE_FLAGS_PS,0);
		dwMappingAddress+=PAGE_DEFAULTSIZE;
	}
}


// 페이지 엔트리에 기준 주소와 속성 플래그 설정
void kSetPageEntryData(PTENTRY* pstEntry,DWORD dwUpperBaseAddress,DWORD dwLowerBaseAddress,DWORD dwLowerFlags,DWORD dwUpperFLAGS)
{
	pstEntry->dwAttributeAndLowerBaseAddress = dwLowerBaseAddress | dwLowerFlags;
	pstEntry->dwUpperBaseAddressAndEXB =(dwUpperBaseAddress&0xFF)|dwUpperFLAGS;
}


	

all: VirtualOS.bin

VirtualOS.bin: Source/EntryPoint.s
	nasm -o Kernel32.bin $< 

clean:
	rm -f VirtualOS.bin

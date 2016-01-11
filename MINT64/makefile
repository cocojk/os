all: BootLoader Kernel32 Kernel64 Utility Disk.img

BootLoader:
	@echo
	@echo =============== Build Boot Loader ======================== 
	@echo
	
	make -C 00.BootLoader

	@echo
	@echo =================  Build complete ========================
	@echo


Kernel32:
	@echo
	@echo =============== Build 32bit kernel =======================
	@echo

	make -C 01.Kernel32

	@echo 
	@echo =============== Build Complete ===========================
	@echo

Kernel64:
	@echo
	@echo =============== Build 64bit kernel =======================
	@echo

	make -C 02.Kernel64

	@echo 
	@echo =============== Build Complete ===========================
	@echo

Utility:
	@echo
	@echo =============== Build Utility =======================
	@echo

	make -C 04.Utility
	

	@echo 
	@echo =============== Build Complete ===========================
	@echo


Disk.img: 00.BootLoader/BootLoader.bin 01.Kernel32/Kernel32.bin 02.Kernel64/Kernel64.bin 
	@echo
	@echo =============== Disk Image Build Start ===================
	@echo

	04.Utility/00.ImageMaker/ImageMaker $^
	
	# dependency에 나열된 전체 파일을 의미 

	@echo
	@echo ================ All Build Complete ======================
	@echo



clean:
	make -C 00.BootLoader clean
	make -C 01.Kernel32 clean
	make -C 02.Kernel64 clean 
	make -C 04.Utility clean
	rm -f Disk.img

all: BootLoader Disk.img

BootLoader:
	@echo
	@echo =============== Build Boot Loader ======================== 
	@echo
	
	make -C 00.BootLoader

	@echo
	@echo =================  Build complete ========================
	@echo


# Kernel32:
#	@echo
#	@echo =============== Build 32bit kernel =======================
#	@echo
#
#	make -C 01.Kernel32
#
#	@echo 
#	@echo =============== Build Complete ===========================
#	@echo



Disk.img: 00.BootLoader/BootLoader.bin
	@echo
	@echo =============== Disk Image Build Start ===================
	@echo

	cp 00.BootLoader/BootLoader.bin Disk.img

	@echo
	@echo ================ All Build Complete ======================
	@echo

clean:
	make -C 00.BootLoader clean
#	make -C 01.Kernel32 clean
	rm -f Disk.img

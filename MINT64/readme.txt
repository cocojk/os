qemu-system-x86_64 -L . -m 64 -fda Disk.img -localtime -M pc
git add MINT64
git commit -m "message"
git push -u origin master
objdump -D -b binary -mi386 -Maddr16,data16 /usr/mdec/mbri

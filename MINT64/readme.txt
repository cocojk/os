qemu-system-x86_64 -L . -m 64 -fda Disk.img -hda HDD.img -boot a -localtime -M pc
qemu-system-x86_64 -L . -m 64 -fda Disk.img -hda HDD.img -boot a -localtime -M pc -serial tcp::4444,server,nowait
git add MINT64
git commit -m "message"
git push -u origin master
objdump -D -b binary -mi386 -Maddr16,data16 /usr/mdec/mbri
this is a test for my ipad

#!/bin/bash

gcc -I/usr/include/efi -I/usr/include/efi/x86_64 \
    -DGNU_EFI_USE_MS_ABI -Dx86_64 \
    -fPIC -fshort-wchar -ffreestanding -fno-stack-protector -maccumulate-outgoing-args \
    -Wall -Werror \
    -m64 -mno-red-zone \
    -c -o DisablePROCHOT.o DisablePROCHOT.c

ld -T /usr/lib/elf_x86_64_efi.lds -Bsymbolic -shared -nostdlib -znocombreloc \
    /usr/lib/crt0-efi-x86_64.o \
    -o DisablePROCHOT.so DisablePROCHOT.o \
    $(gcc -print-libgcc-file-name) /usr/lib/libgnuefi.a

objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel \
        -j .rela -j .reloc -S --target=efi-app-x86_64 DisablePROCHOT.so DisablePROCHOT.efi

ls -l DisablePROCHOT.efi
md5sum DisablePROCHOT.efi

# HelOS

## Introduction

This is a discovery project of OS Developement

The documentation I use : [osDev](https://wiki.osdev.org)

I plan to rebuild everything on this except XORG and everything that is referenced inside `stddef.h` and `stdint.h`

## Running the "OS"

### Compilation and linking

To use this OS the first thing you need is a cross compiler

I would highly recommend you to use [i686-elf from GCC](https://wiki.osdev.org/GCC_Cross-Compiler)

If you want to use something else please make sure to remove in `kernel.c` :

```c
#if defined(__linux__)
    #error "This code must be compiled with a cross-compiler"
#elif !defined(__i386__)
        #error "This code must be compiled with an x86-elf compiler"
#endif
```
And to change it by what you prefer but keep in mind that the project will keep with a 32bit UNIX like kernel

To compile everything make sure to i386-elf and run :

```sh
i686-elf-gcc -std=gnu99 -ffreestanding -g -c start.s -o start.o
i686-elf-gcc -std=gnu99 -ffreestanding -g -c kernel.c -o kernel.o
i686-elf-gcc -ffreestanding -nostdlib -g -T linker.ld start.o kernel.o -o mykernel.elf -lgcc
```

### Launch it with QEMU

After all of this you should get a mykernel.elf image

Run this command after installing QEMU

```sh
qemu-system-i386 -kernel mykernel.elf image
```

If you don't see the messages from term_print you must have failed something while compiling the kernel

If you are sure of what you've done please contact me

## Information

This kernel is not meant for now to be tested on real hardware as i did not implement a bootloader

I'm gonna for now use grub and I might see if I implement my own

This kernel only support printing trough the c file and need to be compiled to work it is not meant for now to be used and might never be

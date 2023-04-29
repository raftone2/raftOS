# $@ = target file
# $< = first dependency
# $^ = all dependencies

C_SOURCES = $(wildcard kernel/*.c kernel/*/*.c drivers/*/*.c)
S_SOURCES = $(wildcard kernel/*/*.s)
HEADERS = $(wildcard kernel/*.h, drivers/*/*.h)
C_OBJ = ${C_SOURCES:.c=.o} 
S_OBJ = ${S_SOURCES:.s=.o} 

all: run

products/kernel.bin: products/kernel_entry.o ${C_OBJ} ${S_OBJ}
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

products/kernel_entry.o: boot/kernel_entry.s
	nasm $< -f elf -o $@

#products/kernel.o: kernel/kernel.c
#	i386-elf-gcc -std=c11 -ffreestanding -c $< -o $@

%.o: %.c ${HEADERS}
	i386-elf-gcc -std=c11 -ffreestanding -c $< -o $@

%.o: %.s
	nasm $< -f elf -o $@

debug/kernel.dis: products/kernel.bin
	ndisasm -b 32 $< > $@

products/boot.bin: boot/boot.s
	nasm $< -f bin -o $@

products/os-image.bin: products/boot.bin products/kernel.bin
	cat $^ > $@

run: products/os-image.bin
	qemu-system-i386 -fda $<

clean:
	rm -rf products/*.bin products/*.o debug/*.dis
	rm -rf kernel/*.bin kernel/*.o kernel/*.dis
	rm -rf kernel/*/*.bin kernel/*/*.o kernel/*/*.dis
	rm -rf drivers/*/*.bin drivers/*/*.o drivers/*/*.dis
	rm -rf *.bin *.o *.dis

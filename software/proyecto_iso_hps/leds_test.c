# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/mman.h>
# include <unistd.h>

#define ADDRESS 0xC0000000
#define OFFSET 0x00000000

int main() {
    int mem = open("/dev/mem", O_RDWR);
    if (mem < 0) {
        perror("open(\"/dev/mem\")");
        return 1;
    }

    size_t MEMORY_SIZE = sizeof(int) * 10;
    unsigned char* mapping = mmap
    (
        NULL,
        MEMORY_SIZE,
        PROT_READ | PROT_WRITE,
        MAP_SHARED,
        mem,
        ADDRESS + OFFSET
    );
    if (mapping == MAP_FAILED) {
        perror("mmap()");
        return 1;
    }

    volatile int* ptr = (void*)(mapping);

    for (int i = 0; i < 10; i++) {
        // Access memory position at offset i * sizeof(int)
        ptr[i] = i;

        printf("Allocated %d in memory\n", i);
    }

    munmap(mapping, OFFSET + sizeof(int) * 10);

    close(mem);

    printf("Memory written successfully!\n");

    return 0;
}
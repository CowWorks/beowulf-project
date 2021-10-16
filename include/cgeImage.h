// #include <stdlib.h>

// typedef union{
//     struct PNGheader{
//         unsigned char initializer;
//         unsigned char P, N, G;
//         unsigned char Dbyte, Abyte;
//         unsigned char Abyte, Abyte;
//     };

// }PNG;
#include <stdint.h>

//this will just move the pointer by byte_nums forward, or backwards if its negative.
#define SKIP_BYTES(mem, byte_num) (mem += byte_num);

uint32_t sh_get_uint32be(uint8_t *mem) {
    uint32_t result = 0;
    for(uint32_t i = 0; i < 4; ++i) {
        result <<= 8;
        result |= *(mem + i);
    }

    return result;
}

struct pngChunk {
    uint32_t data_length;
    uint8_t type[4];
    uint8_t  *data;
    uint32_t crc32;
};

 uint8_t* sh_memalloc(uint32_t bytes_to_allocate) {
    return (uint8 *) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, bytes_to_allocate);
}

uint8_t sh_memfree(uint8_t *mem_pointer) {
    return HeapFree(GetProcessHeap(), 0, (LPVOID) mem_pointer);        
}

void sh_memcpy(uint8_t *from, uint8_t *to, uint32_t bytes_to_copy) { //copy some bytes from "from" to "to" 

    while(bytes_to_copy-- > 0) {
        *(to + bytes_to_copy) = *(from + bytes_to_copy);
    }
}

void sh_memset(uint8_t *mem, uint8_t value_to_use, uint32_t bytes_to_set) {
    while(bytes_to_set-- > 0) {
        *mem++ = value_to_use;
    } 
}

uint16_t sh_get_uint16be(uint8_t *mem) {
    uint16_t result = 0;
    for(uint32 i = 0; i < 2; ++i) {
        result <<= 8;
        result |= *(mem + i);
    }

    return result;
}


uint32_t sh_get_uint32be(uint8_t *mem) {
    uint32_t result = 0;
    for(uint32_t i = 0; i < 4; ++i) {
        result <<= 8;
        result |= *(mem + i);
    }

    return result;
}

uint8_t* sh_read_file(const char *file_name) {
    uint8_t *result = NULL;
    HANDLE file = CreateFile(
            (const char *)file_name,
            GENERIC_READ,
            FILE_SHARE_READ,
            0,
            OPEN_EXISTING,
            FILE_ATTRIBUTE_NORMAL,
            0
            );

    DWORD size = GetFileSize(file, 0);

    result = sh_memalloc(size);
    ReadFile(file, (void *) result, size, 0, 0);
    CloseHandle(file);
    return result;
}

pngChunk sh_png_read_chunk(uint8_t *mem) {
    sh_png_chunk chunk = {};
    chunk.data_length = sh_get_uint32be(mem);
    SKIP_BYTES(mem, 4); //we move 4 bytes over because we read the length, which is 4 bytes

    *( (uint32_t *)&chunk.type) = *((uint32_t *) mem);
    SKIP_BYTES(mem, 4);

    chunk.data = sh_memalloc(chunk.data_length);

    sh_memcpy(mem, chunk.data, chunk.data_length);
    SKIP_BYTES(mem, chunk.data_length);

    chunk.crc32 = sh_get_uint32be(mem);

    return chunk;
}

struct sh_zlib_block {
    uint8_t cmf;
    uint8_t extra_flags;
    uint8_t *data;
    uint16_t check_value;
};


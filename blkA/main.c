#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PHY/NR_TRANSPORT/nr_transport_proto.h"
#include "PHY/TOOLS/nr_gold.h"
#include "common/utils/LOG/log.h"

extern void nr_codeword_scrambling(uint8_t *in,
                                   uint32_t size,
                                   uint8_t q,
                                   uint32_t Nid,
                                   uint32_t n_RNTI,
                                   uint32_t *out); 


int main(void) {
    printf("Start\n");

    // Real runtime size = 2688 bits = 336 bytes
    uint32_t size = 2688;
    uint8_t in[336] __attribute__((aligned(32)));
    uint32_t out[84] __attribute__((aligned(32))); // 2688 bits / 32 = 84 word
    

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    // Populate input with representative pattern (optional)
    // You could copy actual bytes from GDB ("i\276\366\002...") if desired
    const uint8_t gdb_bytes[] = {
        0x69, 0xBE, 0xF6, 0x02, 0xAD, 0xFB, 0x50, 0xE6,
        0xFF, 0x35, 0xA8, 0x44, 0xF9, 0x21, 0x92, 0xAA,
        0x68, 0x28, 0x2A
    };
    
    printf("Just before half of the inputs\n");
    memcpy(in, gdb_bytes, sizeof(gdb_bytes));

    uint8_t q = 0;
    uint32_t Nid = 0;
    uint32_t n_RNTI = 65535; // 0xFFFF
    
    printf("Just before function\n");
    nr_codeword_scrambling(in, size, q, Nid, n_RNTI, out);
    
    printf("After function\n");

    int roundedSz = (size + 31) / 32;
    printf("Scrambled output (roundedSz=%d):\n", roundedSz);
    for (int i = 0; i < roundedSz; i++) {
        printf("out[%02d] = 0x%08X\n", i, out[i]);
    }

    printf("End\n");
    return 0;
}


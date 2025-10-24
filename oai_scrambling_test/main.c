#include "mock_defs.h"

// Inclua o caminho correto do arquivo da OAI
#include "/home/anderson/openairinterface5g/openair1/PHY/NR_TRANSPORT/nr_scrambling.c"

int main() {
    printf("=== Start nr_codeword_scrambling() test ===\n");

    // Reproduzindo os parâmetros do GDB
    uint32_t size = 2688;
    uint8_t q = 0;
    uint32_t Nid = 0;
    uint32_t n_RNTI = 65535;

    // Alocação dos buffers
    uint8_t *in = aligned_alloc(32, size / 8);
    uint32_t *out = aligned_alloc(32, (size + 31) / 32 * sizeof(uint32_t));

    // Inicializa com os bytes observados no GDB
    uint8_t bytes[] = {0x69, 0xBE, 0xF6, 0x02, 0xAD, 0xFB, 0x50, 0xE6, 0xFF, 0x35, 0xA8, 0x44, 0xF9, 0x21, 0x92, 0xAA, 0x68, 0x28, 0x2A};
    memcpy(in, bytes, sizeof(bytes));

    memset(out, 0, (size + 31) / 32 * sizeof(uint32_t));

    printf("Calling nr_codeword_scrambling()...\n");
    nr_codeword_scrambling(in, size, q, Nid, n_RNTI, out);

    int roundedSz = (size + 31)/32;
    printf("Scrambled output (roundedSz=%d):\n", roundedSz);
    for (int i = 0; i < roundedSz; i++){
        printf("out[%d] = 0x%08X\n", i, out[i]);
    }

    printf("=== End ===\n");
    free(in);
    free(out);
    return 0;
}


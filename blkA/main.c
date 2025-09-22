#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void nr_codeword_scrambling(uint8_t *in,
				   uint32_t size,
				   uint8_t q,
				   uint32_t Nid,
				   uint32_t n_RNTI,
				   uint32_t* out);

int main() {
	printf("Start\n");
	uint8_t in[16];
	uint32_t out[16];
	uint32_t size = sizeof(in) * 8;

	for (int i = 0; i < sizeof(in); i++){
		in[i] = i;
	}
	
	uint8_t q = 0;
	uint32_t Nid = 100;
	uint32_t n_RNTI = 0x1234;

	nr_codeword_scrambling(in, size, q, Nid, n_RNTI, out);

	int roundedSz = (size + 31)/32;
	printf("Scrambled output (roundedSz=%d):\n", roundedSz);
	for (int i = 0; i <roundedSz; i++){
		printf("out[%d] = 0x%08X\n", i, out[i]);
	}
	printf("\nEnd\n");
	return 0; 
}


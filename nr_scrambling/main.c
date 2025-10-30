#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

extern void nr_codeword_scrambling(uint8_t *in,
								   uint32_t size,
								   uint8_t q,
								   uint32_t Nid,
								   uint32_t n_RNTI,
								   uint32_t *out);

int main(void)
{
	/* Requested parameters */
	const uint32_t size   = 2688;      /* bits */
	const uint8_t  q      = 0;
	const uint32_t Nid    = 0;
	const uint32_t n_RNTI = 0xFFFF;    /* 65535 */

	/* Derived buffer sizes: 2688 bits = 336 bytes; 2688/32 = 84 words */
	uint8_t  in[336] __attribute__((aligned(32)));
	uint32_t out[84]  __attribute__((aligned(32)));

	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));

	/* Optional: seed the input with a small sample pattern */
	const uint8_t sample[] = {
		0x69, 0xBE, 0xF6, 0x02, 0xAD, 0xFB, 0x50, 0xE6,
		0xFF, 0x35, 0xA8, 0x44, 0xF9, 0x21, 0x92, 0xAA,
		0x68, 0x28, 0x2A
	};
	memcpy(in, sample, sizeof(sample) < sizeof(in) ? sizeof(sample) : sizeof(in));
	printf("Starting scrambling tests...\n");
	/* Run the scrambling 1000 times (as requested earlier) with small variation */
	for (int iter = 0; iter < 1000; ++iter) {
		/* vary a byte so each run differs */
		in[0] = (uint8_t)iter;

		nr_codeword_scrambling(in, size, q, Nid, n_RNTI, out);

		if ((iter % 100) == 0) {
			printf("iter %d: out[0]=0x%08X\n", iter, (unsigned)out[0]);
		}
	}
	
	/* Print final output buffer (rounded size in 32-bit words) */
	int roundedSz = (size + 31) / 32;
	printf("Final output (roundedSz=%d):\n", roundedSz);
	for (int i = 0; i < roundedSz; ++i) {
		printf("out[%02d] = 0x%08X\n", i, out[i]);
	}

	return 0;
}


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define CONSTANTS_H_ASCIIS

#include "constants.h"

int main() {
	for (u8 col = 0; col < HEIGHT; ++col) {
		for (u8 row = 0; row < WIDTH; ++row) {
			f32 xcol = (float)col;
			f32 yrow = (float)row;
			f32 cxdh = (2 * xcol - WIDTH) / HEIGHT;
			f32 cydh = (2 * yrow - HEIGHT) / HEIGHT;
			f32 delt = sqrtf((cxdh * cxdh) + (cydh * cydh));
			delt -= (f32)DELT_0_5;
			delt += (f32)DELT_0_01 * HEIGHT / (2 * (xcol - yrow) + HEIGHT - WIDTH);
			delt          = fabsf(delt);
			delt          = DELT_1 / delt;
			char char_out = " -+=<@#"[(u32)floorf(delt / (1 + delt) * 7)];
			printf("%c%c", char_out, char_out);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}

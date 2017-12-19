#include "pixelwork.h"


int isSet(uint8_t B, uint8_t G, uint8_t R) {

	return (B != 255 || G != 255 || R != 255);

}


void bmp_set_horizontal(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {

	int a;
	for (a = 3 * start; a < 3 * (nr + start) ; a += 3) {
		bmp_data[(i + k) * (width * 3 + padding) + j + a] = 0;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 1] = 0;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 2] = 0;
	}


}



int hline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {

	int a;
	for (a = 3 * start; a < 3 * (nr + start); a += 3)
		if (!isSet(bmp_data[(i + k) * (width * 3 + padding) + j + a], bmp_data[(i + k) * (width * 3 + padding) + j + a + 1], bmp_data[(i + k) * (width * 3 + padding) + j + a + 2])) {
			return 0;
		}

//	bmp_set_horizontal(bmp_data, padding, width, i, j, k, nr, start);

	return 1;
}


void bmp_set_vertical(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {

	int a;
	for (a = start; a < nr; a++) {
		bmp_data[(i + a) * (width * 3 + padding) + j + k ] = 0 ;
		bmp_data[(i + a) * (width * 3 + padding) + j + k + 1] = 0;
		bmp_data[(i + a) * (width * 3 + padding) + j + k + 2] = 0;
	}


}




int vline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {
	int a;
	for (a = start; a < nr; a++)
		if (!isSet(bmp_data[(i + a) * (width * 3 + padding) + j + k ], bmp_data[(i + a) * (width * 3 + padding) + j + k + 1], bmp_data[(i + a) * (width * 3 + padding) + j + k + 2])) {
			return 0;
		}
	//printf("DAI%d\n",j+k);
	return 1;
}
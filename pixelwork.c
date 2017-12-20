#include "pixelwork.h"


int isSet(uint8_t B, uint8_t G, uint8_t R) {

	return (B != 255 || G != 255 || R != 255);

}


void bmp_set_horizontal(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start,pixel color) {

	int a;
	for (a = 3 * start; a < 3 * (nr + start) ; a += 3) {
		bmp_data[(i + k) * (width * 3 + padding) + j + a] = color.B;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 1] = color.G;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 2] = color.R;
	}

	


}


void bmp_set_vertical(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start,pixel color) {

	int a;
	for (a = start; a < nr; a++) {
		bmp_data[(i + a) * (width * 3 + padding) + j + k ] = color.B ;
		bmp_data[(i + a) * (width * 3 + padding) + j + k + 1] = color.G;
		bmp_data[(i + a) * (width * 3 + padding) + j + k + 2] = color.R;
	}


}

int hline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {

	int a;
	for (a = 3 * start; a < 3 * (nr + start); a += 3)
		if (!isSet(bmp_data[(i + k) * (width * 3 + padding) + j + a], bmp_data[(i + k) * (width * 3 + padding) + j + a + 1], bmp_data[(i + k) * (width * 3 + padding) + j + a + 2])) {
			return 0;
		}

	return 1;
}

int vline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start) {
	int a;
	for (a = start; a < nr; a++)
		if (!isSet(bmp_data[(i + a) * (width * 3 + padding) + j + k ], bmp_data[(i + a) * (width * 3 + padding) + j + k + 1], bmp_data[(i + a) * (width * 3 + padding) + j + k + 2])) {
			return 0;
		}
	return 1;
}
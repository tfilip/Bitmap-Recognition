#include "pixelwork.h"


int isSet(uint8_t B, uint8_t G, uint8_t R) {

	return (B != 255 || G != 255 || R != 255);

}


void bmp_set_horizontal(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start, pixel color) {

	int a;
	for (a = 3 * start; a < 3 * (nr + start) ; a += 3) {
		bmp_data[(i + k) * (width * 3 + padding) + j + a] = color.B;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 1] = color.G;
		bmp_data[(i + k) * (width * 3 + padding) + j + a + 2] = color.R;
	}




}


void bmp_set_vertical(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start, pixel color) {

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


void swap_numbers(uint8_t* bmp_data, int padding, int width, int i1, int j1, int i2, int j2, int n1, int n2, pixel p1, pixel p2) {


	delNumber(bmp_data,padding,width,i1,j1);
	delNumber(bmp_data,padding,width,i2,j2);

	switch (n1) {
	case 0:
		drawZero(bmp_data, padding, width, i2, j2, p1);
		break;
	case 1:
		drawOne(bmp_data, padding, width, i2, j2, p1);
		break;
	case 2:
		drawTwo(bmp_data, padding, width, i2, j2, p1);
		break;
	case 3:
		drawThree(bmp_data, padding, width, i2, j2, p1);
		break;
	case 4:
		drawFour(bmp_data, padding, width, i2, j2, p1);
		break;
	case 5:
		drawFive(bmp_data, padding, width, i2, j2, p1);
		break;
	case 6:
		drawSix(bmp_data, padding, width, i2, j2, p1);
		break;
	case 7:
		drawSeven(bmp_data, padding, width, i2, j2, p1);
		break;
	case 8:
		drawEight(bmp_data, padding, width, i2, j2, p1);
		break;
	case 9:
		drawNine(bmp_data, padding, width, i2, j2, p1);
		break;
	default:
		break;
	}


	switch (n2) {
	case 0:
		drawZero(bmp_data, padding, width, i1, j1, p2);

		break;
	case 1:
		drawOne(bmp_data, padding, width, i1, j1, p2);
		break;
	case 2:
		drawTwo(bmp_data, padding, width, i1, j1, p2);
		break;
	case 3:
		drawThree(bmp_data, padding, width, i1, j1, p2);
		break;
	case 4:
		drawFour(bmp_data, padding, width, i1, j1, p2);
		break;
	case 5:
		drawFive(bmp_data, padding, width, i1, j1, p2);
		break;
	case 6:
		drawSix(bmp_data, padding, width, i1, j1, p2);
		break;
	case 7:
		drawSeven(bmp_data, padding, width, i1, j1, p2);
		break;
	case 8:
		drawEight(bmp_data, padding, width, i1, j1, p2);
		break;
	case 9:
		drawNine(bmp_data, padding, width, i1, j1, p2);
		break;
	default:
		break;
	}


}
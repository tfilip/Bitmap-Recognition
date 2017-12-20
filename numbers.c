#include "pixelwork.h"





void delNumber(uint8_t* bmp_data, int padding, int width, int i , int j) {
	pixel white;
	white.B = 255;
	white.G = 255;
	white.R = 255;
	for (int k = 0; k < 5; k++) {
		bmp_set_horizontal(bmp_data, padding, width, i, j, k, 5, 0, white);
	}
}

void drawZero(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);

}


void drawOne(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);


}


void drawTwo(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 3, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);


}


void drawThree(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 4, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);


}


void drawFour(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);


}

void drawFive(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	

}


void drawSix(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);


}


void drawSeven(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);


}


void drawEight(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);

}


void drawNine(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);

}



int isZero(uint8_t* bmp_data, int padding, int width, int i, int j) {

	//Verficare cifra 0
	//Linia de jos de la 0

	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	//Linia de sus de la 0
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}
	//Linia din stanga de la 0

	if (vline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	//Linia din dreapta de la 0
	if (vline_set(bmp_data, padding, width, i, j, 12, 5, 0) == 0) {
		return 0;
	}

	//Mijlocul de la zero sa fie gol
	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0)) {
		return 0;
	}


	return 1;

}

int isOne(uint8_t* bmp_data, int padding, int width, int i, int j) {


	//Verficare cifra 1

	if (hline_set(bmp_data, padding, width, i, j, 0, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 4, 0)) {
		return 0;
	}

	//A 5 linie coloarata

	//A treia linie 0
	if (!vline_set(bmp_data, padding, width, i, j, 12, 5, 0)) {

		return 0;
	}

	//A treia linie 0
	if (vline_set(bmp_data, padding, width, i, j, 15, 5, 0)) {
		return 0;
	}

	if (isSet(bmp_data[i * (width * 3 + padding) + j + 15], bmp_data[i * (width * 3 + padding) + j + 16], bmp_data[i * (width * 3 + padding) + j + 17])) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0)) {
		return 0;
	}

	return 1;

}


int isTwo(uint8_t* bmp_data, int padding, int width, int i, int j) {

	//Verficare cifra 1


	//Liniile de sus si de jos
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	//Linia de mijloc
	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}


	//Setat jos stanga

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}



	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4) == 0) {
		return 0;
	}

	//Setat sus dreapta

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0) == 0) {
		return 0;
	}


	return 1;

}

int isThree(uint8_t* bmp_data, int padding, int width, int i, int j) {


	//Verficare cifra 1


	//Liniile de sus si de jos
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	//Linia de mijloc
	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0) == 0) {
		return 0;
	}


	//Setat jos stanga
	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4) == 0) {
		return 0;
	}


	//Setat sus dreapta




	if (hline_set(bmp_data, padding, width, i, j, 3, 3, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4) == 0) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	return 1;

}

int isFour(uint8_t* bmp_data, int padding, int width, int i, int j) {

	if (hline_set(bmp_data, padding, width, i, j, 0, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 2, 5, 0)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 3, 1)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 4, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 4, 3, 1)) {
		return 0;
	}

	if (!vline_set(bmp_data, padding, width, i, j, 12, 5, 0)) {
		return 0;
	}

	return 1;

}


int isFive(uint8_t* bmp_data, int padding, int width, int i, int j) {

	//Liniile de sus si de jos
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	//Linia de mijloc
	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}


	//Setat jos stanga

	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4)) {
		return 0;
	}

	//Setat sus dreapta

	if (!hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	return 1;
}


int isSix(uint8_t* bmp_data, int padding, int width, int i, int j) {

	//Liniile de sus si de jos
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	//Linia de mijloc
	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}


	//Setat jos stanga

	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}


	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4)) {
		return 0;
	}

	//Setat sus dreapta

	if (!hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	return 1;
}

int isSeven(uint8_t* bmp_data, int padding, int width, int i, int j) {


	if (!vline_set(bmp_data, padding, width, i, j, 12, 5, 0)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 4, 5, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 0, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 2, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 4, 0)) {
		return 0;
	}

	return 1;
}


int isEight(uint8_t* bmp_data, int padding, int width, int i, int j) {

	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	//Linia de sus de la 0
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}
	//Linia din stanga de la 0

	if (vline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	//Linia din dreapta de la 0
	if (vline_set(bmp_data, padding, width, i, j, 12, 5, 0) == 0) {
		return 0;
	}


	return 1;
}

int isNine(uint8_t* bmp_data, int padding, int width, int i, int j) {
	//Verficare cifra 1


	//Liniile de sus si de jos
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	//Linia de mijloc
	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0) == 0) {
		return 0;
	}


	//Setat jos stanga
	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4) == 0) {
		return 0;
	}

	//Setat sus dreapta

	if (hline_set(bmp_data, padding, width, i, j, 3, 3, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4) == 0) {
		return 0;
	}


	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}


	if (!hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}


	return 1;
}


int getNumber(uint8_t* bmp_data, int padding, int width, int i, int j) {

	if (isZero(bmp_data, padding, width, i, j)){
		return 0;
	}
	else if(isOne(bmp_data, padding, width, i, j)){
		return 1;
	}
	else if(isTwo(bmp_data, padding, width, i,j)){
		return 2;
	}
	else if(isThree(bmp_data,padding,width,i,j)){
		return 3;
	}
	else if(isFour(bmp_data, padding, width, i, j)){
		return 4;
	}
	else if(isFive(bmp_data, padding, width, i,j)){
		return 5;
	}
	else if(isSix(bmp_data,padding,width,i,j)){
		return 6;
	}
	else if(isSeven(bmp_data, padding, width, i, j)){
		return 7;
	}
	else if(isEight(bmp_data, padding, width, i,j)){
		return 8;
	}
	else if(isNine(bmp_data,padding,width,i,j)){
		return 9;
	}

	return -1;
}


pixel getColor(uint8_t* bmp_data, int padding, int width, int i, int j){

	pixel color;
	color.B = bmp_data[(i+2) * (width * 3 + padding) + j + 12];
	color.G = bmp_data[(i+2) * (width * 3 + padding) + j + 1 + 12];
	color.R = bmp_data[(i+2) * (width * 3 + padding) + j + 2 + 12];

	return color;

}
//Tepes-Onea Filip 312CD

#include "pixelwork.h"

/*
	In aceast fisier sunt prezente functiile
	ce opereaza (stergere, verificare,desenare) cu numerele 
	din captcha.

*/

//Pune toti pixelii pe alb pe spatiul unei cifre(5x5)
void delNumber(uint8_t* bmp_data, int padding, int width, int i , int j) {
	pixel white;
	white.B = 255;
	white.G = 255;
	white.R = 255;
	int k;
	for (k = 0; k < 5; k++) {
		bmp_set_horizontal(bmp_data, padding, width, i, j, k, 5, 0, white);
	}
}

/*
	Functiile de tip drawX deseanza numerele cu ajutorul
	functiilor din fisierul pixelwork
*/
void drawZero(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);

}


void drawOne(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);

}


void drawTwo(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 3, color);

}


void drawThree(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 4, 0, color);

}


void drawFour(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);


}

void drawFive(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);

}


void drawSix(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 3, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);

}


void drawSeven(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);

}


void drawEight(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);

}


void drawNine(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color) {

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0, color);
	bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 2, color);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0, color);

}


/*
	Functiile de tip isX verifica daca de la un pixel
	incepe o anumita cifra, si returneaza 1 in cazul
	pozitiv

	Se aseamana cu cele de desenat, doar ca includ conditii suplimentare
	pentru a nu se incurca cu alte cifre

*/
int isZero(uint8_t* bmp_data, int padding, int width, int i, int j) {



	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (vline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	if (vline_set(bmp_data, padding, width, i, j, 12, 5, 0) == 0) {
		return 0;
	}

	//Conditia pentru linia de mijloc (altfel s-ar incurca cu 8)
	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0)) {
		return 0;
	}

	return 1;

}

int isOne(uint8_t* bmp_data, int padding, int width, int i, int j) {



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

	if (!vline_set(bmp_data, padding, width, i, j, 12, 5, 0)) {

		return 0;
	}

	//Conditii suplimentare pentru a fi sigur ca este unu la acel pixel
	//si nu se incurca cu o linie vertifcala de la cifre adiacente
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

	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0) == 0) {
		return 0;
	}

	return 1;

}

int isThree(uint8_t* bmp_data, int padding, int width, int i, int j) {


	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4) == 0) {
		return 0;
	}

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

	//Cinci se aseamana cu verifcarea de la doi doar ca se inverseaza
	//verificarea a doi pixeli(stanga sus si dreapta jos)

	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 3, 1, 0)) {
		return 0;
	}

	return 1;

}


int isSix(uint8_t* bmp_data, int padding, int width, int i, int j) {

	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 5, 0) == 0) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 4)) {
		return 0;
	}

	if (!hline_set(bmp_data, padding, width, i, j, 1, 1, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 3, 1, 4)) {
		return 0;
	}

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

	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (vline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}

	if (vline_set(bmp_data, padding, width, i, j, 12, 5, 0) == 0) {
		return 0;
	}

	return 1;

}

int isNine(uint8_t* bmp_data, int padding, int width, int i, int j) {
	
	if (hline_set(bmp_data, padding, width, i, j, 0, 5, 0) == 0) {
		return 0;
	}
	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 2, 3, 0) == 0) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 4, 0)) {
		return 0;
	}

	if (hline_set(bmp_data, padding, width, i, j, 1, 1, 4) == 0) {
		return 0;
	}

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


/*
	Cu ajutorul functiilor de mai sus
	verifica fiecare daca este o anumita cifra,
	in caz afirmativ returneaza cifra aferenta
	, iar in caz negativ returneaza -1
*/
int getNumber(uint8_t* bmp_data, int padding, int width, int i, int j) {

	if (isZero(bmp_data, padding, width, i, j)) {
		return 0;
	}
	else if (isOne(bmp_data, padding, width, i, j)) {
		return 1;
	}
	else if (isTwo(bmp_data, padding, width, i, j)) {
		return 2;
	}
	else if (isThree(bmp_data, padding, width, i, j)) {
		return 3;
	}
	else if (isFour(bmp_data, padding, width, i, j)) {
		return 4;
	}
	else if (isFive(bmp_data, padding, width, i, j)) {
		return 5;
	}
	else if (isSix(bmp_data, padding, width, i, j)) {
		return 6;
	}
	else if (isSeven(bmp_data, padding, width, i, j)) {
		return 7;
	}
	else if (isEight(bmp_data, padding, width, i, j)) {
		return 8;
	}
	else if (isNine(bmp_data, padding, width, i, j)) {
		return 9;
	}

	return -1;
}


/*
	Preia culoara de la un pixel care este setat la fiecare cifra
	si o returneaza
*/
pixel getColor(uint8_t* bmp_data, int padding, int width, int i, int j) {

	pixel color;
	color.B = bmp_data[(i + 2) * (width * 3 + padding) + j + 12];
	color.G = bmp_data[(i + 2) * (width * 3 + padding) + j + 1 + 12];
	color.R = bmp_data[(i + 2) * (width * 3 + padding) + j + 2 + 12];

	return color;

}
#include "numbers.h"
#include "pixelwork.h"

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
		//printf("DS");
	}


	if (hline_set(bmp_data, padding, width, i, j, 4, 5, 0)) {
		return 0;
	}

	//printf("pentru 1: %d %d\n",i,j/3);
	/*bmp_set_vertical(bmp_data, padding, width, i, j, 0, 5, 0);
	bmp_set_vertical(bmp_data, padding, width, i, j, 3, 5, 0);
	bmp_set_vertical(bmp_data, padding, width, i, j, 6, 5, 0);
	bmp_set_vertical(bmp_data, padding, width, i, j, 9, 5, 0);
	bmp_set_vertical(bmp_data, padding, width, i, j, 12, 5, 0);*/
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

	/*
	bmp_data[(i+3) * (width * 3 + padding) + j + 12 ] = 0;
	bmp_data[(i+3) * (width * 3 + padding) + j + 1 + 12] = 0;
	bmp_data[(i+3) * (width * 3 + padding) + j + 2 + 12] = 0;
	*/

	//printf("pentru 1: %d %d\n",i,j/3);


	//bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 4, 5, 0);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 2, 5, 0);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 1, 1, 4);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 3, 1, 4);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 3, 1, 0);
	//bmp_set_horizontal(bmp_data, padding, width, i, j, 1, 1, 0);

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

	bmp_set_horizontal(bmp_data, padding, width, i, j, 0, 5, 0);

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
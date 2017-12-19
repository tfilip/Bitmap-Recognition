#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "bmp_header.h"
#include "input_output.h"
#include "def.h"

int isSet(uint8_t B, uint8_t G, uint8_t R) {

//	printf("B:%d G:%d R:%d\n", B,G,R);
	return (B != 255 || G != 255 || R != 255);

}


void task1_change_colors(pixel change_to, uint8_t* bmp_data, int padding, int height, int width) {

	int i, j;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width * 3; j += 3) {

			if (bmp_data[i * (width * 3 + padding) + j] != 255 &&
			        bmp_data[i * (width * 3 + padding) + j + 1] != 255 &&
			        bmp_data[i * (width * 3 + padding) + j + 2] != 255) {

				bmp_data[i * (width * 3 + padding) + j] = change_to.B;
				bmp_data[i * (width * 3 + padding) + j + 1] = change_to.G;
				bmp_data[i * (width * 3 + padding) + j + 2] =  change_to.R;


			}
//							isSet(bmp_data[i * (width * 3 + padding) + j],bmp_data[i * (width * 3 + padding) + j + 1],bmp_data[i * (width * 3 + padding) + j + 2]);

		}
	}


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


void decode_task2(uint8_t* bmp_data, int padding, int height, int width, char* filename) {

	int i, j;


	for (j = 0; j < 3 * (width - 4); j += 3) {
		for (i = 0; i < height - 4; i++) {
			//printf("PIXELUL ALBASTRU NR:%d\n", j);

			if (isZero(bmp_data, padding, width, i, j)) {

				/*
				bmp_data[i * (width * 3 + padding) + j] = 0;
				bmp_data[i * (width * 3 + padding) + j + 1] = 0;
				bmp_data[i * (width * 3 + padding) + j + 2] = 0;
				*/
				printf("%d", 0);
				print_number(filename, 0);
				continue;
			}

			if (isOne(bmp_data, padding, width, i, j)) {


				bmp_data[i * (width * 3 + padding) + j] = 0;
				bmp_data[i * (width * 3 + padding) + j + 1] = 0;
				bmp_data[i * (width * 3 + padding) + j + 2] = 0;

				print_number(filename, 1);
				printf("%d", 1);
				continue;

			}


			if (isTwo(bmp_data, padding, width, i, j)) {
				print_number(filename, 2);


				bmp_data[i * (width * 3 + padding) + j] = 0;
				bmp_data[i * (width * 3 + padding) + j + 1] = 0;
				bmp_data[i * (width * 3 + padding) + j + 2] = 0;

				printf("%d", 2);
				continue;
			}

			if (isThree(bmp_data, padding, width, i, j)) {
				print_number(filename, 3);
				printf("%d", 3);
				continue;
			}

			if (isFour(bmp_data, padding, width, i, j)) {
				print_number(filename, 4);
				printf("%d", 4);
				continue;
			}

			if (isFive(bmp_data, padding, width, i, j)) {
				print_number(filename, 5);
				printf("%d", 5);
				continue;
			}

			if (isSix(bmp_data, padding, width, i, j)) {
				print_number(filename, 6);
				printf("%d", 6);
				continue;
			}

			if (isSeven(bmp_data, padding, width, i, j)) {
				print_number(filename, 7);
				printf("%d", 7);
				continue;
			}

			if (isEight(bmp_data, padding, width, i, j)) {
				print_number(filename, 8);
				printf("%d", 8);
				continue;
			}

			if (isNine(bmp_data, padding, width, i, j)) {
				print_number(filename, 9);
				printf("%d", 9);
				continue;
			}

		}
	}

	//printf("\n");


}


int main()
{

	pixel change_to;
	int v[MAX_NUMBERS], v_size = 0;
	FILE *img, *bonus_img;
	char filename[IMG_NAME_MAX_LENGTH];
	uint8_t *bmp_data;


	struct bmp_fileheader fh; //File Header
	struct bmp_infoheader ih; //Info Header


	//Alocare memorie pentru cele doua fisiere binare
	img = (FILE*) malloc(1000);
	bonus_img = (FILE*) malloc(1000);

	strcpy(filename, read(&change_to, v, &v_size, &img, &bonus_img));

	//Setez FileHeader si InfoHeader
	fread(&fh, sizeof(struct bmp_fileheader), 1, img);
	fread(&ih, sizeof(struct bmp_infoheader), 1, img);

	//Pointez catre inceputul zonei de date
	fseek(img, fh.imageDataOffset, SEEK_SET);

	//Setez padding
	int padding = 4 -  (3 * ih.width) % 4;
	if (padding == 4) padding = 0;

	//Aloc memorie
	bmp_data = (uint8_t*) malloc(ih.biSizeImage + padding * ih.width);
	//Citesc Datele
	fread(bmp_data, sizeof(uint8_t), ih.biSizeImage + padding * ih.width, img);


	//TASK 1
	task1_change_colors(change_to, bmp_data, padding, ih.height, ih.width);

	write_task1(fh, ih, bmp_data, filename, padding);

	//TASK 2
	decode_task2(bmp_data, padding, ih.height, ih.width, filename);

	//write_task1(fh, ih, bmp_data, filename, padding);


	//Dealocare de memorie pentru fisiere
	free(img);
	free(bonus_img);

	return 0;
}
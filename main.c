//Tepes-Onea Filip 312CD

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bmp_header.h"
#include "input_output.h"
#include "def.h"

/*
	In main am logica principala
	din program si realizarea matricei
	de pixeli, rezolvarea task-urilor
	cu ajutorul functiilor din celalate
	fisiere
*/

/*
	Folosesc aceasta strucutra pentru
	taskul 3, sa salvez toate numerele
	din captcha
*/
typedef struct {
	int i;
	int j;
	int number;
	pixel color;
} Number;

/*
	Structura in care salvez pozitiile
	pe care se afla numere

*/
typedef struct {
	int i;
	int j;
} Spot;

/*
	Functia pentru task-ul 1, de schimbare
	a culoriilor. Aceasta verifia pixel cu pixel
	daca este diferit de alb, iar daca este diferit il
	face in culoarea ceruta

*/
void task1_change_colors(pixel change_to, uint8_t* bmp_data, int padding, int height, int width) {

	int i, j;

	for (i = 0; i < height; i++) {
		for (j = 0; j < width * 3; j += 3) {

			//Verficarea pentru culoarea alb (255,255,255)
			if (bmp_data[i * (width * 3 + padding) + j] != 255 &&
			        bmp_data[i * (width * 3 + padding) + j + 1] != 255 &&
			        bmp_data[i * (width * 3 + padding) + j + 2] != 255) {

				//Modificarea culorii
				bmp_data[i * (width * 3 + padding) + j] = change_to.B;
				bmp_data[i * (width * 3 + padding) + j + 1] = change_to.G;
				bmp_data[i * (width * 3 + padding) + j + 2] =  change_to.R;


			}
		}
	}
}

/*
	Functia aferenta task-ului 2
	ce parcurge bmp-ul coloana cu coloana
	de la stanga la dreapta
	si verfica daca la un pixel incepe
	o anumita cifra

*/
void decode_task2(uint8_t* bmp_data, int padding, int height, int width, char* filename) {

	int i, j;

	for (j = 0; j < 3 * (width - 4); j += 3) {
		for (i = 0; i < height - 4; i++) {

			/* In cazul in care a gasit o anumita cifra
			nu le mai verifica si pe celalate
			*/
			if (isZero(bmp_data, padding, width, i, j)) {
				print_number(filename, 0);
				continue;
			}

			if (isOne(bmp_data, padding, width, i, j)) {
				print_number(filename, 1);
				continue;
			}

			if (isTwo(bmp_data, padding, width, i, j)) {
				print_number(filename, 2);
				continue;
			}

			if (isThree(bmp_data, padding, width, i, j)) {
				print_number(filename, 3);
				continue;
			}

			if (isFour(bmp_data, padding, width, i, j)) {
				print_number(filename, 4);
				continue;
			}

			if (isFive(bmp_data, padding, width, i, j)) {
				print_number(filename, 5);
				continue;
			}

			if (isSix(bmp_data, padding, width, i, j)) {
				print_number(filename, 6);
				continue;
			}

			if (isSeven(bmp_data, padding, width, i, j)) {
				print_number(filename, 7);
				continue;
			}

			if (isEight(bmp_data, padding, width, i, j)) {
				print_number(filename, 8);
				continue;
			}

			if (isNine(bmp_data, padding, width, i, j)) {
				print_number(filename, 9);
				continue;
			}
		}
	}
}

/*
	Functia pentru task-ul 3.
	Aceasta pune intr-un vector toate numerele
	existente in captcha si in alt vector toate pozitiile
	pe care se aflau acestea. Dupa aceea sterge toate numerele
	si le pune pe pozitii, in ordine, doar pe cele care nu trebuiesc
	eliminate

*/
void task3(uint8_t* bmp_data, int padding, int height, int width, char* filename, int *numbers, int max) {

	int i, j, l, y;
	Number nums[101];
	Spot spots[101];
	int k = 0, m = 0;

	//Pun toate numerele existente intr-un vector
	for (j = 0; j < 3 * (width - 4); j += 3) {
		for (i = 0; i < height - 4; i++) {
			int number = getNumber(bmp_data, padding, width, i, j);
			if (number != -1) {
				nums[k].i = i;
				nums[k].j = j;
				nums[k].number = number;
				nums[k].color = getColor(bmp_data, padding, width, i, j);
				spots[m].i = i;
				spots[m].j = j;
				m++;
				k++;
				delNumber(bmp_data, padding, width, i, j);
			}
		}
	}

	//Repun toate numerele ce trebuie sa fie
	int h = 0;
	for (l = 0; l < k; l++) {
		int ok = 1;
		for (y = 0; y < max; y++) {
			if (nums[l].number == numbers[y]) {
				ok = 0;
			}
		}
		if (ok) {
			switch (nums[l].number) {
			case 0:
				drawZero(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 1:
				drawOne(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 2:
				drawTwo(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				//	return;
				h++;
				break;
			case 3:
				drawThree(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 4:
				drawFour(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 5:
				drawFive(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 6:
				drawSix(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 7:
				drawSeven(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 8:
				drawEight(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			case 9:
				drawNine(bmp_data, padding, width, spots[h].i, spots[h].j, nums[l].color);
				h++;
				break;
			}
		}
	}
}

int main()
{

	pixel change_to;
	int v[MAX_NUMBERS], v_size = 0;
	FILE *img, *bonus_img;
	char filename[IMG_NAME_MAX_LENGTH];
	uint8_t *bmp_data;
	uint8_t *bmp_data_2;

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
	bmp_data_2 = (uint8_t*) malloc(ih.biSizeImage + padding * ih.width);

	//Citesc Datele
	fread(bmp_data, sizeof(uint8_t), ih.biSizeImage + padding * ih.width, img);

	fseek(img, fh.imageDataOffset, SEEK_SET);

	fread(bmp_data_2, sizeof(uint8_t), ih.biSizeImage + padding * ih.width, img);


	//TASK 1
	task1_change_colors(change_to, bmp_data, padding, ih.height, ih.width);

	write_task(fh, ih, bmp_data, filename, padding, 1);

	//TASK 2
	decode_task2(bmp_data, padding, ih.height, ih.width, filename);

	//TASK 3

	task3(bmp_data_2, padding, ih.height, ih.width, filename, v, v_size);
	write_task(fh, ih, bmp_data_2, filename, padding, 3);


	//Dealocare de memorie
	free(img);
	free(bonus_img);
	free(bmp_data);
	free(bmp_data_2);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_output.h"
#include "def.h"


int read(Color *change_to, int *v, int *v_size, FILE *img_b, FILE *bonus_img_b) {

	char img[IMG_NAME_MAX_LENGTH], bonus_img[IMG_NAME_MAX_LENGTH];


	//Citirea datelor de intrare

	int v_index = 0;

	char filename[] = "input.txt";

	FILE *in = fopen(filename, "rt");

	//Verificare daca a putut deschide fisierul
	if ( in == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", filename);
		return -1;
	}

	//Citire numele imaginii

	fgets( img, IMG_NAME_MAX_LENGTH, in );

	//Sterge NEWLINE din capatul numelui
	strtok(img, "\n");



	//Citire culori ce trebuie schimbate
	fscanf( in, "%hi", &change_to->B );
	fscanf( in, "%hi", &change_to->G );
	fscanf( in, "%hi", &change_to->R );

	//Trecere la linia urmatoare
	fgetc(in);

	//Citire numere pentru task-ul 3
	char line[MAX_NUMBERS * 2];
	char delim[] = " ";

	fgets( line, MAX_NUMBERS * 2, in );

	strtok(line, "\n");

	char *p = strtok( line, delim );

	while ( p != NULL ) {
		v[v_index] = atoi(p);
		v_index++;
		p = strtok(NULL, delim);
	}

	//Citire fisier bonus

	fgets( bonus_img, IMG_NAME_MAX_LENGTH, in );

	fclose(in);

	//Deschide fisierele binare si setaza numarul de cifre pentru task-ul 3

	*v_size = v_index;
	img_b = fopen(img, "rb");

	if ( img_b == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", img);
		return -1;
	}

	bonus_img_b = fopen(bonus_img, "rb");

	if ( bonus_img_b == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", bonus_img);
		return -1;
	}

	return 0;

}
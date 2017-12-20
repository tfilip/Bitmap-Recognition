#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "bmp_header.h"
#include "input_output.h"
#include "def.h"




/*
	Citeste de din fisier si schimba parametrii
	pentru a putea fi utilizati mai departe
*/
char* read(pixel *change_to, int *v, int *v_size, FILE **img_b, FILE **bonus_img_b) {

	char img[IMG_NAME_MAX_LENGTH], bonus_img[IMG_NAME_MAX_LENGTH];


	//Citirea datelor de intrare

	int v_index = 0;

	char filename[] = "input.txt";

	FILE *in = fopen(filename, "rt");

	//Verificare daca a putut deschide fisierul
	if ( in == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", filename);
		return NULL;
	}

	//Citire numele imaginii

	fgets( img, IMG_NAME_MAX_LENGTH, in );

	//Sterge NEWLINE din capatul numelui
	strtok(img, "\n");



	//Citire culori ce trebuie schimbate
	fscanf( in, "%" SCNu8, &change_to->B );
	fscanf( in, "%" SCNu8, &change_to->G );
	fscanf( in, "%" SCNu8, &change_to->R );


	//Trecere la linia urmatoare
	fgetc(in);

	//Citire numere pentru task-ul 3
	char line[MAX_NUMBERS * 2];
	char delim[] = " ";

	fgets( line, MAX_NUMBERS * 2, in );

	strtok(line, "\n");

	char *p = strtok( line, delim );

	while ( p != NULL ) {
		if(!strcmp(p,"\n"))
			break;
		v[v_index] = atoi(p);
		v_index++;
		p = strtok(NULL, delim);
	}

	//v_index--;
	//Citire fisier bonus

	fgets( bonus_img, IMG_NAME_MAX_LENGTH, in );

	fclose(in);

	//Deschide fisierele binare si setaza numarul de cifre pentru task-ul 3

	*v_size = v_index;
	*img_b = fopen(img, "rb");

	if ( img_b == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", img);
		return NULL;
	}

	*bonus_img_b = fopen(bonus_img, "rb");

	if ( bonus_img_b == NULL ) {
		fprintf(stderr, "ERROR: Can't open file %s\n", bonus_img);
		return NULL;
	}

	char *a = (char*)(malloc(sizeof(img)));
	strcpy(a,img);
	
	return a;

}

void write_task(struct bmp_fileheader fh,struct bmp_infoheader ih,uint8_t *bmp_data,char *filename,int padding, int task){

	//Setez noul nume
	char new_filename[IMG_NAME_MAX_LENGTH];
	strcpy(new_filename,filename);
	char *p2 = strtok(new_filename,".");
	switch(task){
		case 1:
				strcat(p2,"_task1.bmp");
				break;
		case 3:
				strcat(p2,"_task3.bmp");
				break;
		default:
				break;
	}
	
		
	
	FILE *out;
	out = fopen(p2,"wb");
	fwrite(&fh,sizeof(struct bmp_fileheader),1,out);
	fwrite(&ih,sizeof(struct bmp_infoheader),1,out);
	fseek(out,fh.imageDataOffset,SEEK_SET);
	fwrite(bmp_data,sizeof(uint8_t),ih.biSizeImage+ih.height*padding,out);
	fclose(out);


}


void print_number(char* filename, int n){

	//Setez noul nume
	char new_filename[IMG_NAME_MAX_LENGTH];
	strcpy(new_filename,filename);
	char *p2 = strtok(new_filename,".");
	strcat(p2,"_task2.txt");

	FILE *out;
	out = fopen(p2,"a");
	fprintf(out, "%d", n);
	fclose(out);


}
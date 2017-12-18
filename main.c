#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "bmp_header.h"
#include "input_output.h"
#include "def.h"


void task1_change_colors(pixel change_to, uint8_t* bmp_data,int padding, int height, int width){

	for(int i =0;i<height;i++){
		for(int j=0;j<width*3;j+=3){

			if(bmp_data[i*(width*3 + padding)+j] != 255 &&
				bmp_data[i*(width*3 + padding)+j+1] != 255 &&
				bmp_data[i*(width*3 + padding)+j+2] != 255){

				bmp_data[i*(width*3 + padding)+j] = change_to.B;
				bmp_data[i*(width*3 + padding)+j+1] = change_to.G; 
				bmp_data[i*(width*3 + padding)+j+2] =  change_to.R;

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
	int padding = 4 -  (3*ih.width)%4;
	if(padding == 4) padding = 0;

	//Aloc memorie
	bmp_data = (uint8_t*) malloc(ih.biSizeImage+padding*ih.width);
	//Citesc Datele
	fread(bmp_data, sizeof(uint8_t), ih.biSizeImage+padding*ih.width, img);

	//TASK 1
	task1_change_colors(change_to,bmp_data,padding,ih.height,ih.width);

	write_task1(fh, ih, bmp_data, filename, padding);

	//Dealocare de memorie pentru fisiere
	free(img);
	free(bonus_img);

	return 0;
}
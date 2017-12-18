#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmp_header.h"
#include "input_output.h"
#include "def.h"


int main()
{

	pixel change_to;
	int v[MAX_NUMBERS], v_size = 0;
	FILE *img, *bonus_img;
	char filename[IMG_NAME_MAX_LENGTH];
	pixel *bmp_data;

	struct bmp_fileheader fh; //File Header
	struct bmp_infoheader ih; //Info Header


	//Alocare memorie pentru cele doua fisiere binare
	img = (FILE*) malloc(1000);
	bonus_img = (FILE*) malloc(1000);

	strcpy(filename,read(&change_to, v, &v_size, &img, &bonus_img));

		//Setez FileHeader si InfoHeader 
		fread(&fh, sizeof(struct bmp_fileheader), 1, img);
		fread(&ih, sizeof(struct bmp_infoheader), 1, img);

		//Pointez catre inceputul zonei de date
		fseek(img, fh.imageDataOffset, SEEK_SET);

		//Aloc memorie
		bmp_data = (pixel*) malloc(ih.biSizeImage);

		fread(bmp_data,sizeof(pixel),ih.biSizeImage/3,img);
	

	for(int i=0;i<ih.biSizeImage/3;i++){
			if(bmp_data[i].B != 255 &&
				bmp_data[i].G != 255 &&
				bmp_data[i].R != 255){
				
				bmp_data[i].B = change_to.B;
				bmp_data[i].G = change_to.G;
				bmp_data[i].R = change_to.R;
			}
	}

	//char *a = task1_rename(filename);
	//printf("%s\n", a);
	
	
	write_task1(fh,ih,bmp_data,filename);

	//Dealocare de memorie pentru fisiere
	free(img);
	free(bonus_img);

	return 0;
}
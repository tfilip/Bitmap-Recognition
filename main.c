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


	struct bmp_fileheader fh; //File Header
	struct bmp_infoheader ih; //Info Header


	//Alocare memorie pentru cele doua fisiere binare
	img = (FILE*) malloc(1000);
	bonus_img = (FILE*) malloc(1000);

	if ( read(&change_to, v, &v_size, &img, &bonus_img) == 0) {

		fread(&fh, sizeof(struct bmp_fileheader), 1, img);
		fread(&ih, sizeof(struct bmp_infoheader), 1, img);

		
		


	}





	//Dealocare de memorie pentru fisiere
	free(img);
	free(bonus_img);

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmp_header.h"
#include "input_output.h"
#include "def.h"


int main()
{

	Color change_to;
	int v[MAX_NUMBERS], v_size = 0;
	FILE *img, *bonus_img;

	//Alocare memorie pentru cele doua fisiere binare
	img = (FILE*) malloc(1000);
	bonus_img = (FILE*) malloc(1000);

	if ( read(&change_to, v, &v_size, img, bonus_img) == 0) {
		printf("SUCCES\n");
	}


	//Dealocare de memorie pentru fisiere
	free(img);
	free(bonus_img);

	return 0;
}
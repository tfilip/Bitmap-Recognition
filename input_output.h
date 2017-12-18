#include <stdio.h>
#include "pixel.h"

char* read(pixel *change_to, int *v, int *v_size, FILE **img_b, FILE **bonus_img_b);
void write_task1(struct bmp_fileheader fh,struct bmp_infoheader ih,uint8_t *bmp_data,char *filename,int padding);
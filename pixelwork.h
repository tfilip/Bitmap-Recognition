#include<stdint.h>
#include "numbers.h"

int isSet(uint8_t B, uint8_t G, uint8_t R);
void bmp_set_horizontal(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start, pixel color);
void bmp_set_vertical(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start, pixel color);
int vline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
int hline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
void swap_numbers(uint8_t* bmp_data, int padding, int width, int i1, int j1, int i2, int j2, int n1, int n2, pixel p1, pixel p2);
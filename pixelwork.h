#include<stdint.h>

int isSet(uint8_t B, uint8_t G, uint8_t R);
void bmp_set_horizontal(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
int hline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
void bmp_set_vertical(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
int vline_set(uint8_t* bmp_data, int padding, int width, int i, int j, int k, int nr, int start);
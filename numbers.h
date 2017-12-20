#include "pixel.h"

void drawZero(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawOne(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawTwo(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawThree(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawFour(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawFive(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawSix(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawSeven(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawEight(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void drawNine(uint8_t* bmp_data, int padding, int width, int i, int j, pixel color);
void delNumber(uint8_t* bmp_data, int padding, int width, int i , int j);
int isZero(uint8_t* bmp_data, int padding, int width, int i, int j);

int isOne(uint8_t* bmp_data, int padding, int width, int i, int j);

int isTwo(uint8_t* bmp_data, int padding, int width, int i, int j);

int isThree(uint8_t* bmp_data, int padding, int width, int i, int j);

int isFour(uint8_t* bmp_data, int padding, int width, int i, int j);

int isFive(uint8_t* bmp_data, int padding, int width, int i, int j);

int isSix(uint8_t* bmp_data, int padding, int width, int i, int j);

int isSeven(uint8_t* bmp_data, int padding, int width, int i, int j);

int isEight(uint8_t* bmp_data, int padding, int width, int i, int j);


int isNine(uint8_t* bmp_data, int padding, int width, int i, int j);
int getNumber(uint8_t* bmp_data, int padding, int width, int i, int j);
pixel getColor(uint8_t* bmp_data, int padding, int width, int i, int j);
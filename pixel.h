//Tepes-Onea Filip 312CD

#include <stdint.h>

#pragma pack(1)

/*

	Utilizat pentru salvarea culoriilor.
	Folosesc type-ul uint8_t deoarece acestea 
	sunt salvate pe un singur byte

*/

typedef uint8_t byte;

typedef struct
{
	byte B;
	byte G;
	byte R;

} pixel;


#pragma pack()
/*This program is used to swap bytes in an integer*/
/*for example if Input: 0xaabbccdd ; Output should be: 0xccddaabb*/

#include <stdio.h>

int main()
{
   	int number,left_shift,right_shift;
   
	number = 0xaabbccdd;

	printf("\nNumber before swapping:%x",number);
        
	/*Left shifting will give us 0xccdd0000 and performing a bitwise and with 0xffff0000 will give 0xccdd0000*/
	left_shift = (number<<16)&(0xffff0000);

	/*Right shifting will give us 0xffffaabb and performing a bitwise and with 0x0000ffff will give 0x0000aabb*/
   	right_shift = (number>>16)&(0x0000ffff);

	/*Bitwise Or between right and left shift*/
   	number=(left_shift|right_shift);
   
   	printf("\nNumber after swapping:%x\n",number);
   
    	return 0;
}

/*This program converts a number to decimal,binary and hexadecimal format. It also prints number of high bits in the binary format. In order t exit, the input should be E.*/

#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void decimal_to_binary(int);/*Function Declaration*/
int counter=0;

int main()
{
    	char string[20];
	int jLoop,count;

	/*Continuous Loop asking Input from the User*/
    	while(1)
    	{

    		int num;
		
   		label:  printf("\nEnter a number:");
    		scanf("%s",string);
		
		count=0;
		/*Counting the number of integers in the input*/
    		for(jLoop=0;jLoop<strlen(string);jLoop++)
    		{
        		if(isdigit(string[jLoop]))
        		{
            			count++;
        		}
    		}

		/*Checking if the input string is an integer*/
    		if(count == strlen(string))
    		{
        		num = atoi(string);
        		printf("\nThe number in decimal format: %d",num);
        		printf("\nThe number in binary format: ");
        		decimal_to_binary(num);
        		printf("\nThe number in hexadecimal format: %x",num);
        		printf("\nThe number of high bits is: %d\n",counter);
    		}
    		else
    		{
			/*Checking if the input is "E", in that case, the program exits*/
        		if(strcmp(string,"E") == 0)
        		{
         			exit(1);
        		}

			/*In case of invalid inputs, user is asked to input again*/
        		else
        		{
           			printf("\nInvalid Input format. Enter a valid input\n");
           			goto label;
        		}
    		}
    	}

    	return 0;
}

/*This function converts decimal to binary and also counts the number of high bits in the number*/

void decimal_to_binary(int number)
{
    	int rem,iLoop=0,jLoop,bin_arr[50];

	/*Storing the remainders after dividing the number consecutively by 2 in an array named bin_arr*/
    	while(number!=0)
    	{
        	rem=number%2;
        	number=number/2;
        	bin_arr[iLoop]=rem;
        	iLoop++;
    	}

	/*Printing the number in binary format backwards*/
    	for(jLoop=iLoop-1;jLoop>=0;jLoop--)
    	{
        	printf("%d",bin_arr[jLoop]);
    	}

	/*Counting the number of high(1) bits in the binary format*/
    	for(jLoop=0;jLoop<iLoop;jLoop++)
    	{
        	if(bin_arr[jLoop]==1)
        	{
            		counter++;
        	}
    	}
}




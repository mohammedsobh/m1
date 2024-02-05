/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file <Add File Name>
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
  print_statistics(test,SIZE);

}


void print_statistics(unsigned char *arr,unsigned char Len){
	print_array(arr,Len);
	printf("the median value: %d\n", find_median(arr,Len));
    printf("the mean: %f\n", find_mean(arr,Len));
	printf("the maximum: %d\n" ,find_maximum(arr,Len));
	printf("the minimum: %d\n" , find_minimum(arr,Len));
	sort_array(arr,Len);
	print_array(arr,Len);
}

void print_array(unsigned char *arr,unsigned char Len){
	printf("[");
	for (int i = 0; i < Len; i++)
	{
		printf("%d ,",arr[i]);
	}
	printf("]\n");
}

unsigned char find_median(unsigned char *arr,unsigned char Len){
	unsigned char Min = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int x = i; x < Len - 1; x++){
			if (arr[x] > arr[x + 1])
			{
                Min = arr[x];
                arr[x] = arr[x + 1];
                arr[x + 1] = Min;
			}
		}

	}
	unsigned char MidPos = (unsigned char)(Len/2);
	return arr[MidPos];
}

float find_mean(unsigned char *arr,unsigned char Len){
    unsigned char Sum = 0;
    for (int x = 0; x < Len ; x++){
			Sum += arr[x];
		}
    return Sum/Len;
}
unsigned char find_maximum(unsigned char *arr,unsigned char Len){
    unsigned char Min = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int x = i; x < Len - 1; x++){
			if (arr[x] > arr[x + 1])
			{
                Min = arr[x];
                arr[x] = arr[x + 1];
                arr[x + 1] = Min;
			}
		}

	}
	return arr[Len-1];
}

unsigned char find_minimum(unsigned char *arr,unsigned char Len){
    unsigned char Min = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int x = i; x < Len - 1; x++){
			if (arr[x] > arr[x + 1])
			{
                Min = arr[x];
                arr[x] = arr[x + 1];
                arr[x + 1] = Min;
			}
		}

	}
	return arr[0];
}
void sort_array(unsigned char *arr,unsigned char Len){
    unsigned char Min = 0;
	for (int i = 0; i < Len - 1; i++)
	{
		for (int x = i; x < Len - 1; x++){
			if (arr[x] > arr[x + 1])
			{
                Min = arr[x];
                arr[x] = arr[x + 1];
                arr[x + 1] = Min;
			}
		}

	}
}
/* Add other Implementation File Code Here */

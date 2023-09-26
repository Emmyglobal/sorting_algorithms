#include <stdio.h>
//#include "sort.h"
#include <stddef.h>

int sortt(int *, int,int);
void print_array(int *in, size_t siz)
{
	int i;
	for (i = 0; i < siz; i++)
		printf("%d, ", in[i]);
	printf("\n");
}
int main()
{
//int array[13] = {2,4,8,4,10,9,3,8,0, 10, 1, 2, 77};
int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7,1,2,3};
	size_t siz = 13;
	int stop;

	print_array(array, siz);
	stop = sortt(array,8, 13);
	print_array(array, 13);
	printf("%d \n", stop);
	return 0;
}
int sortt(int *ar, int start, int s)
{
	int i, j, piv = ((s - start) % 2 == 0) ? (s - start) / 2 : ((s-start) -1) / 2, temp;


	printf("%d \n", ar[start]);
	piv = start + piv;
	printf("%d \n", s - start);
	printf("%d \n", ar[piv]);
	for (i = start; i < piv; i++)
	{
	
		if (ar[i] > ar[piv])
		{
			for (j = 0; j < piv; j++)
			{
				if (ar[s - 1 - j] < ar[piv])
				{
					temp = ar[i];
					ar[i] = ar[s - 1 -j];
					ar[s - 1 - j] = temp;
					break;
				}
			}
			printf("%d - %d\n", j, piv);
			if (j == piv)
			{
				temp = ar[piv];
				ar[piv] = ar[i];
				ar[i] = temp;
				break;
			}
		}
	}
	for (j = 0; i + j < s; j++)
	{
		printf("%d - %d\n", ar[i+j],ar[i]);
		if (ar[i + j] < ar[i])
		{
			temp = ar[i];
			ar[i] = ar[i + j];
			ar[i + j] = temp;
			i = i + j;
			j = 0;
		}
	}
	return(i);
}

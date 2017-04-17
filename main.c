#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

int i = 0;
int n = 0;
int temp = 0;

void Input_data(int array_data[10])
{
	/* Input data of array*/
	do {
		printf("Nhap so luong phan tu co trong mang <tu 3 den 10 phan tu>\n");
		scanf("%d", &n);
		flushall();
	} while(n < 3 || n > 10);
	
	printf("Nhap gia tri cua cac phan tu co trong mang <tu 0 den 99>\n");
	for (i = 0; i < n; i++)
	{
		printf("array_data[%d] ", i);
		scanf("%d", &array_data[i]);	
		//printf("%d", array_data[i]);
		flushall();
		if ((array_data[i] >= 0 && array_data[i] <= 99))
		{
			;
		}
		else
		{
			printf("Ban da nhap sai, vui long nhap lai.\n");
			i--;
		}
		
	}

	
	/* Print all of index in your array */
	printf("Mang ban da nhap:\n");
	for(i = 0; i < n; i++)
	{
		printf("%d\t", array_data[i]);
	}
}

int Sum_array(int array_data[10])
{
	int sum=0;
	/* Print sum of all input */
	for(i = 0; i < n; i++)
	{
		sum += array_data[i];
	}
	printf("\nTong gia tri cua cac phan tu ban da nhap: %d\n", sum);
	return sum;
}

void Sumfront(int array_data[10],int sumfront_array[9])
{
	/* Calculate sumfront */
	sumfront_array[0]=0;

	for (i = 0; i < n-1; i++)
	{
		sumfront_array[i] = sumfront_array[temp] + array_data[i];
		temp = i;
	}
	temp = 0;	//reset temp

	/* Print sumfront */		//function for test, not include
	printf("\nSum Front:\n");
	for(i = 0; i < n-1; i++)
	{
		printf("%d\t", sumfront_array[i]);
	}
}

void Sumback(int sum,int sumfront_array[9],int sumback_array[9])
{
	/* Calculate sumback */
	sumback_array[0]=0;
	for (i = 0; i < (n-1); i++)
	{
			sumback_array[i] = sum - sumfront_array[i];
	}

	/* Print sumback */			//function for test, not include
	printf("\nSum Back:\n");
	for(i = 0; i < n-1; i++)
	{
		printf("%d\t", sumback_array[i]);
	}
}

int Compare(int sumfront_array[9],int sumback_array[9])
{
	int min;
	/* Find sub-group and index of min sub-group */
	for (i = 0; i <= (n-2); i++)
	{
		if (i == 0)
		{
			min = abs(sumfront_array[i] - sumback_array[i]);
			//printf("\nMin sub-group0: %d", min);	//for test, not include
		}
		else
		{
			if ( abs(sumfront_array[i] - sumback_array[i]) < min)   //change < to <=
			{
				min = abs(sumfront_array[i] - sumback_array[i]);
			//	printf("\nMin sub-group1: %d", min);	//for test, not include
				temp = i;
			}
			else
			{
				//min = min;		//just for clear, not include
				//printf("\nMin sub-group2: %d", min);	//for test, not include
				//temp = i;
			}
		}
	}
	return min;
}

void main(){
	int Min=0,Sum=0;
	int SeriesNumber[10],group1[9],group2[9];
	int position=0;

	Input_data(SeriesNumber);
	Sum=Sum_array(SeriesNumber);
	Sumfront(SeriesNumber,group1);
	Sumback(Sum,group1,group2);
	Min=Compare(group1,group2);
	position=temp;
	/* Print min sub-group and Min index of min sub-group */
	printf("\nMin sub-group: %d", Min);
	printf("\nMIN's position: %d", (position+1));	//change position in array to position in nature.
	printf("\nMin index of Min Group: %d\t%d", group1[position], group2[position]);

	_getch();
}
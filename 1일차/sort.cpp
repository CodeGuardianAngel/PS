#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100'000;

int origin[MAX];
int arr1[MAX];
int arr2[MAX];	// 4 * 100'000 byte = 390.625 Kbyte = 0.38 MByte

void selection_sort(int arr[], int size)
{
	// Big(N * N) = O(N^2) => 100'000 * 100'000 = 100억 -> (10억 1초)
	// N개
	for (int i = 0; i < size; i++)
	{
		// 5개
		int min_val = arr[i];
		int min_idx = i;

		// N - 1 => N
		for (int j = i + 1 ; j < MAX; j++)
		{
			// 4개
			if (min_val > arr[j])
			{
				min_val = arr[j];
				min_idx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int temp_arr[MAX];
// O(N Log N) => 100'000 * 17 = 1,700,000
void merge(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	int k = left;
	int i = left, j = mid + 1;
	int e1 = mid;
	int e2 = right;

	while (i <= e1 && j <= e2)
	{
		if (arr[i] > arr[j])
		{
			temp_arr[k] = arr[j];
			j++;
		}else 
		{
			temp_arr[k] = arr[i];
			i++;
		}
		k++;
	}

	while (i <= e1)
	{
		temp_arr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e2)
	{
		temp_arr[k] = arr[j];
		j++;
		k++;
	}

	for (int i = left; i <= right; i++)
	{
		 arr[i] = temp_arr[i];
	}
}

void divide(int arr[], int left,  int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		divide(arr, left, mid);
		divide(arr, mid + 1, right);
		merge(arr, left, right);
	}
}

void merge_sort(int arr[], int size)
{
	divide(arr, 0, size - 1);
}


int main()
{
	for (int i = 0; i < MAX; i++)
	{
		origin[i] = rand() % 100;
		arr1[i] = arr2[i] = origin[i];
		// printf("%d ", origin[i]);
	}
	printf("\n");

	time_t pre, end;
	printf("=== selection sort ===\n");
	pre = clock();
	// selection_sort(arr1, MAX);
	end = clock() - pre;
	printf("%d\n", end);



	printf("%d", sizeof(arr1));

	//for (int i = 0; i < MAX; i++)
	//{
	//	printf("%d ", arr1[i]);
	//}
	
	printf("\n");
	printf("=== merge sort ===\n");
	pre = clock();
	merge_sort(arr2, MAX);
	end = clock() - pre;
	printf("%d\n", end);
	/*for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr2[i]);
	}*/
}
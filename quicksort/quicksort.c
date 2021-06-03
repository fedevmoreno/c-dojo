/*
**	Randomized Algorithms 
**
**	Quick Sort Algorithm
**
**	COMPLEXITY
**
**	Worst-case performance: O(n^2)
**	Worst-case performance: O(n log n)
**	Average performance: O(n log n)
**
**	TO DO:
**	
**	1) Choice a magic number you think is the middle of the list.
**	
**	2) If n is lower or iquals to the magic number,
**	then is stored in**	the left side,
**	otherwise n is stored in the right side.
*/

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int arr[], int left, int right)
{
	int	pivot;

	pivot = arr[left];
	while (1)
	{
		while (arr[left] < pivot)
		{
			left++;
		}
		while (arr[right] > pivot)
		{
			right--;
		}
		if (left >= right)
		{
			return (right);
		}
		else
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}

void	quicksort(int arr[], int left, int right)
{
	int	index_partition;

	if (left < right)
	{
		index_partition = partition(arr, left, right);
		quicksort(arr, left, index_partition);
		quicksort(arr, index_partition + 1, right);
	}
}

int	main(void)
{
	int	arr[] = {28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
	int	len;
	int	x;

	x = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	printf("ARRAY:\n");
	while (x < len)
	{
		printf("%d ", arr[x]);
		x++;
	}
	printf("\n");
	quicksort(arr, 0, len - 1);
	printf("SORTED ARRAY:\n");
	x = 0;
	while (x < len)
	{
		printf("%d ", arr[x]);
		x++;
	}
	return (0);
}

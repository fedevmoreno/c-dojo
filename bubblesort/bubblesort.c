#include <stdio.h>
void	fd_bubblesort(int arr[], size_t len)
{
	int		tmp;
	size_t	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

int	main(void)
{
	int		arr[] = {4, 2, 0, 5, 1, 9};
	size_t	i;
	size_t	len;

	len = 6;
	i = 0;
	fd_bubblesort(arr, len);
	while (i < len)
	{
		if (i == len - 1)
		{
			printf("%d\n", arr[i]);
			return (0);
		}
		printf("%d, ", arr[i]);
		i++;
	}
	return (0);
}

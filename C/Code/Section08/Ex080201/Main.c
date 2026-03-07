// main.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
	size_t i;
	int* Nums = (int*)malloc(10 * sizeof(int));
	if (NULL == Nums)
	{
		return 0;
	}

	for (i = 0; i < 10; ++i)
	{
		Nums[i] = i * 10;
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%d ", Nums[i]);
	}

	free(Nums);
	Nums = NULL;

	if (NULL != Nums)
	{
		//TODO
	}

	return 0;
}
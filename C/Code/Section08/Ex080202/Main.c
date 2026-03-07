
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t i;
	int* Nums;

	Nums = (int*)malloc(10 * sizeof(int));
	if (NULL == Nums)
	{
		return 1;
	}

	for (i = 0; i < 10; ++i)
	{
		Nums[i] = 10 * (i + 1);
	}

	free(Nums);
	Nums = NULL;

	return 0;
}
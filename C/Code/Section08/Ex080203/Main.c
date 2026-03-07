
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* APNums;          /* 메모리 할당된 포인터(allocated pointer)라는 뜻에서 접두어 AP-를 붙히는 것도 아주 좋음.
		                   이런 코딩 컨벤션은, 일하거나 배우는 곳의 코딩 컨벤션을 따르면 됨. */
	int* TemPtr;
	size_t i;

	APNums = (int*)malloc(10 * sizeof(int));
	if (NULL == APNums)
	{
		return 0;
	}

	TemPtr = APNums;

	for (i = 0; i < 10; ++i)
	{
		*TemPtr++ = 10 * (i + 1);
	}

	free(APNums);
	APNums = NULL;

	return 0;
}
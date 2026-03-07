// ±Ì¿∫ ∫πªÁ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pointers
{
	int* PtrToInt1;
	int* PtrToInt2;
} Pointers_t;

int main(void)
{
	int X = 10;
	int Y = 20;
	Pointers_t Original;
	Pointers_t Clone;

	Original.PtrToInt1 = &X;
	Original.PtrToInt2 = &Y;

	//Clone = Original;
	Clone.PtrToInt1 = (int*)malloc(sizeof(int));
	memcpy(Clone.PtrToInt1, Original.PtrToInt1, sizeof(int));

	Clone.PtrToInt2 = (int*)malloc(sizeof(int));
	memcpy(Clone.PtrToInt2, Original.PtrToInt2, sizeof(int));

	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);
	*Clone.PtrToInt1 = 99;
	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);

	free(Clone.PtrToInt1);
	Clone.PtrToInt1 = NULL;
	free(Clone.PtrToInt2);
	Clone.PtrToInt2 = NULL;

	return 0;
}

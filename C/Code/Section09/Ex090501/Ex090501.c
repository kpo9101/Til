// ¾èÀº º¹»ç

#include <stdio.h>

struct Pointers
{
	int* PtrToInt1;
	int* PtrToInt2;
};
typedef struct Pointers Pointers_t;

int main(void)
{
	int X = 10;
	int Y = 20;
	Pointers_t Original;
	Pointers_t Clone;

	Original.PtrToInt1 = &X;
	Original.PtrToInt2 = &Y;

	Clone = Original;

	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);
	*Clone.PtrToInt1 = 99;
	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);

	return 0;
}

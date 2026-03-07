#include <stdlib.h>

struct Human
{
	float Height;
	float Weight;
	size_t Age;
};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));

	free(Park);
	Park = NULL;

	return 0;
}
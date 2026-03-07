// ¸â¹ö ÇÔ¼ö 1

#include <stdio.h>
#include <stdlib.h>

struct Human
{
	float Height;

	float Weight;

	size_t Age;

	void SayHello(void)
	{
		printf("Hello!\n");

		return;
	}

};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));

	Park->SayHello();

	free(Park);
	Park = NULL;

	return 0;
}

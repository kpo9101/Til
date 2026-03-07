// 멤버 함수 2 [중요 샘플 코드]

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

	void SayMyInfo(void)
	{
		printf("My Height is %.1f.\n", Height);
		printf("My Weight is %1f.\n", Weight);
		printf("y age is %zu.\n\n", Age);

		return;
	}
};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));
	Park->Height = 173.f;
	Park->Weight = 70.f;
	Park->Age = 19;

	Park->SayHello();
	Park->SayMyInfo();

	free(Park);
	Park = NULL;

	return 0;
}
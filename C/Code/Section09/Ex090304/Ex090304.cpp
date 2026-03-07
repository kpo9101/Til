// 클래스 만들어보기
//내가 임의로 캐릭터로 만들어본 것

#include <stdio.h>
#include <stdlib.h>

struct Character
{
	size_t LEVEL;

	size_t HP;

	size_t MP;

	void SayHello(void)
	{
		printf("Hi!\n");

		return;
	}

	void SayMyInfo(void)
	{
		printf("My LEVEL is %.zu.\n", LEVEL);
		printf("My HP is %.zu.\n", HP);
		printf("My MP is %.zu.\n\n", MP);

		return;
	}

};
typedef struct Character Character_t;

int main(void)
{
	Character_t* Ark = (Character_t*)malloc(1 * sizeof(Character_t));

	if (Ark == NULL)
	{
		printf("sdad");
		return 0;
	}

	Ark->LEVEL = 250;
	Ark->HP = 100;
	Ark->MP = 200;

	Ark->SayHello();
	Ark->SayMyInfo();

	free(Ark);
	Ark = NULL;

	return 0;
}
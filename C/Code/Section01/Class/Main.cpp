// Main.cpp

#define _CRT_SECURE_NO_WARNINGS 

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

/*
Ark->LEVEL = 250;
	Ark->HP = 100;
	Ark->MP = 200;
*/	
/*if (Ark == NULL)
{
	printf("sdad");
	return 0;
}
*/
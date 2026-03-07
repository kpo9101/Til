// enum 2

#include <stdio.h>

enum EChamp
{
	CHAMP_MISSFORTUNE,
	CHAMP_MALFIGHT,
	CHAMP_BLITZCRANK,
	CHAMP_JAX,
	CHAMP_SYNDRA
};

enum ERole
{
	ROLE_TOP,
	ROLE_MID,
	ROLE_JUNGLE,
	ROLE_BOTTOM,
	ROLE_SUPPORTER
};

int main(void)
{
	enum EChamp MyChamp = CHAMP_BLITZCRANK;
	enum ERole MyRole = ROLE_SUPPORTER;

	printf("MyChamp: %d\n", MyChamp);
	printf("MyRole: %d\n", MyRole);

	MyRole = CHAMP_MISSFORTUNE;
	printf("MyRole: %d\n", MyRole);

	return 0;
}

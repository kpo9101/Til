// enum°ú typedef

#include <stdio.h>

enum ERole
{
	ROLE_TOP,
	ROLE_JUNGLE,
	ROLE_MID,
	ROLE_BOT,
	ROLE_SUP
};
typedef enum ERole ERole_t;

typedef enum EChamp
{
	CHAMP_LEESIN,
	CHAMP_MASTER_LEE,
	CHAMP_BLITZ_CRANK
} EChamp_t;

typedef enum
{
	TIER_BRONZE,
	TIER_SILVER,
	TIER_GOLD
} ETier_t;

int main(void)
{
	ERole_t MyRole = ROLE_SUP;
	EChamp_t MyChamp = CHAMP_BLITZ_CRANK;
	ETier_t MyTier = TIER_SILVER;

	return 0;
}

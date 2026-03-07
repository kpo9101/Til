// 구조체 배열

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};
typedef struct Date Date_t;

int main(void)
{
	Date_t Anniversaries[3];
	size_t i, ElementSize;

	Anniversaries[0].Year = 2000;
	Anniversaries[0].Month = 1;
	Anniversaries[0].Day = 1;

	Anniversaries[1].Year = 2010;
	Anniversaries[1].Month = 10;
	Anniversaries[1].Day = 10;

	Anniversaries[2].Year = 2020;
	Anniversaries[2].Month = 20;
	Anniversaries[2].Day = 20;

	for (i = 0; i < 3; ++i)
	{
		printf("anniversaries[%zu]: %d/%d/%d\n", i, Anniversaries[i].Year,
			Anniversaries[i].Month,
			Anniversaries[i].Day);
	}

	printf("sizeof(anniversaries[0]): %zu\n", sizeof(Anniversaries[0]));

	return 0;
}

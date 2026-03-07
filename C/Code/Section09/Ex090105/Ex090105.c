// Main.c

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};

void PrintBirthday(struct Date InBirthday);

int main(void)
{
	struct Date Birthday;

	PrintBirthday(Birthday);

	return 0;
}

void PrintBirthday(struct Date InBirthday)
{
	printf("%d/%d/%d\n", InBirthday.Year, InBirthday.Month, InBirthday.Day);
}

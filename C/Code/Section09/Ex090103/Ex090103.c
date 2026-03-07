//구조체 멤버 접근 연산자

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};

int main(void)
{
	struct Date Birthday;
	Birthday.Year = 2001;
	Birthday.Month = 9;
	Birthday.Day = 12;

	printf("%d/%d/%d\n", Birthday.Year, Birthday.Month, Birthday.Day);

	return 0;
}

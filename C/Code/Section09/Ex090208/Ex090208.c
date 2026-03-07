// 여러 개의 반환 값

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};
typedef struct Date Date_t;

Date_t GetToday(void);

int main(void)
{
	Date_t Today = { 0, };

	printf("Today: %d/%d/%d\n", Today.Year, Today.Month, Today.Day);

	Today = GetToday();

	printf("Today: %d/%d/%d\n", Today.Year, Today.Month, Today.Day);

	return 0;
}

Date_t GetToday(void)
{
	printf("GetToday() has been called.\n");

	Date_t Date;

	Date.Year = 2020;
	Date.Month = 7;
	Date.Day = 7;

	return Date;
}

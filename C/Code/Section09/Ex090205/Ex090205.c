// typedef와 함수 매개변수 자료형

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};
typedef struct Date Date_t;

void IncreaseYear(Date_t InDate);

int main(void)
{
	Date_t Today;
	Today.Year = 2021;
	Today.Month = 5;
	Today.Day = 26;

	printf("%d/%d/%d\n", Today.Year, Today.Month, Today.Day);
	IncreaseYear(Today);
	printf("%d/%d/%d\n", Today.Year, Today.Month, Today.Day);

	return 0;
}

void IncreaseYear(Date_t InDate)
{
	printf("IncreaseYear() has been called.\n");
	++InDate.Year;

	return;
}

// pointer to structure

#include <stdio.h>

struct Date
{
	int Year;
	int Month;
	int Day;
};
typedef struct Date Date_t;

void IncreaseYear(Date_t* InPtrToDate);

int main(void)
{
	Date_t Today;
	Today.Year = 2021;
	Today.Month = 5;
	Today.Day = 26;

	Date_t* PtrToToday = &Today;

	printf("%d/%d/%d\n", Today.Year, Today.Month, Today.Day);
	IncreaseYear(PtrToToday);
	printf("%d/%d/%d\n", Today.Year, Today.Month, Today.Day);

	return 0;
}

void IncreaseYear(Date_t* InPtrToDate)
{
	printf("IncreaseYear() has been called.\n");
	++(*InPtrToDate).Year;

	return;
}
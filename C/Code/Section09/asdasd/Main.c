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
    Birthday.Year = 2001;
    Birthday.Month = 9;
    Birthday.Day = 12;

    PrintBirthday(Birthday);

    return 0;
}

void PrintBirthday(struct Date InBirthday)
{
    printf("% d / % d / % d", InBirthday.Year, InBirthday.Month, InBirthday.Day);
}
// enum 1 [중요 샘플 코드]

#include <stdio.h>

enum Emonth
{
	MONTH_JAN = 1,
	MONTH_FEB = 2,
	MONTH_MAR = 3,
	MONTH_APR = 4
};

enum EASCII
{
	ASCII_A = 66,
	ASCII_B,
	ASCII_C,
	ASCII_D
};

int main(void)
{
	printf("This month's(%d) lucky character is %c.", 3, 66);

	int March = 3, B = 66;
	printf("This month's(%d) lucky character is %c.", March, B);

	printf("This month's(%d) lucky character is %c.", MONTH_MAR, ASCII_B);


	return 0;
}
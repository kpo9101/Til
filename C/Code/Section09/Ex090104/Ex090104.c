// 함수의 인자로 구조체 변수 전달 [중요 샘플 코드]

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
	struct Date Birthday = { 2024, 1, 13 }
	;
	Birthday.Year = 2024;
	Birthday.Month = 1;
	Birthday.Day = 13;
	// 구조체 변수 Birthday는 어느 메모리에 저장 될까요?.
	// 당연하게도 스택 메모리입니다. 다른 기본 자료형과 마찬가지입니다.
	// 초기화 하지 않으면 0이 아닌 쓰레기 값이 저장되어 있습니다.

	PrintBirthday(Birthday);

	return 0;
}

void PrintBirthday(struct Date InBirthday)
{
	printf("%d/%d/%d\n", InBirthday.Year, InBirthday.Month, InBirthday.Day);
}



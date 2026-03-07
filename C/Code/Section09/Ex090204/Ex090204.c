// 초기화 방법

typedef struct Date
{
	int Year;
	int Month;
	int Day;
} Date_t;

int main(void)
{
	Date_t Today = { 0, };
	/* 첫 번째 방법. */

	Date_t Tomorrow = { 7, 7, 2021 };
	/* 두 번째 방법. 요소 나열법. 실수할 여지가 있으니 사용에 주의합시다. */
	/* 나중에 누가 일,월,년 순으로 구조체 멤버변수 순서를 바꿔버리면 문제가 생길 수도 있습니다. */
	/* const 멤버 변수를 선언해서 사용할때도 요소 나열법이 유용합니다. */

	return 0;
}

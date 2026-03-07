### 지금까지 사용한 자료형은 모두 Built-In type.

언어에 내장된 기본 자료형. ex) char, int, …
근데 나만의 자료형이 필요하다면 어떻게 해야 될까요? 

ex) 주민등록번호(int), 이름(char[])을 모아놓고 Human 자료형을 만들고 싶습니다.
    그리고 Human Classmate[30];을 원합니다.
    지금까지 배운 내용이라면, 굳이 주민등록번호용 int 변수 30개
    이름용 문자배열 30개를 따로 선언해서 써야합니다.

### 구조체(Structure)

필요한 여러 자료형의 변수들을 한데 묶어서 하나의 자료형처럼 만들 수 있습니다.

아래와 같은 코드로 정의 가능합니다.
예제 코드를 반복적으로 클론 코딩 해보며 숙지해봅시다.

```c
struct 구조체명 
{
	자료형 변수명;
	...
};
```

### Ex090101) 구조체 정의

아래 소스코드를 따라서 작성해봅시다. 

```c
// Main.c

struct Date
{
	int Year;
	int Month;
	int Day;
};

int main(void)
{

	return 0;
}
```

### Ex090102) 구조체 변수 선언

```jsx
// Main.c

struct Date
{
	int Year;
	int Month;
	int Day;
};

int main(void)
{
	struct Date Birthday; // 사용자 정의 자료형 Date 변수 선언.

	return 0;
}

```

### Ex090103) 구조체 멤버 접근 연산자

. 연산자를 구조체 멤버 접근 연산자라고 합니다.
아래 소스코드를 따라서 작성해봅시다. 

```c
// Main.c

#include <stdio.h>

struct Date
{
	int Year;  // 구조체 Date의 멤버 Year.
	int Month; // 구조체 Date의 멤버 Month.
	int Day;   // 구조체 Date의 멤버 Day.
};

int main(void)
{
	struct Date Birthday;
	Birthday.Year = 2024;
	Birthday.Month = 1;
	Birthday.Day = 13;

	printf("%d/%d/%d\n", Birthday.Year, Birthday.Month, Birthday.Day);

	return 0;
}
```

### Ex090104) 함수의 인자로 구조체 변수 전달 [중요 샘플 코드]

아래 소스코드를 따라서 작성해봅시다.

```c
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
```

### Ex090105) 문제의 코드

아래 소스코드를 따라서 작성해봅시다. 문제가 될만한 부분이 어딘지 고민해보고 실행해봅시다.

```c
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

```

### [**참고**] 구조체와 객체지향 프로그래밍

나만의 자료형처럼 만든다는 것은 OOP에서 하나의 물체를 정의하는 것과 같습니다.
나만의 자료형으로 물체(객체)를 정의하고,
동적할당을 이용해서 물체를 생성 후 원하는 때에 해당 물체를 제거합니다.
이는 객체지향 프로그래밍과 유사합니다.

### 구조체도 기본 자료형처럼 쓰고 싶습니다.

변수를 선언 할 때, struct 키워드를 빼고 자료형만 적고 싶은데 어떻게 해야할까요?

### typedef

type definition의 약자. 이미 정의되어 있는 자료형에 새로운 별명을 지어줍니다.
ex) 선생님을 쌤, …

### Ex090201) typedef 1

아래 소스코드를 따라서 작성해봅시다.

```c
// Main.c

struct Date
{
	int Year;
	int Month;
	int Day;
};
typedef struct Date Date_t;

int main(void)
{
	Date_t Birthday;

	return 0;
}

```

### size_t 자료형도 사실 typedef unsigned long long size_t

_t가 접미사로 붙으면 typedef 되었다고 보면 됩니다.

### Ex090202) typedef 2

또다른 형태의 typedef. 아래 소스코드를 따라서 작성해봅시다.

```c
// Main.c

typedef struct Date
{
	int Year;
	int Month;
	int Day;
} Date_t;

int main(void)
{
	Date_t Birthday1;
	struct Date Birthday2;

	return 0;
}

```

### Ex090203) typedef 3

또다른 형태의 typedef. 아래 소스코드를 따라서 작성해봅시다.

```c
// Main.c

typedef struct
{
	int Year;
	int Month;
	int Day;
} Date_t;

int main(void)
{
	Date_t Birthday1;
	//struct Date Birthday2; // 컴파일 가능할까요?

	return 0;
}
```

### Ex090204) 초기화 방법

아래 소스코드를 따라서 작성해봅시다.

```c
// Main.c

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
```

### Ex090205) typedef와 함수 매개변수 자료형

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

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

```

### Ex090206) pointer to structure

구조체도 포인터 자료형이 가능합니다.

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

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
```

### 또다른 구조체 멤버 접근 연산자 ->

구조체 포인터에 역참조 연산자와 . 연산자를 합친 연산자가 -> 연산자.
우선순위도 1순위인 연산자라서 괄호 안쳐도 됩니다.

### Ex090207) -> 연산자

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

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
	//++(*InPtrToDate).Year;
	++InPtrToDate->Year;

	return;
}

```

### Ex090208) 여러 개의 반환 값

구조체를 함수 반환 자료형으로 쓰면 실질적으론 여러개의 값 반환 가능합니다.

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

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

```

### Ex090209) 구조체 배열

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

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

	ElementSize = (char*)&Anniversaries[1] - (char*)&Anniversaries[0];
	printf("ElementSize: %zu\n", ElementSize);

	return 0;
}
```

### Ex090301) Human 구조체

아래 코드를 따라서 작성해봅시다.
따라 작성한 소스코드의 실행 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.cpp

#include <stdlib.h>

struct Human
{
	float Height;

	float Weight;

	size_t Age;

};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));

	free(Park);
	Park = NULL;

	return 0;
}
```

### 객체지향 프로그래밍의 시작

위 예제가 별거 아닌것처럼 보이지만, 객체지향 프로그래밍의 시작과도 같습니다.
Park이라는 Human_t 객체를 만들어 낸 예제입니다.
객체지향 프로그래밍 언어는 객체 간의 상호작용에 중점을 둔 언어입니다.
지금까지 배운 내용으로 객체지향 프로그래밍을 살짝 맛보도록 해봅시다.

### 구조체에 멤버 변수만 선언 할 수 있는건 아닙니다.

객체지향 프로그래밍으로 넘어가면서 구조체에는 멤버 함수도 선언 할 수 있습니다.

### Ex090302) 멤버 함수 1

아래 코드를 따라서 작성해봅시다.
따라 작성한 소스코드의 실행 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.cpp

#include <stdio.h>
#include <stdlib.h>

struct Human
{
	float Height;

	float Weight;

	size_t Age;

	void SayHello(void)
	{
		printf("Hello!\n");

		return;
	}

};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));

	Park->SayHello();

	free(Park);
	Park = NULL;

	return 0;
}

```

### Ex090303) 멤버 함수 2 [중요 샘플 코드]

아래 코드를 따라서 작성해봅시다.
따라 작성한 소스코드의 실행 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.cpp

#include <stdio.h>
#include <stdlib.h>

struct Human
{
	float Height;

	float Weight;

	size_t Age;

	void SayHello(void)
	{
		printf("Hello!\n");

		return;
	}

	void SayMyInfo(void)
	{
		printf("My Height is %.1f.\n", Height);
		printf("My Weight is %.1f.\n", Weight);
		printf("My age is %zu.\n\n", Age);

		return;
	}

};
typedef struct Human Human_t;

int main(void)
{
	Human_t* Park = (Human_t*)malloc(1 * sizeof(Human_t));
	Park->Height = 173.f;
	Park->Weight = 70.f;
	Park->Age = 19;

	Park->SayHello();
	Park->SayMyInfo();

	free(Park);
	Park = NULL;

	return 0;
}

```

### Ex090304) 클래스 만들어보기

현실에 있는 어떤 사물을 구조체로 정의해보고, 그 구조체의 객체를 생성 및 해제 해봅시다.
예컨대, 비둘기라던가 고양이라던가…

### 구조체와 클래스가 완전히 똑같은건 아닙니다.

클래스는 접근 제한 지정자와 상속 등 다양한 기능들이 추가적으로 지원됩니다.

관련 내용은 객체지향 프로그래밍에서 배우게 됩니다.

### 열거형(Enummeration)

정수에 별명을 붙여서 소스코드를 이해하기 쉽게 해줍니다.

```c
enum 열거형명
{
	멤버01,
	멤버02,
	...
};
```

### Ex090401) enum 1 [**중요 샘플 코드**]

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

enum EMonth
{
	MONTH_JAN = 1,
	MONTH_FEB = 2,
	MONTH_MAR = 3,
	MONTH_APR = 4
};

enum EASCII
{
	ASCII_A = 65,
	ASCII_B,
	ASCII_C,
	ASCII_D
};

int main(void)
{
	printf("This month's(%d) lucky character is %c.", 3, 66);
		// 갑자기 숫자 3과 66이 튀어나오면 이해가 안될 수 있습니다.

	int March = 3, B = 66;
	printf("This month's(%d) lucky character is %c.", March, B);
		// 물론 위와 같이 하면 가독성이 좋아지긴 하나, 변수가 메모리 공간을 잡아먹음.

	printf("This month's(%d) lucky character is %c.", MONTH_MAR, ASCII_B);

	return 0;
}

```

### Ex090402) enum 2

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

enum EChamp
{
	CHAMP_MISSFORTUNE,
	CHAMP_MALFIGHT,
	CHAMP_BLITZCRANK,
	CHAMP_JAX,
	CHAMP_SYNDRA
};

enum ERole
{
	ROLE_TOP,
	ROLE_MID,
	ROLE_JUNGLE,
	ROLE_BOTTOM,
	ROLE_SUPPORTER
};

int main(void)
{
	enum EChamp MyChamp = CHAMP_BLITZCRANK;
	enum ERole MyRole = ROLE_SUPPORTER;

	printf("MyChamp: %d\n", MyChamp);
	printf("MyRole: %d\n", MyRole);

	MyRole = CHAMP_MISSFORTUNE;
	printf("MyRole: %d\n", MyRole);

	return 0;
}
```

### 열거형도 typedef가 가능합니다.

되도록이면 typedef를 이용해서 가독성을 더 끌어올려봅시다.

### Ex090403) enum과 typedef

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

enum ERole
{
	ROLE_TOP,
	ROLE_JUNGLE,
	ROLE_MID,
	ROLE_BOT,
	ROLE_SUP
};
typedef enum ERole ERole_t;

typedef enum EChamp
{
	CHAMP_LEESIN,
	CHAMP_MASTER_LEE,
	CHAMP_BLITZ_CRANK
} EChamp_t;

typedef enum
{
	TIER_BRONZE,
	TIER_SILVER,
	TIER_GOLD
} ETier_t;

int main(void)
{
	ERole_t MyRole = ROLE_SUP;
	EChamp_t MyChamp = CHAMP_BLITZ_CRANK;
	ETier_t MyTier = TIER_SILVER;

	return 0;
}

```

### Ex090501) 얕은 복사

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.
만약 문제가 있다면, 어디가 왜 문제인지 생각해봅시다.

```c
// Main.c

#include <stdio.h>

struct Pointers
{
	int* PtrToInt1;
	int* PtrToInt2;
};
typedef struct Pointers Pointers_t;

int main(void)
{
	int X = 10;
	int Y = 20;
	Pointers_t Original;
	Pointers_t Clone;

	Original.PtrToInt1 = &X;
	Original.PtrToInt2 = &Y;

	Clone = Original;

	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);
	*Clone.PtrToInt1 = 99;
	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);

	return 0;
}
```

### 얕은 복사(Shallow Copy)

실제 데이터가 아니라, 데이터가 들어있는 메모리 주소만 복사되는 것을 얕은 복사라고 합니다.
두 변수가 다른 이름을 가지지만, 같은 메모리 주소를 복사해서 가지고 있기 때문에,
실제 데이터는 하나만 존재하는 상태입니다.

### 깊은 복사(Deep Copy)

서로 다른 메모리 주소를 가지면서, 해당 메모리 주소에 적힌 값은 같은 상태.
값은 같지만, 실제 데이터가 두 개 존재하는 상태입니다.

```cpp
int A = 10;
int B = A; // 이건 얕은 복사일까요, 깊은 복사일까요?
```

### Ex090502) 깊은 복사

아래 소스코드를 따라서 작성해봅시다.
따라서 작성한 소스코드의 출력을 예측해봅시다. 예측한 결과와 실행한 결과를 비교해봅시다.
만약 문제가 있다면, 어디가 왜 문제인지 생각해봅시다.

```c
// Main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pointers
{
	int* PtrToInt1;
	int* PtrToInt2;
} Pointers_t;

int main(void)
{
	int X = 10;
	int Y = 20;
	Pointers_t Original;
	Pointers_t Clone;

	Original.PtrToInt1 = &X;
	Original.PtrToInt2 = &Y;

	//Clone = Original;
	Clone.PtrToInt1 = (int*)malloc(sizeof(int));
	memcpy(Clone.PtrToInt1, Original.PtrToInt1, sizeof(int));

	Clone.PtrToInt2 = (int*)malloc(sizeof(int));
	memcpy(Clone.PtrToInt2, Original.PtrToInt2, sizeof(int));

	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);
	*Clone.PtrToInt1 = 99;
	printf("Original: (%p)%d, %d\n", (void*)Original.PtrToInt1, *Original.PtrToInt1, *Original.PtrToInt2);
	printf("Clone   : (%p)%d, %d\n", (void*)Clone.PtrToInt1, *Clone.PtrToInt1, *Clone.PtrToInt2);

	free(Clone.PtrToInt1);
	Clone.PtrToInt1 = NULL;
	free(Clone.PtrToInt2);
	Clone.PtrToInt2 = NULL;

	return 0;
}

```

# End
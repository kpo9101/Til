### 포인터의 필요성

이전에 배열을 배우면서 5천만개 크기의 배열을 생각해봤습니다.
int 자료형의 크기는 4byte이므로, 5천만개 배열의 크기는 2억바이트입니다.
이걸 어딜가나 들고다니기엔 무리입니다.
배열은 연속적인 메모리에 저장된다고 했으니까 자료형과 시작 주소만 알면 될 것 같습니다.
시작 메모리 주소로 가서 자료형을 통해 얻은 한 칸의 크기로 모두 접근 가능하기 때문입니다.

![image.png](attachment:95f08483-7cf9-4cfe-b63a-a48e8bf8db78:image.png)

### “들고 다닌다”의 의미

main() 함수에서 대선투표결과가 저장된 배열이 있다고 해봅시다.
Count() 함수에서 개표해보고자 합니다.
즉, Count() 함수로 대선투표결과가 저장된 배열을 전달해야 합니다.
그럼 Count() 함수의 스택 프레임은 2억바이트를 할당해줘야 할까요? 들고다니기엔 무리입니다.

ex) 아파트 1채 10톤(2억 바이트) Vs. 아파트 1채의 소유문서 10g (시작 메모리 주소값. 8바이트)

실제 함수의 동작에서도 Count(int Votes[]) 함수를 호출하면 
시작 메모리 주소 값이 인자값으로 전달되게 됩니다.

근데 지금까지 배운 개념 중에는 메모리 주소를 저장할 수 있는 자료형은 없었습니다.
메모리 주소를 저장할 수 있는 변수인 포인터에 대해 알아봅시다.

### 포인터(Pointer) [중요 샘플 코드]

메모리 주소를 저장하기 위한 변수. 

```c
자료형 변수명 = 값;

자료형* 변수명 = 메모리주소값; // 자료형쪽에 Asterisk를 붙힙시다.
    // 변수명쪽에 Asterisk를 붙히면 뒤에서 배울 역참조 연산자와 심히 헷갈립니다.
```

### 포인터를 선언할 때 자료형은 왜 필요할까요?

해당 메모리 주소로 가서 얼마만큼의 크기로 읽어야 내 데이터인지 모르기 때문입니다.
자료형이 있어야 크기를 알 수 있습니다.
더 나아가서, 자료형 크기만큼 가면 다음 데이터를 얻을 수도 있습니다.

### [심화] 포인터를 공부하다보면.

단순히 “자료형* 변수명”으로 적혀있지 않은 경우가 종종 있습니다.
ex. const int*, int* const Add(), int* Ptrs[3], …
이런 경우에도 흔들리지 않는 방법이 있습니다.

### [심화] Right-Left Rule

<aside>
1️⃣

아래와 같이 적고, 변수명을 기준으로 일단 오른쪽(right)으로 읽어갑니다.
Var is ~

</aside>

<aside>
2️⃣

더이상 읽을게 없거나, 읽어 가는 방향 기준으로 닫는 괄호가 나온다면 
반대쪽(left)으로 읽습니다.

</aside>

<aside>
3️⃣

아래 기호들을 만날 때마다 다음과 같이 해석. (관사는 일단 생략)
*: Var is pointer to ~
[]: Var is array of ~
(): Var is function expecting ~ and returning ~

</aside>

### Ex070101) [심화] Right-Left Rule

아래 소스코드 속 주석 달린 코드들을 Right-Left Rule로 해석해보고,
그 아래 답지로 확인해봅시다.

```c
// Main.c

#include <stdio.h>

int Func(int A, int B); // 1번

int* (*WTF)(void); // 2번

int main(void)
{
	int* Var[3]; // 3번

	return 0;
}
```

- 답지
    
    ```c
    // Main.c
    
    #include <stdio.h>
    
    int Func(int A, int B); // 1번
    // 1. Func is ~
    // 2. Func is function expecting (int a, int b) and returning int
    
    int* (*WTF)(void); // 2번
    // 1. WTF is ~
    // 2. WTF is pointer to ~
    // 3. WTF is pointer to function expecting (void) and returning ~
    // 4. WTF is pointer to function expecting (void) returning pointer to ~
    // 5. WTF is pointer to function expecting (void) returning pointer to int.
    
    int main(void)
    {
    	int* Var[3]; // 3번
    	// 1. Var is ~
    	// 2. Var is array of ~
    	// 3. Var is array of pointer to ~
    	// 4. Var is array of pointer to int.
    
    	return 0;
    }
    
    ```
    

### 지난 시간에 메모리 주소를 저장하는 방법에 대해 배웠습니다.

그럼 메모리 주소는 어떻게 얻을까요?

### 주소 연산자(address-of operator) &

피연산자의 메모리 주소를 반환하는 연산자.
기호 &(Ampersand)를 사용합니다

### 사실 scanf() 함수에서 사용 했었던 주소 연산자

“~에”라고 해석하자고 배웠었습니다. 
사실은 변수 앞에 &를 붙혀서 그 변수의 메모리 주소를 얻은 것입니다.
해당 메모리 주소에 입력 받은 값을 저장할 수 있게된 것입니다.

### 메모리 주소를 얻을 수 있는 두 가지 방법

<aside>
1️⃣

주소 연산자

</aside>

<aside>
2️⃣

배열의 이름

```cpp
int Array[1024]; 
	// 여기서 Array는 메모리 주소를 저장한 변수. 특히 그 메모리 주소는 배열의 시작 메모리 주소.
```

</aside>

### 메모리 주소는 어떻게 얻는지 배웠습니다.

해당 메모리 주소에 저장 되어 있는 값을 알고 싶다면 어떻게 해야할까요?

### 역참조 연산자(indirection operator) *

피연산자로 포인터를 받아서, 해당 메모리 주소에 저장된 값을 읽거나 값을 수정할 때 사용하는 연산자.

### [**좋은습관**] “메모리 그리기”

포인터 관련 예제를 풀 때는 “메모리 그리기”를 해봅시다.
사각형을 그린 다음, 변수들을 적고 각 변수에 메모리 주소를 0x100번지부터 적어줍니다.
그 상태로 한 줄씩 소스코드를 분석해봅시다.

### Ex070201) 주소 연산자와 역참조 연산자 1 [중요 샘플 코드]

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

int main(void)
{
	int X = 10;
	int* PtrToX = &X;

	printf("%d\n", *PtrToX);

	*PtrToX = 100;

	printf("%d\n", *PtrToX);

	return 0;
}
```

### Ex070202) 주소 연산자와 역참조 연산자 2

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

int main(void)
{
	int X = 10;
	int* PtrToX = &X;

	printf("%d\n", *PtrToX);

	*PtrToX = *PtrToX * 2;

	printf("%d\n", *PtrToX);

	return 0;
}
```

### Ex070203) 주소 연산자와 역참조 연산자 3

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

int main(void)
{
	int X = 10, Y = 20;
	int* PtrToX = &X;

	printf("%d\n", *PtrToX);

	*PtrToX = *PtrToX * 2;
	PtrToX = &Y;

	printf("%d\n", *PtrToX);

	return 0;
}
```

### Ex070204) 주소 연산자와 역참조 연산자 4

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

[[**여기**](https://learn.microsoft.com/en-us/cpp/c-language/precedence-and-order-of-evaluation?view=msvc-170#:~:text=precedence%20and%20associativity.-,Precedence%20and%20associativity%20of%20C%20operators,-Expand%20table)]에서 연산자 우선순위와 결합법칙 표를 볼 수 있습니다.

```cpp
// Main.c

#include <stdio.h>

int main(void)
{
	int X = 10;
	int* PtrToX = &X;

	printf("%d\n", X);
	printf("%d\n", (*PtrToX)++);
	printf("%d\n", X);
	printf("%d\n", *PtrToX++); 
		// 문제 속의 문제. 계산될 연산자의 순서를 맞추시오.

	return 0;
}

```

### 포인터 Vs. 역참조 연산자 Vs. 곱셈 연산자

셋은 모두 *(Asterisk) 기호를 사용합니다.
포인터: 자료형 오른쪽에 붙습니다.
역참조 연산자: 피연산자가 한 개. 특히 피연산자로 메모리 주소를 받습니다.
곱셈 연산자: 피연산자가 두 개.

### Ex070205) 주소 출력

메모리 주소를 출력할 때 %X로 출력하는 것은 올바르지 않습니다.
형식 지정자 %p로 메모리 주소를 출력하는 게 올바르나,
void* 자료형으로 형변환이 필요합니다. 아래 소스코드를 따라서 작성 후 실행 해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Num = 100;
	int* PointerToNum = &Num;

	printf("Num:               %d\n", Num);
	printf("&Num:              %X\n", &Num);
	printf("&Num:              %p\n", (void*)&Num);
	printf("PointerToNum:      %X\n", PointerToNum);
	printf("PointerToNum:      %p\n", (void*)PointerToNum);
	printf("*PointerToNum:     %d\n", *PointerToNum);
	printf("*PointerToNum:     %d\n", *(&Num)); // 올바르진 않지만, 소거하는 식으로라도 이해해 보자.
	printf("(*PointerToNum)*2: %d\n", (*PointerToNum) * 2);

	return 0;
}

```

### 포인터의 단점

큰 데이터들의 시작 메모리 주소만으로 가볍게 공유할 수 있다는 점은 좋습니다.
다만, 공유 받은 사람이 착한 사람인지는 모릅니다.
해당 주소로 가서 들어있는 값을 마음대로 수정 할수도 있습니다.
아주 강력한 기능임과 동시에 그만큼 잘못쓰면 큰일 날 수도 있습니다.

### Ex070206) 다양한 자료형과 포인터

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	char Character = 'C';
	char* PtrToChar = &Character;
	short Num1 = 10;
	short* PtrToShort = &Num1;
	int Num2 = 11;
	int* PtrToInt = &Num2;
	float Num3 = 3.14f;
	float* PtrToFloat = &Num3;
	double Num4 = 3.141592;
	double* PtrToDouble = &Num4;

	printf("%p: %c(%d)\n", (void*)PtrToChar, Character, Character);
	printf("%p: %d\n", (void*)PtrToShort, Num1);
	printf("%p: %d\n", (void*)PtrToInt, Num2);
	printf("%p: %f\n", (void*)PtrToFloat, Num3);
	printf("%p: %f\n", (void*)PtrToDouble, Num4);

	return 0;
}
```

### Ex070207) char 자료형과 포인터

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	char Char1 = 'L';
	char Char2 = 'O';
	char* PtrToChar = &Char1;

	printf("%p: %c\n", (void*)PtrToChar, *PtrToChar);

	PtrToChar = &Char2;
	printf("%p: %c\n", (void*)PtrToChar, *PtrToChar);

	PtrToChar = &Char1;
	printf("%p: %c\n", (void*)PtrToChar, *PtrToChar);

	return 0;
}

```

### Ex070208) 뒤섞기 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Num1 = 10;
	int Num2 = 20;
	int Num3 = 30;

	int* Ptr1 = &Num1;
	int* Ptr2 = &Num2;
	int* Ptr3 = &Num3;

	Ptr3 = Ptr2;
	Ptr2 = Ptr1;
	Ptr1 = Ptr2;

	/* Q. num1을 가리키는 포인터는? */
	printf("%p: %d\n", (void*)Ptr1, *Ptr1);
	printf("%p: %d\n", (void*)Ptr2, *Ptr2);
	printf("%p: %d\n", (void*)Ptr3, *Ptr3);

	return 0;
}
```

### Ex070209) 뒤섞기 2

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
    int Num1 = 15;
    int Num2 = 30;
    int Num3 = 45;

    int* Ptr1 = &Num1;
    int* Ptr2 = &Num2;
    int* Ptr3 = &Num3;

    Ptr1 = Ptr2;
    Ptr2 = Ptr3;

    *Ptr3 *= 2;
    *Ptr1 += *Ptr3;
    *Ptr2 *= 2;

    /* Q. 출력 결과는? */
    printf("%d %d %d", Num1, Num2, Num3);

    return 0;
}
```

### 참조에 의한 호출 Vs. 값에 의한 호출

원본값이 바뀌냐 Vs. 안 바뀌냐.

함수 A가 함수 B를 호출 할 때, 인자를 전달하면서 호출한다고 가정해봅시다.
함수 B가 종료될 때 인자의 원본값도 바뀐다면 참조에 의한 호출입니다.
인자의 원본값이 바뀔 수 없다면 값에 의한 호출이라고 부릅니다. 

### Ex070210) Swap() 함수 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

void Swap1(int Op1, int Op2);

void Swap2(int* Op1, int* Op2);

int main(void)
{
	int Num1 = 10;
	int Num2 = 20;

	printf("before Swap1()\n");
	printf("Num1: %d, Num2: %d\n", Num1, Num2);

	Swap1(Num1, Num2);

	printf("after Swap1()\n");
	printf("Num1: %d, Num2: %d\n\n", Num1, Num2);

	printf("before Swap2()\n");
	printf("Num1: %d, Num2: %d\n", Num1, Num2);

	Swap2(&Num1, &Num2);

	printf("after Swap2()\n");
	printf("Num1: %d, Num2: %d\n\n", Num1, Num2);

	return 0;
}

void Swap1(int Op1, int Op2)
{
	int Temp;

	Temp = Op1;
	Op1 = Op2;
	Op2 = Temp;

	return;
}

void Swap2(int* Op1, int* Op2)
{
	int Temp;

	Temp = *Op1;
	*Op1 = *Op2;
	*Op2 = Temp;

	return;
}

```

### Ex070211) Swap() 함수 2

이전 예제에서 배운 Swap() 함수를 스스로 구현 후 호출 해 봅시다.

```
//입력1
3 2
```

```
//출력1
2 3
```

### Ex070212) GetMinMax() 함수

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>
#include <assert.h>

void GetMinMax(const size_t InArrayLength, const int InArray[], int* OutPtrToMin, int* OutPtrToMax);

int main(void)
{
    const int Nums[5] = { 7, 8, 1, 10, 5 };
    int ResultMin;
    int ResultMax;

    GetMinMax(5, Nums, &ResultMin, &ResultMax);

    printf("ResultMin: %d\n", ResultMin);
    printf("ResultMax: %d\n", ResultMax);

    return 0;
}

void GetMinMax(const size_t InArrayLength, const int InArray[], int* OutPtrToMin, int* OutPtrToMax)
{
    size_t i;

    *OutPtrToMin = InArray[0];
    *OutPtrToMax = InArray[0];

    for (i = 0; i < InArrayLength; ++i)
    {
        if (InArray[i] < *OutPtrToMin)
        {
            *OutPtrToMin = InArray[i];
        }

        if (*OutPtrToMax < InArray[i])
        {
            *OutPtrToMax = InArray[i];
        }
    }

    return;
}
```

### 포인터를 초기화 하려면 어떻게 하면 될까요?

변수를 초기화 할 때는 대부분 0으로 초기화를 했습니다.
포인터도 변수이긴 한데, 0처럼 깔끔하게 초기화하는 그런 값이 없을까요?

### NULL 포인터

#define NULL ((void*)0)
아무것도 가르키지 않는 포인터.

### Ex070301) NULL을 활용한 포인터 유효성 검사

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int* Ptr = NULL;

	if (NULL == Ptr)
	{
		printf("NULL == Ptr");
	}

	if (Ptr != NULL)
	{
		printf("Ptr is not the \"NULL pointer\"\n");
	}

	/* 간혹 다음과 같이 쓰기도 합니다. worst.*/
	if (Ptr)
	{
		printf("Ptr is not the \"NULL pointer\"\n");
	}

	/* 올바르지 않은 예들. 명시적인 부분에서 올바르지 않음. */
	if (0 == Ptr)
	{
		printf("Ptr is the \"NULL pointer\"\n");
	}
	if (Ptr != 0)
	{
		printf("Ptr is not the \"NULL pointer\"\n");
	}

	return 0;
}

```

### NULL 포인터의 쓰임새

<aside>
1️⃣

포인터의 초기화

</aside>

<aside>
2️⃣

포인터가 더이상 사용중이지 않음을 알리고 싶을 때.

</aside>

<aside>
3️⃣

포인터가 유효한 메모리 주소를 저장하고 있는지 확인할 때.

</aside>

```cpp
Ptr = NULL;

if (NULL == Ptr) 
{ 
	/* alert */ 
}
```

### 자료형이 정해지지 않은 포인터

다시 한 번 포인터 선언 및 초기화 코드를 살펴봅시다.
**자료형*** 변수명 = **메모리주소값**;
NULL 포인터는 **메모리주소값**이 아직 정해지지 않았을 때 사용 했습니다.
**자료형**을 지금 바로 정할 수 없을 때도 있습니다.

### void 포인터

범용 포인터라고도 부릅니다.
void* 변수명 = 메모리 주소 값;

### 어떤 자료형의 포인터라도 void*에 대입 가능합니다.

즉, 매개변수 자료형으로 void*를 사용하면, 어떤 자료형의 포인터라도 모두 받을 수 있는 함수입니다.

### void 포인터의 주의점

<aside>
1️⃣

void*에 역참조 연산은 불가능.
해당 메모리 주소부터 몇 바이트만큼 읽어야 내 데이터인지 모르기 때문입니다.

</aside>

<aside>
2️⃣

void*에 정수를 더하거나 빼는 연산은 불가능.
해당 메모리 주소부터 몇 바이트만큼 더하거나 빼야하는지 모르기 때문입니다.

</aside>

### Ex070302) void*와 역참조

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.
만약 컴파일 에러가 난다면 어디서 왜 나는지 생각해봅시다.

7-4~7-7은 심화

### Ex070401) 포인터의 크기

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

void PrintPointerSize(int* InArray);

int main(void)
{
	int Nums[1024] = { 0, };

	PrintPointerSize(Nums);

	printf("size of array of int: %zu\n", sizeof(Nums));

	return 0;
}

void PrintPointerSize(int* InArray)
{
	char Character = 'h';
	int Num = 2147483647;
	float PI = 3.141595f;

	char* PtrToChar = &Character;
	int* PtrToInt = &Num;
	float* PtrToFloat = &PI;

	printf("size of pointer to an char: %zu\tsize of char: %zu\n", sizeof(PtrToChar), sizeof(Character));
	printf("size of pointer to an int: %zu\tsize of int: %zu\n", sizeof(PtrToInt), sizeof(Num));
	printf("size of pointer to an float: %zu\tsize of float: %zu\n\n", sizeof(PtrToFloat), sizeof(PI));

	printf("size of pointer to int: %zu\n", sizeof(InArray));

	return;
}

```

### 배열의 이름도 포인터

배열의 이름도 사실 포인터입니다. 즉 메모리 주소를 저장하고 있습니다.
정확히는 배열의 시작 메모리 주소를 저장하고 있습니다.

### Ex070402) 배열의 이름과 포인터

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.
주석에 있는 퀴즈도 맞춰봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int i;
	int Nums[6] = { 0, 1, 2, 3, 4, 5 };
	int* PtrToInt = NULL;

	PtrToInt = Nums;
	if (NULL == PtrToInt)
	{
		return -1;
	}
	
	for (i = 0; i < 6; ++i)
	{
		printf("(PtrToInt+%d): %p\t(&Nums[%d]): %p\t*(PtrToInt+%d): %d\n", i, (void*)PtrToInt, i, (void*)(&Nums[i]), i, *PtrToInt);
		++PtrToInt;
	}

	// PtrToInt = Nums[0]; 이 코드는 컴파일 될까?

	// 아래 두 코드는 결과적으로 같습니다.
	PtrToInt = Nums;
	printf("PtrToInt: %p\n", (void*)PtrToInt);
	PtrToInt = &Nums[0];
	printf("PtrToInt: %p\n", (void*)PtrToInt);

	// Nums = PtrToInt; 이 코드는 컴파일 될까?

	return 0;
}

```

### 반대로 포인터도 배열이름처럼 첨자 연산자 []를 쓸 수 있습니다.

결국 컴파일러에게 포인터와 배열이름은 동일한 동작 가능하기 때문입니다.

```cpp
Array[1] == Pointer[1] == *(Array + 1) == *(Pointer + 1);
```

### Ex070403) 배열의 인덱스와 포인터 연산 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void) 
{
	int Nums[5] = { 0, 1, 2, 3, 4 };
	int* Ptr = Nums;

	printf("%d %d %d\n", Nums[1], Ptr[1], *(Ptr + 1));

	return 0;
}
```

### 포인터에 사칙 연산을 가해봅시다.

포인터 + 포인터가 아니라 포인터 + 정수에 대한 이야기입니다.

### Ex070404) 배열의 인덱스와 포인터 연산 2

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int i;
	char Chars[5] = { '0', '1', '2', '3', '4' };
	int Nums[5] = { 0, 1, 2, 3, 4 };
	char* PtrToArrayOfChar = Chars;
	int* PtrToArrayOfInt = Nums;

	for (i = 0; i < 5; ++i)
	{
		printf("Chars[%d]: %p\t%c\n", i, (void*)PtrToArrayOfChar, *PtrToArrayOfChar);
		++PtrToArrayOfChar;
	}

	for (i = 0; i < 5; ++i)
	{
		printf("Nums[%d]: %p\t%d\n", i, (void*)PtrToArrayOfInt, *PtrToArrayOfInt);
		++PtrToArrayOfInt;
	}

	return 0;
}
```

### pointer to char Vs. pointer to int

pointer to char에 1을 더하면 주소도 1 더해집니다.
pointer to int에 1을 더하면 주소는 4가 더해집니다.
즉, 자료형의 크기만큼 주소도 증가합니다.
포인터에 ++연산을 가하면 다음 메모리 주소를 가르키게끔 설계되어 있단 뜻입니다.
이는 덧셈 뺄셈 증감 모두 적용됩니다.

### 포인터 + 정수의 의미

포인터에 정수 n을 더하거나 빼면 (sizeof(자료형) * n) 만큼 주소 이동됩니다.

### 배열 인덱스의 진짜 의미

“시작 메모리 주소로부터의 떨어진 거리”
떨어진 거리 정도를 다른 말로 오프셋(Offset)이라고도 합니다.

ex) Array[0]는 “배열의 시작 메모리 주소로부터 0만큼 떨어져 있다.”

### 중요 포인트

<aside>
1️⃣

포인터의 크기와 자료형의 크기는 헷갈리지 맙시다.
포인터의 크기는 32bit 플랫폼 기준 4바이트. 64bit는 8바이트.

</aside>

<aside>
2️⃣

배열은 첫 번째 요소의 메모리 주소와 자료형만 안다면 n 번째 요소도 알 수 있습니다.

</aside>

### Ex070405) 배열의 인덱스와 포인터 연산 3

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Nums[5] = { 0, 1, 2, 3, 4 };
	int* Ptr = Nums;

	printf("Ptr+0: %p\t%d\n", (void*)(Ptr + 0), *(Ptr + 0));
	Ptr = Ptr + sizeof(int);
	printf("Ptr+sizeof(int): %p\t%d\n", (void*)Ptr, *Ptr);

	return 0;
}

```

### Ex070406) 배열의 인덱스와 포인터 연산 4

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
    int Nums[3] = { 12, 34, 56 };
    int* Ptr = Nums;

    int Num1 = *Ptr++;
    int Num2 = *++Ptr;
    int Num3 = ++*Ptr;
    int Num4 = (*Ptr)++;

    /* Q. 각 num 변수들의 출력 값을 예측해보자. */
    printf("%d %d %d %d", Num1, Num2, Num3, Num4);

    return 0;
}

```

### Ex070407) 포인터 연산 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Nums[5] = { 0, 1, 2, 3, 4 };    /* Nums == 0x00000100 */

	/* Q. 각각의 포인터에 저장된 메모리 주소를 맞춰보자. */
	int* Ptr1 = Nums + 2;
	int* Ptr2 = &Nums[0] + 2;
	int* Ptr3 = Nums + 4;
	int* Ptr4 = Ptr3 - 2;
	int* Ptr5 = &Nums[1] - 1;
	int* Ptr6 = Ptr5 - 1;

	return 0;
}

```

### Ex070408) 포인터 연산 2

아래를 만족하는 함수를 작성해봅시다.
반환 자료형: int
매개변수 목록: int* InData, const int InSize
하는 일: 전달 받은 배열(InData)의 원소 합을 반환하는 함수.
배열 첨자 연산자로 누적합을 구하지 말고, 다른 방법을 고안해봅시다. 

### 포인터에 정수를 더할 때 그 강력함과 위험함이 느껴집니다.

시작 주소와 자료형만 알고 있다면 어디든지 접근해서 읽고 쓸 수 있습니다.
어떤 메모리는 접근할 시에 프로그램이 OS에 의해 종료당할 수도 있습니다.

### Ex070410) 올바르지 않은 메모리 주소에 접근

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int i;
	int Nums[3] = { 12, 34, 56 };
	int* Ptr = Nums;

	for (i = -1; i <= 3; ++i)
	{
		printf("%p: %d\n", (void*)(Ptr + i), *(Ptr + i));
	}

	return 0;
}
```

### 포인터와 포인터 간의 사칙연산

포인터와 포인터 간에는 뺄셈만 지원됩니다.
두 메모리 주소가 얼마나 떨어져 있는가에 대한 값이 반환됩니다. 즉 오프셋 값입니다.
따라서 (포인터 - 포인터)의 반환 값은 정수입니다.

### Ex070411) 포인터와 포인터 간의 뺄셈

아래 소스코드를 따라서 작성해봅시다. 출력 결과를 예측해보고, 문제가 무엇인지 고민해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Nums[5] = { 0, };

	//int* Ptr1 = &Nums[1] + &Nums[3];
	//int Res1 = &Nums[1] + &Nums[3];

	//int* Ptr2 = &Nums[1] - &Nums[3];
	int Res2 = &Nums[1] - &Nums[3];

	//int* Ptr3 = &Nums[1] * &Nums[3];
	//int Res3 = &Nums[1] * &Nums[3];

	//int* ptr4 = &Nums[1] / &Nums[3];
	//int Res4 = &Nums[1] / &Nums[3];

	printf("%d\n", Res2);

	return 0;
}

```

### Ex070412) ReverseElement() 함수

```jsx
// Main.c

#include <stdio.h>

void ReverseElement(int* InArray, int InArraySize);

int main(void)
{
	int i, Array[5] = { 1, 2, 3, 4, 5 };

	for (i = 0; i <= 4; ++i)
	{
		printf("%d ", Array[i]);
	}

	ReverseElement(Array, 4);
	printf("\n");

	for (i = 0; i <= 4; ++i)
	{
		printf("%d ", Array[i]);
	}

	return 0;
}

void ReverseElement(int* InArray, int InArraySize)
{
	// 이 부분을 채우시오.

	return;
}
```

### 값 수정 막기

값 수정을 막으려면 const 키워드를 사용했었습니다.

근데 딱히 값 수정을 막는건 의미 없어 보입니다.
값 수정을 막을때는 이후에 배울 매크로 변수를 쓰는게 더 좋고,
실수가 발생한다해도 해당 함수 내에서 발생하는 정도라서 큰 의미는 없어보입니다.

### 포인터와 const 키워드

다른 함수에 포인터가 인자로 전달되면 원본이 바뀔 위험이 있습니다.
만약 이런 실수가 발생한다면 전역적인 문제로 번질 가능성이 농후합니다.

### 포인터에 const 키워드를 달면 뭘 보호하겠다는 걸까요?

메모리 주소를 보호하겠다는건가? 아님 메모리 주소 속에 값을 보호하나?
위치에 따라 달라집니다. 이는 right-left rule을 통해 구별 가능합니다.

### const pointer to integer

메모리 주소를 보호하는 포인터.
자료형* const 변수명 = 주소;

### Ex070501) const pointer to integer

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Num1 = 100;
	int Num2 = 300;
	int* const ConstPtrToInt = &Num1;

	// 컴파일 안됨.
	// ConstPtrToInt = &Num2;
	// ++ConstPtrToInt;

	printf("Num: %d\n", Num1);
	printf("ConstPtrToInt: %p\t%d\n", (void*)ConstPtrToInt, *ConstPtrToInt);
	*ConstPtrToInt *= 2;
	printf("Num: %d\n", Num1);
	printf("ConstPtrToInt: %p\t%d\n", (void*)ConstPtrToInt, *ConstPtrToInt);
	*ConstPtrToInt = Num2;
	*ConstPtrToInt *= 2;
	printf("Num: %d\n", Num2);
	printf("ConstPtrToInt: %p\t%d\n", (void*)ConstPtrToInt, *ConstPtrToInt);

	return 0;
}
```

### pointer to const integer

메모리 주소 속에 값을 보호. 
const 자료형* 변수명 = 주소;

### Ex070502) pointer to const integer 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

Num3는 const int가 아니기 때문에, 직접적으로 값을 바꿀 수 있습니다. 상수가 아닌 변수.
그러나 PtrToConstInt2를 통한 간접적인 값 변경(역참조 연산자 사용)은 불가능합니다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	int Num1 = 10;
	int Num2 = 20;
	int Num3 = 30;

	/* const pointer to an int */
	int* const ConstPtrToInt = &Num1;

	/* pointer to an int, which is const. */
	const int* PtrToConstInt1 = &Num2; 
		// 값을 보호할 때는, 아래보다 이 방식으로 적는 경우가 많음.

	/* pointer to an const int */
	int const* PtrToConstInt2 = &Num3;

	printf("Num2: %d\n", Num2);
	printf("Num3: %d\n", Num3);
	printf("PtrToConstInt1: %p\t%d\n\n", (void*)PtrToConstInt1, *PtrToConstInt1);

	PtrToConstInt1 = &Num3;

	printf("Num2: %d\n", Num2);
	printf("Num3: %d\n", Num3);
	printf("PtrToConstInt1: %p\t%d\n\n", (void*)PtrToConstInt1, *PtrToConstInt1);

	// *PtrToConstInt1 = 15;
	// (*PtrToConstInt1)++;

	Num3 = 25;
	printf("Num2: %d\n", Num2);
	printf("Num3: %d\n", Num3);
	printf("PtrToConstInt1: %p\t%d\n", (void*)PtrToConstInt1, *PtrToConstInt1);

	Num3 *= 2;
	*PtrToConstInt2 *= 2;

	return 0;
}

```

### Ex070503) pointer to const integer 2

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

게임 개발에서 Vector라는 개념을 자주 씁니다.
이때 전달받은 벡터의 원본 값을 훼손하지 않겠다는 뜻으로 매개 자료형에 const int*를 사용해봅시다.

```c
// Main.c

#include <stdio.h>

void Sum(const int* InArray1, const int* InArray2, int* OutArray);

int main(void)
{
	const int Vector1[3] = { 1, 2, 3 };
	const int Vector2[3] = { 4, 5, 6 };
	int ResultVector[3];

	Sum(Vector1, Vector2, ResultVector);

	printf("ResultVector: %d\t%d\t%d\n", ResultVector[0], ResultVector[1], ResultVector[2]);

	return 0;
}

void Sum(const int* InArray1, const int* InArray2, int* OutArray)
{
	size_t i;

	for (i = 0; i < 3; ++i)
	{
		*OutArray++ = *InArray1++ + *InArray2++;
	}

	return;
}

```

### const pointer to an const integer

주소도 보호하고 값도 보호.
const 자료형* const 변수명 = 주소;

### Ex070504) const pointer to an const integer

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

int main(void)
{
	const int Num = 10;
	const int* const ConstPtrToConstInt = &Num;

	printf("Num: %d\n", Num);
	printf("ConstPtrToConstInt: %p\t%d\n", (void*)ConstPtrToConstInt, Num);

	return 0;
}

```

### const casting

const 키워드를 제거 하는 형변환. 절대로 하지 말라는 의미에서 배우는 것입니다.
물론 제 3의 라이브러리를 사용하면서 문제가 있다면 사용해야 합니다.

### Ex070505) const casting

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

void DeleteConst(const int InLength, const int* InData);

int main(void)
{
	int i;
	int Nums[3] = { 43, 21, 52 };
	const int* ConstPtrToInt = Nums;

	for (i = 0; i < 3; ++i)
	{
		printf("Nums[%d]: %d\n", i, Nums[i]);
	}

	DeleteConst(3, ConstPtrToInt);

	for (i = 0; i < 3; ++i)
	{
		printf("Nums[%d]: %d\n", i, Nums[i]);
	}

	return 0;
}

void DeleteConst(const int InLength, const int* InData)
{
	int i;
	int* ClonedData = NULL;

	*((int*)InData) = 12; /* const casting. worst. */

	ClonedData = (int*)InData;

	for (i = 1; i <= InLength; ++i)
	{
		*ClonedData++ = i * 12;
	}
}
```

### Ex070601) 지역 변수의 메모리 주소 반환

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.
문제가 있다면, 어떤게 문제인지 생각해봅시다.

```c
// Main.c

#include <stdio.h>

int* Add(const int Op1, const int Op2);

int main(void)
{
	int* PtrToRes = Add(17, 20);

	printf("17 + 20 = %d\n", *PtrToRes);

	return 0;
}

int* Add(const int Op1, const int Op2)
{
	int Res = Op1 + Op2;

	return &Res;
}
```

### 위 소스코드는 컴파일 경고가 뜹니다.

함수의 블럭 스코프에 선언된 변수는 지역 변수라고 배웠습니다.
이는 스택 프레임에 저장됩니다. 함수가 종료되면 더이상 접근할 수 없습니다.
근데 그 지역 변수의 메모리 주소가 반환되기 때문에 경고가 뜨는 것입니다.

### Dangling Pointer

더이상 접근 할 수 없는 메모리 주소를 저장하고 있는 포인터.
실로 팽팽하게 어딘가를 가리키고 있다가 가위로 삭둑 자른 모양새.

<aside>
1️⃣

Callee에서 선언된 지역변수의 메모리 주소를 Caller로 반환한 경우. 
해당 메모리 주소는 댕글링 포인터입니다.

</aside>

<aside>
2️⃣

이미 해제된 동적할당 메모리 주소. 이는 뒤에서 배웁니다.

</aside>

### 함수 포인터의 필요성

네비게이션 어플을 만든다고 가정해봅시다.
출발지와 도착지를 받으면 여러 경로를 계산할 수 있습니다.
이때 어떤 사람은 급하게 가야해서 최단거리 경로를, 어떤 사람은 경치가 가장 좋은 경로를 원할 수 있습니다.
즉, 사람들마다 원하는 기준이 다릅니다.
이를 충족시키기 위해서, 우리는 사람에게 “두 경로를 비교할 기준 함수”를 제공 받고자 합니다.
누구는 이 함수에 거리가 짧을 수록 높은 점수, 어떤 사람은 경치가 좋을수록 높은 점수를 주는 함수를 작성해서 줍니다.
받은 함수를 통해 여러 경로들을 비교해나가면 결국 원하는 경로가 나오게 됩니다.

### 함수 포인터(Pointer to function)

함수도 메모리 어딘가에 존재하므로 메모리 주소를 가집니다. 함수 포인터는 해당 메모리 주소를 저장하는 변수입니다.

### Ex070701) 함수 포인터 1

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

void PrintHello(void);

int main(void)
{
	void (*PtrToFunction)(void);

	PrintHello();

	PtrToFunction = PrintHello;

	PtrToFunction();

	return 0;
}

void PrintHello(void)
{
	printf("Hello, world!\n");

	return;
}

```

```

```

### Ex070702) 함수 포인터 2

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

int Add(int X, int Y);

int main(void)
{
	int (*PtrToFunction)(int, int);

	PtrToFunction = Add;

	printf("1 + 2 = %d\n", Add(1, 2));
	printf("1 + 2 = %d\n", PtrToFunction(1, 2));

	return 0;
}

int Add(int X, int Y)
{
	return X + Y;
}

```

```

```

### Ex070703) 함수 포인터 3

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```cpp
// Main.c

#include <stdio.h>

long long Power(int X, int Y);

int main(void)
{
	long long (*PtrToFunction)(int, int);

	PtrToFunction = Power;

	printf("2^10 = %lld\n", Power(2, 10));
	printf("2^10 = %lld\n", PtrToFunction(2, 10));

	return 0;
}

long long Power(int X, int Y)
{
	int i;
	long long Mul = X;

	for (i = 1; i < Y; ++i)
	{
		Mul *= X;
	}

	return Mul;
}

```

```

```

### Ex070704) 함수 포인터 4

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

void SayHello(void);

void SayHi(void);

int Add(int A, int B);

int main(void)
{
	void (*PtrToFunc1)(void);
	int (*PtrToFunc2)(int, int);

	PtrToFunc1 = SayHello;
	PtrToFunc1();

	PtrToFunc1 = SayHi;
	PtrToFunc1();

	/* Q. 컴파일 될까? 왜 안될까? */
	PtrToFunc1 = Add;
	printf("2 + 5 = %d\n", PtrToFunc1(2, 5));

	PtrToFunc2 = Add;
	printf("2 + 5 = %d\n", PtrToFunc2(2, 5));

	return 0;
}

void SayHello(void)
{
	printf("Hello, world!\n");

	return;
}

void SayHi(void)
{
	printf("Hi, world!\n");

	return;
}

int Add(int A, int B)
{
	return A + B;
}

```

### 콜백 함수(Call-Back Function)

특정 이벤트가 발생 했을 때 자동으로 호출되어지게끔 등록해둔 함수를 콜백 함수라고 함.

### Ex070705) 계산기와 함수 포인터

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

int Add(int A, int B);

int Sub(int A, int B);

int Mul(int A, int B);

int Div(int A, int B);

void PrintResult(int A, int B, int (*PtrToFunc)(int, int));

int main(void)
{
	char Operator;
	int A, B;
	int Loop = 1;

	while (Loop)
	{
		scanf("%d%c%d", &A, &Operator, &B);
		switch (Operator)
		{
		case '+':
			PrintResult(A, B, Add);
			break;

		case '-':
			PrintResult(A, B, Sub);
			break;

		case '*':
			PrintResult(A, B, Mul);
			break;

		case '/':
			PrintResult(A, B, Div);
			break;

		default:
			printf("wrong operator.\n");
			Loop = 0;
			break;
		}
	}

	return 0;
}

int Add(int A, int B)
{
	return A + B;
}

int Sub(int A, int B)
{
	return A - B;
}

int Mul(int A, int B)
{
	return A * B;
}

int Div(int A, int B)
{
	if (0 == B) { return INT_MAX; }
	return A / B;
}

void PrintResult(int A, int B, int (*PtrToFunc)(int, int))
{
	printf("Result: %d\n", PtrToFunc(A, B));

	return;
}

```

### Ex070706) 함수포인터를 이용한 콜백 함수 구현

아래 소스코드를 따라서 작성해봅시다. 
따라 적은 코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>

static void (*SHPChangedHandler)(int InPreviousHP, int InCurrentHP) = NULL;

int TakeDamage(int InCurrentHP, int InDamage);

void CallHPChangedHandler(int InPreviousHP, int InCurrentHP);

void SetHP(int InCurrentHP, int InDamage);

void RegisterHPChangedHandler(void (*InHandler)(int InPreviousHP, int InCurrentHP));

void HandleHPChanged(int InPreviousHP, int InCurrentHP);

void HandleHPChangedWithPrint(int InPreviousHP, int InCurrentHP);

int main(void)
{
	int CharacterHP = 100;

	RegisterHPChangedHandler(HandleHPChanged);

	CharacterHP = TakeDamage(CharacterHP, 30);

	RegisterHPChangedHandler(HandleHPChangedWithPrint);
	
	CharacterHP = TakeDamage(CharacterHP, 80);

	CharacterHP = TakeDamage(CharacterHP, 10);
}

int TakeDamage(int InCurrentHP, int InDamage)
{
	if (0 == InCurrentHP)
	{
		return 0;
	}

	int NewHP = InCurrentHP - InDamage;
	if (NewHP <= 0)
	{
		NewHP = 0;
	}

	SetHP(InCurrentHP, NewHP);

	return NewHP;
}

void CallHPChangedHandler(int InPreviousHP, int InCurrentHP)
{
	if (SHPChangedHandler != NULL)
	{
		SHPChangedHandler(InPreviousHP, InCurrentHP);
	}
}

void SetHP(int InPreviousHP, int InCurrentHP)
{
	CallHPChangedHandler(InPreviousHP, InCurrentHP);
}

void RegisterHPChangedHandler(void (*InHandler)(int InPreviousHP, int InCurrentHP))
{
	if (InHandler != NULL)
	{
		SHPChangedHandler = InHandler;
	}
}

void HandleHPChanged(int InPreviousHP, int InCurrentHP)
{
	
}

void HandleHPChangedWithPrint(int InPreviousHP, int InCurrentHP)
{
	printf("%d -> %d\n", InPreviousHP, InCurrentHP);
}

```

# End
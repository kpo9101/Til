### 메모리 레이아웃(메모리 구조)

메모리 레이아웃은 크게 스택 메모리, 힙 메모리, 코드 섹션, 데이터 섹션으로 나뉩니다.
이번 단원에서 살펴볼 메모리는 힙 메모리입니다.

![alt text](image-49.png)

### 코드 섹션과 데이터 섹션

코드 섹션: 우리가 작성한 소스코드들이 빌드된 결과물들이 저장되는 곳입니다.
데이터 섹션: 전역 변수와 정적 변수등이 저장되는 곳입니다.
근데, 스택 메모리와 힙 메모리는 왜 나눴을까요?

### 스택 메모리의 단점

<aside>
1️⃣

스택 메모리에 저장되는 지역 변수(배열 등)의 크기는 컴파일 타임에 고정됩니다.
런타임에 더 필요해진다 해도 크기를 늘릴 수 없습니다.

</aside>

<aside>
2️⃣

함수가 종료되면 해당 스택 프레임에 더이상 접근 불가능합니다.
즉, 지역변수의 수명은 함수의 수명과 함께합니다.
더 오래 보존하려면 전역변수 혹은 정적변수로 선언해야 합니다.
근데 이 변수들은 너무 또 극단적입니다. 프로그램의 수명과 함께합니다.

</aside>

<aside>
📌

런타임 시에 프로그래머가 원하는 만큼(1번 만족)
원하는 때에 생성 및 삭제(2번만족) 가능한 메모리가 필요합니다.

</aside>

### 힙 메모리(Heap Memory)

프로그래머의 메모리 할당과 해제를 통해 관리되는 동적 할당 영역입니다.

스택 메모리는 함수의 호출 및 종료에 따라 자동으로 정리됩니다만, 힙메모리는 아닙니다.
프로그래머가 원하는 만큼, 원하는 때에 할당 및 반납이 가능합니다.
이것이 힙 메모리의 장점입니다.

### 힙 메모리의 단점

<aside>
1️⃣

스택 메모리에 비교해 할당/해제 속도가 느립니다.
스택 메모리는 자료구조 스택의 특성상 할당 및 해제에 O(1) 시간이 걸립니다.
힙 메모리는 할당 받아오려면 사용중이지 않은 메모리이면서 크기가 맞는지 체크 후 제공됩니다.
또한 메모리 공간에 구멍(메모리 단편화)이 생길 수도 있어서 효율적인 메모리 관리가 어렵기도 합니다.

</aside>

<aside>
2️⃣

프로그래머가 직접 메모리 할당 및 해제 해야합니다.
메모리 할당만 하고 해제는 안하는 실수를 할 여지가 있습니다.

</aside>

### 동적 할당의 세 가지 단계

<aside>
1️⃣

메모리 할당(대여)
힙 메모리 관리자에게 필요한 바이트만큼의 메모리를 달라고 요청합니다.
힙 메모리 관리자는 해당 크기의 연속된 메모리를 찾아서 반환합니다.
반환된 값은 시작 메모리 주소입니다.

</aside>

<aside>
2️⃣

메모리 사용
할당된 힙 메모리 시작 주소를 가지고 원하는 작업 수행합니다.
이때 할당된 메모리 속 데이터는 쓰레기값입니다.

</aside>

<aside>
3️⃣

메모리 해제(반납)
힙 메모리 관리자에게 해당 메모리 주소를 돌려주면서 다 썼다고 알립니다.
힙 메모리 관리자는 해당 메모리를 점유되지 않은 메모리 상태로 바꿉니다.
메모리 주소를 돌려주지 않으면 메모리 누수(Memory leak) 발생합니다.
메모리 누수란, 해당 메모리가 점유 상태를 벗어나지 못해 사용가능한 메모리가 줄어드는 현상입니다.

</aside>

### 동적 메모리 관련 함수

할당: malloc() / calloc()
재할당: realloc()
해제: free()
기타: memset() / memcpy() / memcmp() / …

### void* malloc(size_t size)

memory allocation의 약자. stdlib.h 헤더파일에 선언되어 있습니다.
size 바이트 만큼의 메모리를 반환해줍니다.
할당 실패시 NULL을 반환합니다.

### void free(void* ptr)

동적 할당 받은 메모리를 해제하는 함수.
다시말해, 메모리 할당 함수를 통해서 얻은 메모리 주소만 해제 가능합니다.

### [**좋은습관**] malloc()을 작성했다면 곧바로 free()부터 작성하기.

동적 할당 받은 메모리 주소를 지역 변수에 저장해뒀다가 해제 안하고 함수가 종료되버리면,
해당 지역변수를 접근할 방법이 사라져 버립니다. 지울 방법이 없습니다.
이렇게 반납하지 않으면 메모리 누수가 발생하므로, 무슨 일이 있어도 free()부터 작성합시다.

### Ex080201) malloc() 함수와 free() 함수 [중요 샘플 코드]

아래 소스코드를 따라서 작성해봅시다. 
따라 작성한 소스코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t i;
	int* Nums = (int*)malloc(10 * sizeof(int));
	if (NULL == Nums)
	{
		return 0;
	}

	for (i = 0; i < 10; ++i)
	{
		Nums[i] = i * 10;
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%d ", Nums[i]);
	}

	free(Nums);
	Nums = NULL;

	if (NULL != Nums)
	{
		// TODO.
	}

	return 0;
}
```

### 동적 할당 받은 메모리 시작 주소를 연산에 사용한다면 어떻게 될까요?

최초에 받아온 시작 주소를 잃어버리게 됩니다.
그럼 다른 메모리 주소를 free() 함수의 인자로 보낼지도 모릅니다.
사본을 만들어서 포인터 연산에 사용해야 합니다.

### Ex080202) 동적 할당과 포인터 연산 1

아래 소스코드를 따라서 작성해봅시다. 
따라 작성한 소스코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.
만약 문제가 있다면 어디가 왜 문제인지 생각해봅시다.

```c
// Main.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t i;
	int* Nums;

	Nums = (int*)malloc(10 * sizeof(int));
	if (NULL == Nums)
	{
		return 0;
	}

	for (i = 0; i < 10; ++i)
	{
		*Nums++ = 10 * (i + 1);
	}

	free(Nums);
	Nums = NULL;

	return 0;
}

```

### Ex080203) 동적 할당과 포인터 연산 2

아래 소스코드를 따라서 작성해봅시다. 
따라 작성한 소스코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.
만약 문제가 있다면 어디가 왜 문제인지 생각해봅시다.

```c
// Main.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* APNums;    
		/* 메모리 할당된 포인터(allocated pointer)라는 뜻에서 접두어 AP-를 붙히는 것도 아주 좋음. */
		/* 이런 코딩 컨벤션은, 일하거나 배우는 곳의 코딩 컨벤션을 따르면 됨. */
	int* TempPtr;
	size_t i;

	APNums = (int*)malloc(10 * sizeof(int));
	if (NULL == APNums)
	{
		return 0;
	}
	
	TempPtr = APNums;

	for (i = 0; i < 10; ++i)
	{
		*TempPtr++ = 10 * (i + 1);
	}

	free(APNums);
	APNums = NULL;

	return 0;
}
```

### void* realloc(void* ptr, size_t new_size)

이미 동적할당 받은 메모리 시작 주소 ptr을 new_size 바이트로 재할당 해주는 함수.
새로운 크기가 허용하는 한 기존 데이터를 그대로 유지해줍니다.

### Ex080205) malloc() 함수와 realloc() 함수

아래 소스코드를 따라서 작성해봅시다. 
따라 작성한 소스코드의 출력 결과를 예측해보고, 예측 결과와 실행 결과를 비교해봅시다.

```c
// Main.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* APNums = NULL;
	int* APTempNums = NULL;

	APNums = malloc(5 * sizeof(int));
	if (NULL == APNums)
	{
		return 0;
	}

	APTempNums = realloc(APNums, 5 * sizeof(int));
	if (APTempNums != NULL)
	{
		APNums = APTempNums;
	}
	else
	{
		// realloc() 함수가 NULL을 반환하면, 인자로 전달된 APNums는 메모리 해제 되지 않음.
		free(APNums);
		APNums = NULL;
		
		return 0;
	}

	/* 원하는 작업 */

	free(APNums);
	APNums = NULL;

	return 0;
}

```

### 동적 할당 메모리 소유권

해당 메모리 공간의 주인이 누구냐는 아주 중요한 문제입니다.
왜냐면 반드시 책임 지고 해제해야 하기 때문입니다.
또 주인도 아닌데 마음대로 해제해버려도 문제입니다.

```c
// Psudo code.

char* CombineString(const char* LHS, const char* RHS)
{
	char* APStr;
	size_t Size = strlen(LHS) + strlen(RHS);

	APStr = (char*)malloc(Size + 1);
	if (NULL == APStr)
	{
		return NULL;
	}

	/* 복사 생략 */

	/*
	  호출자 입장에선 CombineString() 함수가 내부에서
	  동적 메모리를 할당해서 반환한다는 사실을 어떻게 알 수 있을까요?
	  
	  이처럼 동적할당된 메모리의 해제 문제는 복잡합니다.
	  C++에서는 RAII라는 개념을 통해 메모리 해제 실수를 구조적으로 막을 수 있습니다.
	*/

	return APStr;
}
```

# End
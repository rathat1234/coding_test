# Day 17. 비트맵 (Bitmap) 관리자

## 문제 설명

여러 개의 리소스 사용 여부를 효율적으로 관리하기 위해 **비트맵(Bitmap)** 기반의 리소스 관리자를 구현한다.

`uint8_t` 배열의 각 비트를 하나의 리소스 상태로 사용하여, **1bit = 1resource** 방식으로 할당 여부를 저장한다.

비트가 `0`이면 사용 가능한 상태, `1`이면 이미 할당된 상태로 판단한다.

## 요구사항

* **입력:** 관리할 리소스 개수, 할당/해제 요청
* **출력:** 할당된 리소스의 인덱스 번호
* **제약조건:**

  * `uint8_t` 배열 사용
  * 하나의 비트로 하나의 리소스 상태 관리
  * `0`은 미사용, `1`은 사용 중으로 처리
  * 비트 연산을 이용하여 할당/해제
  * 해제된 리소스는 다시 할당 가능

## 핵심 개념

`uint8_t` 하나는 총 8개의 비트를 가진다.

```text id="gjf3q9"
Bit:   7 6 5 4 3 2 1 0
       ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
Byte: [0 0 0 0 0 0 0 0]
```

따라서 `uint8_t` 배열을 사용하면 하나의 바이트로 8개의 리소스를 관리할 수 있다.

예를 들어 20개의 리소스를 관리하려면 다음과 같이 사용할 수 있다.

```text id="7h9c4d"
Byte 0 → Resource 0  ~ 7
Byte 1 → Resource 8  ~ 15
Byte 2 → Resource 16 ~ 19
```

## 인덱스 계산

리소스 인덱스를 이용하여 어떤 Byte와 Bit를 사용해야 하는지 계산한다.

```c id="95ah2n"
int byte = index / 8;
int bit = index % 8;
```

예를 들어 `index = 10`이면 다음과 같다.

```text id="37ph50"
byte = 10 / 8 = 1
bit  = 10 % 8 = 2
```

즉, Byte 1의 Bit 2가 Resource 10의 상태를 나타낸다.

## 할당

사용 가능한 비트를 찾으면 해당 비트를 `1`로 설정한다.

```c id="w0coqr"
bitmap[byte] |= (1 << bit);
```

예를 들어 Bit 2를 할당하면:

```text id="0ax72f"
Before : 00000000
Mask   : 00000100
         --------
After  : 00000100
```

## 해제

리소스를 해제할 때는 해당 비트를 `0`으로 만든다.

```c id="ut8ykg"
bitmap[byte] &= ~(1 << bit);
```

예를 들어 Bit 2를 해제하면:

```text id="72eb39"
Before : 00000100
Mask   : 11111011
         --------
After  : 00000000
```

## 실행 결과

```text id="ugiz1g"
=== Day 17: Bitmap Manager ===

>> Index 0 allocated. (Byte 0, Bit 0 set)
>> Index 1 allocated. (Byte 0, Bit 1 set)
>> Index 2 allocated. (Byte 0, Bit 2 set)
>> Index 3 allocated. (Byte 0, Bit 3 set)
>> Index 4 allocated. (Byte 0, Bit 4 set)
>> Index 5 allocated. (Byte 0, Bit 5 set)
>> Index 6 allocated. (Byte 0, Bit 6 set)
>> Index 7 allocated. (Byte 0, Bit 7 set)
[Bitmap Visual] 11111111 | 00000000 | 0000

Freeing index 2...
>> Index 2 freed. (Byte 0, Bit 2 cleared)
[Bitmap Visual] 11011111 | 00000000 | 0000

Allocating again (expecting index 2)...
>> Index 2 allocated. (Byte 0, Bit 2 set)
[Bitmap Visual] 11111111 | 00000000 | 0000
```

## 실행 과정

### Phase 1. 리소스 할당

인덱스 `0`부터 `7`까지 순서대로 할당한다.

```text id="stzr4y"
Index 0 → Byte 0, Bit 0
Index 1 → Byte 0, Bit 1
Index 2 → Byte 0, Bit 2
...
Index 7 → Byte 0, Bit 7
```

Byte 0의 모든 비트가 사용 중 상태가 된다.

```text id="o6zo4g"
11111111 | 00000000 | 0000
```

첫 번째 Byte의 8개 리소스가 모두 할당된 상태이다.

### Phase 2. Index 2 해제

Resource 2를 해제한다.

```text id="55heph"
Byte 0
Bit  : 7 6 5 4 3 2 1 0
       1 1 1 1 1 0 1 1
```

실행 결과:

```text id="1o6h18"
11011111 | 00000000 | 0000
```

Index 2에 해당하는 비트만 다시 `0`으로 변경된다.

### Phase 3. 재할당

새로운 리소스 할당 요청이 들어오면 비트맵을 탐색하여 가장 먼저 발견되는 `0` 비트를 찾는다.

현재 Index 2가 비어 있으므로 다시 Index 2가 할당된다.

```text id="48emeg"
>> Index 2 allocated.
```

비트맵은 다시 다음 상태가 된다.

```text id="yw59de"
11111111 | 00000000 | 0000
```

## 비트맵 구조 예시

20개의 리소스를 관리한다고 가정한다.

```text id="yknqo7"
Resource Index

 0 1 2 3 4 5 6 7 | 8 9 10 11 12 13 14 15 | 16 17 18 19
 ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓   ↓ ↓ ↓  ↓  ↓  ↓  ↓  ↓    ↓  ↓  ↓  ↓

[    Byte 0     ] | [       Byte 1       ] | [ Byte 2 ]
```

필요한 메모리는 리소스 하나당 1바이트가 아니라 **1비트**뿐이다.

예를 들어 100개의 리소스를 관리할 경우 필요한 크기는 다음과 같다.

```text id="lwza03"
100 / 8 = 12 byte + 나머지

필요한 배열 크기 = 13 byte
```

따라서 단순히 `uint8_t resource[100]` 방식으로 관리하는 것보다 메모리를 크게 절약할 수 있다.

## 시간 및 공간 특성

### 공간 복잡도

리소스 개수가 `N`개라면 필요한 메모리는 약 다음과 같다.

```text id="bq8s0d"
N / 8 Byte
```

즉, 리소스 하나를 `uint8_t` 하나로 관리하는 방식에 비해 약 **1/8 수준의 메모리**만 사용한다.

### 할당 탐색

가장 앞의 빈 비트를 순차 탐색하는 방식이라면 최악의 경우 모든 리소스를 검사해야 한다.

따라서 기본 구현의 할당 탐색 시간 복잡도는:

```text id="66guh5"
O(N)
```

비트 설정 및 해제 자체는 특정 위치를 알고 있다면 `O(1)`로 처리할 수 있다.

## 임베디드 활용

비트맵은 메모리 사용량이 중요한 임베디드 환경에서 여러 상태를 관리할 때 활용할 수 있다.

* 메모리 블록 할당 상태
* 통신 채널 사용 여부
* 센서 활성화 상태
* 디바이스 ID 할당
* 태스크 또는 이벤트 상태
* 고정 크기 리소스 풀
* 페이지 및 블록 관리

## 학습 포인트

* 비트맵 자료구조 이해
* `uint8_t`의 비트 단위 활용
* 비트 마스크 연산
* `|`를 이용한 비트 설정
* `&`, `~`를 이용한 비트 해제
* `/`, `%`를 이용한 Byte/Bit 위치 계산
* 한정된 메모리에서 효율적인 상태 관리
* 리소스 할당 및 해제 구조 이해
* 임베디드 환경에서의 메모리 최적화

# Day 22. 소프트웨어 타이머 (Linked List 기반)

## 문제 설명

임베디드 시스템에서 여러 개의 타이머를 효율적으로 관리하기 위해 **단일 연결 리스트(Singly Linked List)** 기반의 소프트웨어 타이머를 구현한다.

각 타이머의 남은 시간을 절대 시간이 아닌 **Delta Time(상대 시간)** 으로 저장하고, 만료 시간이 빠른 순서대로 연결 리스트를 정렬하여 관리한다.

`Tick()`이 주기적으로 호출될 때 리스트의 가장 앞에 있는 타이머의 시간만 감소시키며, 시간이 만료되면 등록된 콜백 함수를 실행하고 해당 타이머를 리스트에서 제거한다.

## 요구사항

* **입력:** `SetTimer(ID, ms)`, `Tick()` 주기적 호출
* **출력:** 타이머 만료 시 콜백 함수 실행
* **제약조건:**

  * 단일 연결 리스트 사용
  * 타이머를 남은 시간 순으로 정렬
  * Delta Time(상대 시간) 방식으로 관리
  * `Tick()`마다 Head 타이머의 시간만 감소
  * 시간이 만료된 타이머의 콜백 실행 및 리스트에서 제거

## 핵심 개념

### Delta Time 방식

타이머의 **절대 만료 시간**을 저장하는 대신, 앞에 있는 타이머가 만료된 후 얼마나 더 기다려야 하는지를 저장한다.

예를 들어 다음과 같이 3개의 타이머를 등록한다.

```text
Timer A = 10ms
Timer B = 15ms
Timer C = 15ms
```

Delta Time 방식으로 저장하면 다음과 같다.

```text
Head
 ↓
[A: 10] -> [B: 5] -> [C: 0] -> NULL
```

각 타이머의 실제 만료 시점은 다음과 같다.

* A: 10ms 후 만료
* B: A 만료 후 5ms → 총 15ms 후 만료
* C: B 만료 후 0ms → 총 15ms 후 만료

### 왜 Delta Time을 사용하는가?

모든 타이머의 남은 시간을 매 `Tick()`마다 감소시키면 타이머가 N개일 때 매번 **O(N)** 의 연산이 필요하다.

반면 Delta Time 방식에서는 리스트의 Head 타이머만 감소시키면 되므로 일반적인 `Tick()` 연산은 **O(1)** 로 처리할 수 있다.

타이머가 만료되어 제거되는 경우에는 다음 타이머를 확인하고 필요한 후속 처리를 수행한다.

## 타이머 리스트 구조

초기 타이머 등록 과정은 다음과 같다.

```text
Timer 1 = 10ms

[ID:1, dt:10, total:10]
        ↓
       NULL
```

5ms 타이머인 Timer 2를 추가하면 가장 먼저 만료되므로 Head에 삽입한다.

```text
[ID:2, dt:5, total:5]
        ↓
[ID:1, dt:5, total:10]
        ↓
       NULL
```

15ms 타이머인 Timer 3을 추가하면 마지막에 삽입된다.

```text
[ID:2, dt:5, total:5]
        ↓
[ID:1, dt:5, total:10]
        ↓
[ID:3, dt:5, total:15]
        ↓
       NULL
```

## 실행 결과

```text
=== Day 22: Software Timer (Delta List) ===

Timer 1 set (10 ms) [Inserted at HEAD]
[Timer List] (ID:1, dt:10, total:10) -> NULL

Timer 2 set (5 ms) [Inserted at HEAD]
[Timer List] (ID:2, dt:5, total:5) -> (ID:1, dt:5, total:10) -> NULL

Timer 3 set (15 ms) [Inserted in List]
[Timer List] (ID:2, dt:5, total:5) -> (ID:1, dt:5, total:10) -> (ID:3, dt:5, total:15) -> NULL

>> Start Ticking...
Tick 1: Rem Head dt: 4
... (생략) ...
Tick 4: Rem Head dt: 1
Tick 5: >> [Event] Timer 2 expired! Action executed.
Rem Head dt: 5
Tick 6: Rem Head dt: 4
... (생략) ...
Tick 9: Rem Head dt: 1
Tick 10: >> [Event] Timer 1 expired! Action executed.
Rem Head dt: 5
Tick 11: Rem Head dt: 4
... (생략) ...
Tick 14: Rem Head dt: 1
Tick 15: >> [Event] Timer 3 expired! Action executed.
All timers cleared.
```

## 실행 과정

### Phase 1. Timer 등록

총 3개의 타이머를 등록한다.

```text
Timer 1 → 10ms
Timer 2 → 5ms
Timer 3 → 15ms
```

타이머는 만료 시간이 빠른 순서대로 리스트에 정렬된다.

```text
[Timer 2: 5] -> [Timer 1: 5] -> [Timer 3: 5]
```

각 `dt` 값은 **이전 타이머가 만료된 후 기다려야 하는 상대 시간**을 의미한다.

### Phase 2. Tick 진행

`Tick()`이 1ms마다 호출된다고 가정한다.

Head의 `dt`만 감소한다.

```text
Tick 1 → Timer 2: 4
Tick 2 → Timer 2: 3
Tick 3 → Timer 2: 2
Tick 4 → Timer 2: 1
Tick 5 → Timer 2 만료
```

Timer 2가 만료되면 콜백을 실행하고 리스트에서 제거한다.

```text
[Timer 2] -> [Timer 1] -> [Timer 3]
     ↓
  Callback
```

이후 Timer 1이 Head가 되어 다시 시간을 감소시킨다.

### Phase 3. 타이머 만료

각 타이머의 만료 시점은 다음과 같다.

| Timer   | 설정 시간 | 만료 시점 |
| ------- | ----: | ----: |
| Timer 2 |   5ms |   5ms |
| Timer 1 |  10ms |  10ms |
| Timer 3 |  15ms |  15ms |

따라서 실행 순서는 다음과 같다.

```text
Timer 2 → Timer 1 → Timer 3
```

모든 타이머가 만료되면 연결 리스트는 `NULL`이 된다.

## 자료구조

타이머 하나를 연결 리스트의 노드로 관리한다.

```c
typedef struct TimerNode
{
    int id;
    int dt;
    void (*callback)(struct TimerNode* expired);

    struct TimerNode* next;
} TimerNode;
```

주요 멤버의 역할은 다음과 같다.

* `id`: 타이머를 구분하기 위한 ID
* `dt`: 이전 타이머 이후의 상대 시간
* `callback`: 타이머 만료 시 실행할 함수
* `next`: 다음 타이머를 가리키는 포인터

## 핵심 구현 포인트

### 1. Head 타이머 감소

```text
Tick()
  ↓
Head의 dt 감소
  ↓
dt == 0 ?
  ↓
Yes → Callback 실행
  ↓
노드 제거
```

### 2. 타이머 삽입

새로운 타이머의 만료 시간이 기존 타이머보다 빠르면 Head에 삽입한다.

그렇지 않으면 적절한 위치를 찾아 삽입하면서 **Delta Time 값을 재계산**해야 한다.

### 3. 콜백 실행

타이머가 만료되었을 때 등록된 콜백 함수를 호출한다.

```c
timer->callback(timer);
```

이를 통해 타이머 관리 코드와 실제 만료 후 수행할 동작을 분리할 수 있다.

## 학습 포인트

* 단일 연결 리스트의 활용
* 함수 포인터를 이용한 Callback 구현
* 소프트웨어 타이머의 동작 원리
* Delta Time 방식 이해
* 타이머 정렬 및 삽입
* `Tick()` 기반 시간 관리
* 타이머 만료 및 노드 제거
* 임베디드 시스템에서 효율적인 타이머 관리 방법 이해
* `O(N)` 방식과 `O(1)` 방식의 차이 이해

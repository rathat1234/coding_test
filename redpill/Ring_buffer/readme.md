# Day 15. 원형 버퍼 (Ring Buffer) 구현

## 문제 설명

원형 버퍼(Ring Buffer)를 배열을 이용하여 구현한다.

데이터를 `Push`하고 `Pop`하는 과정에서 `Head`와 `Tail` 인덱스를 관리하며, 버퍼가 가득 찬 경우 데이터가 덮어쓰이지 않도록 오버플로우를 방지한다.

## 요구사항

* **입력:** 데이터 Push / Pop 요청
* **출력:** 버퍼 상태 (`Full` / `Empty`), 꺼낸 데이터
* **제약조건:**

  * 배열을 사용하여 구현
  * `Head` / `Tail` 인덱스 관리
  * 버퍼 오버플로우 방지
  * 인덱스가 배열의 끝에 도달하면 처음으로 돌아가는 원형 구조 구현

## 실행 결과

```text
--- Phase 1: Filling Buffer ---
Put: 1 (Head: 1, Tail: 0)
Put: 2 (Head: 2, Tail: 0)
Put: 3 (Head: 3, Tail: 0)
Put: 4 (Head: 4, Tail: 0)
Put: 5 (Head: 5, Tail: 0)
Put: 6 (Head: 6, Tail: 0)
Put: 7 (Head: 7, Tail: 0)
Fail to Put: 8 (Buffer Full!)

--- Phase 2: Reading Buffer ---
Get: 1 (Head: 7, Tail: 1)
Get: 2 (Head: 7, Tail: 2)
Get: 3 (Head: 7, Tail: 3)

--- Phase 3: Writing again (Wrap around) ---
Put: 99 (Head: 0, Tail: 3)
```

## 실행 과정

### Phase 1. 버퍼 채우기

버퍼 크기가 8이지만 `Head == Tail` 상태를 Empty로 사용하기 때문에 한 칸을 비워둔다.

따라서 실제로 저장할 수 있는 데이터는 최대 **7개**이다.

```text
Put: 1 ~ 7
```

8번째 데이터를 저장하려고 하면 버퍼가 Full 상태이므로 저장하지 않는다.

```text
Fail to Put: 8 (Buffer Full!)
```

### Phase 2. 데이터 읽기

Tail이 가리키는 위치에서 데이터를 순서대로 꺼낸다.

```text
Get: 1
Get: 2
Get: 3
```

3개의 데이터가 제거되면서 버퍼에 다시 공간이 생긴다.

### Phase 3. Wrap Around

데이터를 3개 꺼낸 후 다시 `Put`을 수행한다.

```text
Put: 99 (Head: 0, Tail: 3)
```

`Head`가 배열의 마지막 인덱스에 도달한 후 **0번 인덱스로 돌아가는 것**을 확인할 수 있다.

이것이 원형 버퍼의 `Wrap Around`이다.

## 핵심 개념

### Head

새로운 데이터를 저장할 위치를 가리킨다.

```text
Head = (Head + 1) % BUFFER_SIZE;
```

### Tail

가장 오래된 데이터를 꺼낼 위치를 가리킨다.

```text
Tail = (Tail + 1) % BUFFER_SIZE;
```

### Empty

```text
Head == Tail
```

### Full

다음 Head 위치가 Tail과 같으면 버퍼가 가득 찬 것으로 판단한다.

```text
(Head + 1) % BUFFER_SIZE == Tail
```

이 방식을 사용하면 버퍼의 한 칸을 비워두는 대신 별도의 `count` 변수를 사용하지 않고도 Full과 Empty를 구분할 수 있다.

## 참고 테스트 코드

```c
// ---- 테스트 코드 ----
int main() {
    RingBuffer uart_rx_buf;
    uint8_t temp;

    rb_init(&uart_rx_buf);

    printf("--- Phase 1: Filling Buffer ---\n");
    // 버퍼 사이즈가 8이므로, 한 칸 비우면 최대 7개 저장 가능
    for (int i = 1; i <= 8; i++) {
        if (rb_put(&uart_rx_buf, i)) {
            printf("Put: %d (Head: %d, Tail: %d)\n",
                   i, uart_rx_buf.head, uart_rx_buf.tail);
        } else {
            printf("Fail to Put: %d (Buffer Full!)\n", i);
        }
    }

    printf("\n--- Phase 2: Reading Buffer ---\n");
    // 3개만 읽어봄
    for (int i = 0; i < 3; i++) {
        if (rb_get(&uart_rx_buf, &temp)) {
            printf("Get: %d (Head: %d, Tail: %d)\n",
                   temp, uart_rx_buf.head, uart_rx_buf.tail);
        }
    }

    printf("\n--- Phase 3: Writing again (Wrap around) ---\n");
    // 읽어서 공간이 생겼으므로 다시 쓰기 가능
    // 인덱스가 0으로 돌아가는지 확인
    if (rb_put(&uart_rx_buf, 99)) {
        printf("Put: 99 (Head: %d, Tail: %d)\n",
               uart_rx_buf.head, uart_rx_buf.tail);
    }

    return 0;
}
```

## 학습 포인트

* 원형 버퍼의 기본 구조 이해
* `Head` / `Tail` 인덱스 관리
* `%` 연산을 이용한 인덱스 순환
* Full / Empty 상태 구분
* 버퍼 오버플로우 방지
* Wrap Around 동작 확인
* UART RX 버퍼 등 임베디드 시스템에서 활용되는 자료구조 이해

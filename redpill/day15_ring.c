#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef struct RingBuffer
{
    uint8_t buffer[BUFFER_SIZE];

    int head;
    int tail;
} RingBuffer;

void rb_init(RingBuffer *pool)
{
    pool->head = 0;
    pool->tail = 0;
}

bool rb_put(RingBuffer *pool, uint8_t data)
{
    int next_head = (pool->head + 1) % BUFFER_SIZE;

    if (next_head == pool->tail)
    {
        return false;
    }

    pool->buffer[pool->head] = data;
    pool->head = next_head;

    return true;
}

bool rb_get(RingBuffer *pool, uint8_t *data_get)
{
    if (pool->head == pool->tail)
    {
        return false;
    }

    *data_get = pool->buffer[pool->tail];
    pool->tail = (pool->tail + 1) % BUFFER_SIZE;

    return true;
}

// ---- 테스트 코드 ----
int main() {
    RingBuffer uart_rx_buf;
    uint8_t temp;

    rb_init(&uart_rx_buf);

    printf("--- Phase 1: Filling Buffer ---\r\n\r\n");
    // 버퍼 사이즈가 8이므로, 한 칸 비우면 최대 7개 저장 가능
    for (int i = 1; i <= 8; i++) {
        if (rb_put(&uart_rx_buf, i)) {
            printf("Put: %d (Head: %d, Tail: %d)\n", i, uart_rx_buf.head, uart_rx_buf.tail);
        } else {
            printf("Fail to Put: %d (Buffer Full!)\n", i);
        }
    }

    printf("--- Phase 2: Reading Buffer ---\r\n\r\n");
    // 3개만 읽어봄
    for (int i = 0; i < 3; i++) {
        if (rb_get(&uart_rx_buf, &temp)) {
            printf("Get: %d (Head: %d, Tail: %d)\n", temp, uart_rx_buf.head, uart_rx_buf.tail);
        }
    }

    printf("--- Phase 3: Writing again (Wrap around) ---\r\n\r\n");
    // 읽어서 공간이 생겼으므로 다시 쓰기 가능 (인덱스가 0으로 돌아가는지 확인)
    if (rb_put(&uart_rx_buf, 99)) {
         printf("Put: 99 (Head: %d, Tail: %d)\n", uart_rx_buf.head, uart_rx_buf.tail);
    }

    return 0;
}
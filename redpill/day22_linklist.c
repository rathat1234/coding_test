#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

typedef struct TimerNode
{
    int id;
    int dt;
    void (*callback)(struct TimerNode* expired);

    struct TimerNode *next;
} TimerNode;

TimerNode *current = NULL;
int tick_time = 0;

void Timeout(TimerNode *expired)
{
    printf("Tick %d: >> [Event] Timer %d expired! Action executed.\r\n",tick_time,expired->id);
    free(expired);
}

void Tick(void)
{
    if(current == NULL)
        return;
    
    if(current->dt==0)
    {
        TimerNode* expired = current;
        current = current->next;
        expired->callback(expired);
        if(current == NULL)
            return;
        printf("Rem Head dt: %d\r\n",current->dt);
    }
    else
    {
        printf("Tick %d: Rem Head dt: %d\r\n",++tick_time,current->dt);
        current->dt--;
    }
}

void SetTimer(int ID, int ms)
{
    TimerNode *timer = malloc(sizeof(TimerNode));

    timer->id = ID;
    timer->dt = ms;
    timer->callback = Timeout;
    timer->next = NULL;
    if (current == NULL)
    {
        current = timer;
        printf("Timer %d set (%d ms) [Inserted at HEAD]\r\n",ID,ms);
    }
    else
    {
        if (current->dt > timer->dt)
        {
            current->dt -= timer->dt;
            timer->next=current;
            current = timer;
            printf("Timer %d set (%d ms) [Inserted at HEAD]\r\n",ID,ms);

        }
        else
        {
            TimerNode *prev = current;
            TimerNode *node = current->next;

            timer->dt -= current->dt;

            while (node != NULL && timer->dt >= node->dt)
            {
                timer->dt -= node->dt;
            
                prev = node;
                node = node->next;
            }
            
            timer->next = node;
            prev->next = timer;
            printf("Timer %d set (%d ms) [Inserted at List]\r\n",ID,ms);

        }
    }
}

void print_timer(void)
{
    TimerNode *prev = current;
    TimerNode *node = current->next;
    int time = 0;
    printf("[Timer List]");
    while (prev != NULL)
    {
        time += prev->dt;
        printf("(ID:%d, dt:%d, total:%d) ->",prev->id,prev->dt,time);
        prev = node;
        if(node != NULL)
            node = prev->next;
    }
    printf("NULL\r\n");
}



int main(int argc, char const *argv[])
{
    printf("=== Day 22: Software Timer (Delta List) ===\r\n\r\n");
    SetTimer(1, 10);
    print_timer();
    SetTimer(2, 5);
    print_timer();
    SetTimer(3, 15);
    print_timer();
    printf("\r\n");
    
    printf(">> Start Ticking...\r\n");
    while(current != NULL)
    {
        Tick();
    }

    printf("All timers cleared.\r\n");

    return 0;
}

#include "stdio.h"
#include "stdlib.h"

#define DATA_SIZE 3

typedef struct Block{
    struct Block* next;
    int num;
}Block;

Block* current = NULL;

void list_init(void);

void list_reversed(void);


int main(int argc, char const *argv[])
{
    list_init();

    list_reversed();

    printf("List Reversed.");
    return 0;
}

void list_init(void)
{
    for (int i = DATA_SIZE; i > 0; i--)
    {
        Block* temp = malloc(sizeof(Block));
        temp->next= current;
        temp->num = i;
        current = temp;
    }
    Block* temp = current;
    
    while(temp!=NULL)
    {
        printf("%d -> ",temp->num);
        temp = temp->next;
    }
        printf("NULL\r\n");

}

void list_reversed(void)
{
    Block* prev = NULL;
    Block* temp = current;
    Block* next = NULL;

    while(temp !=NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    current = prev;
    
    temp = current;
    
    while(temp!=NULL)
    {
        printf("%d -> ",temp->num);
        temp = temp->next;
    }
        printf("NULL\r\n");
}

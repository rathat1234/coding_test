#include <stdio.h>
#include <stdint.h>

typedef struct SensorData
{
    uint16_t a;
    char b[12];
    float c;
}SensorData;


void hexdump(char *str, void *data, int size)
{   
    printf("%s:\r\n",str);
    for (int i = 0; i <= size/16; i++)
    {
        printf("%04x  ", i * 16);
        int temp = 16;
        unsigned char *p = (unsigned char *)data;
        for (int j = 0; j < temp; j++)
        {
            if(size<=(i*16)+j-1)
                printf("   ");
            else
                printf("%02x ", p[(i*16)+j]);
        }
        printf("     ");

        for (int j = 0; j < temp; j++)
        {
            if(size<=(i*16)+j)
                printf("");
            else
            {
                if(0x20<=p[(i*16)+j]&&p[(i*16)+j]<=0x7E)
                {
                    printf("%c", p[(i*16)+j]);
                }
                else
                {
                    printf(".");

                }
            }

        }
        printf("\r\n");
    }
        printf("\r\n\r\n");   
}

int main(int argc, char const *argv[])
{
        // 테스트 1: 단순 문자열
    char my_text[] = "Hello Embedded World! This is Hexdump.";
    hexdump("String Dump", my_text, sizeof(my_text));
  
    // // 테스트 2: 구조체 (엔디안 확인 가능)
    SensorData sensor = { 0x12345678, "Sensor A", 3.14f };
    hexdump("Struct Dump", &sensor, sizeof(sensor)); 
    return 0;
}


#include <stdio.h>
#include <stdint.h>
#include <intrin.h>
#include <stdbool.h>

typedef struct packet
{
    uint8_t data1;
    uint8_t data2;
    uint8_t data3;
    uint8_t data4;
    uint8_t data5;
    uint8_t data6;
    uint8_t checksum;
} packet;

void packet_verif(packet *b_data);

int main(int argc, char const *argv[])
{
    packet send_data = {0x01, 0x04, 0x10, 0x20, 0x30, 0x40, 0x04};

    printf("[TX] Sending Packet...\r\n");
    printf("Data: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\r\n",
           send_data.data1, send_data.data2, send_data.data3,
           send_data.data4, send_data.data5, send_data.data6);
    printf("Calculated Checksum: : 0x%02x\r\n\r\n", send_data.checksum);

    printf("[RX] Receiving Packet...\r\n");
    packet_verif(&send_data);
    printf("\r\n");

    send_data.checksum = 0x45;
    printf("[RX] Receiving Packet... (change checksum 0x45)\r\n");
    printf("Data: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\r\n",
           send_data.data1, send_data.data2, send_data.data3,
           send_data.data4, send_data.data5, send_data.data6);
    packet_verif(&send_data);
    printf("\r\n");

    send_data.data3 = 0xEF;
    printf("[RX] Receiving Corrupted Packet (Noise injected)...\r\n");
    packet_verif(&send_data);
    printf("\r\n");
}

void packet_verif(packet *b_data)
{
    uint8_t temp;
    temp = b_data->data1 ^ b_data->data2 ^ b_data->data3 ^
            b_data->data4 ^ b_data->data5 ^ b_data->data6;
    if (temp == b_data->checksum)
    {
        printf(">> Verification SUCCESS (Result: 0x00)\r\n");
    }
    else
    {
        printf("Corrupted Data: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\r\n",
               b_data->data1, b_data->data2, b_data->data3,
               b_data->data4, b_data->data5, b_data->data6);

        printf(">> Verification FAIL (Result: 0x%02x)\r\n", temp);
        printf(">> Error detected! Discarding packet.\n");
    }
}

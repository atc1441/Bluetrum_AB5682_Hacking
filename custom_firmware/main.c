#include "stdio.h"
#include "stdint.h"
#include "macro.h"
#include <string.h>
#include "sfr.h"
#include "util.h"

#define DUMP_START_ADDRESS 0x000000
#define DUMP_SIZE 0x4000
#define BUFFER_SIZE 0x100

#define LED_HIGH() GPIOESET = BIT(7);
#define LED_LOW() GPIOECLR = BIT(7);
#define LED1_HIGH() GPIOBSET = BIT(0);
#define LED1_LOW() GPIOBCLR = BIT(0);

#define SPI_CS_PIN 2
#define SPI_SCK_PIN 4
#define SPI_MOSI_PIN 5
#define SPI_MISO_PIN 1

#define SPI_WP_PIN 0   // Unknown
#define SPI_HOLD_PIN 3 // Unknown

// Pinout Flash Internal
#define FLASH_SELECT() GPIOGCLR = BIT(SPI_CS_PIN);
#define FLASH_DESELECT() GPIOGSET = BIT(SPI_CS_PIN);
#define SPI_SCK_HIGH() GPIOGSET = BIT(SPI_SCK_PIN);
#define SPI_SCK_LOW() GPIOGCLR = BIT(SPI_SCK_PIN);
#define SPI_MOSI_HIGH() GPIOGSET = BIT(SPI_MOSI_PIN);
#define SPI_MOSI_LOW() GPIOGCLR = BIT(SPI_MOSI_PIN);
#define SPI_MISO_READ() (GPIOG & BIT(SPI_MISO_PIN))

#define SPI_WP_HIGH() GPIOGSET = BIT(SPI_WP_PIN);
#define SPI_WP_LOW() GPIOGCLR = BIT(SPI_WP_PIN);
#define SPI_HOLD_HIGH() GPIOGSET = BIT(SPI_HOLD_PIN);
#define SPI_HOLD_LOW() GPIOGCLR = BIT(SPI_HOLD_PIN);

#define SPI_SCK_OUTPUT() GPIOGDIR &= ~BIT(SPI_SCK_PIN);
#define SPI_MOSI_OUTPUT() GPIOGDIR &= ~BIT(SPI_MOSI_PIN);
#define SPI_MISO_INPUT() GPIOGDIR |= BIT(SPI_MISO_PIN);
#define FLASH_CS_OUTPUT() GPIOGDIR &= ~BIT(SPI_CS_PIN);
#define FLASH_WP_OUTPUT() GPIOGDIR &= ~BIT(SPI_WP_PIN);
#define FLASH_HOLD_OUTPUT() GPIOGDIR &= ~BIT(SPI_HOLD_PIN);

uint8_t spi_transfer(uint8_t data)
{
    uint8_t i;
    uint8_t received_data = 0;

    for (i = 0; i < 8; i++)
    {
        if (data & 0x80)
        {
            SPI_MOSI_HIGH();
        }
        else
        {
            SPI_MOSI_LOW();
        }
        data <<= 1;
        SPI_SCK_HIGH();
        received_data <<= 1;
        if (SPI_MISO_READ())
        {
            received_data |= 1;
        }

        SPI_SCK_LOW();
    }
    return received_data;
}

uint32_t flash_read_id()
{
    uint8_t manufacturer_id, memory_type, capacity;
    uint32_t readID = 0;

    FLASH_SELECT();
    spi_transfer(0x9F);
    manufacturer_id = spi_transfer(0x00);
    memory_type = spi_transfer(0x00);
    capacity = spi_transfer(0x00);
    FLASH_DESELECT();

    readID = (manufacturer_id << 16) | (memory_type << 8) | capacity;

    return readID;
}

void flash_read_data(uint32_t address, uint8_t *buffer, uint32_t length)
{
    FLASH_SELECT();
    spi_transfer(0x03);
    spi_transfer((address >> 16) & 0xFF);
    spi_transfer((address >> 8) & 0xFF);
    spi_transfer(address & 0xFF);

    for (uint32_t i = 0; i < length; i++)
    {
        buffer[i] = spi_transfer(0x00);
    }
    FLASH_DESELECT();
}

void memory_read_data(uint32_t address, uint8_t *buffer, uint32_t length)
{
    memcpy(buffer, (const void *)address, length);
}

void print_hex_dump(const uint8_t *buffer, uint32_t length, uint32_t base_address)
{
    uint32_t i, j;

    for (i = 0; i < length; i += 16)
    {
        my_printf("%08X: ", base_address + i);
        for (j = 0; j < 16; j++)
        {
            if (i + j < length)
            {
                my_printf("%02X ", buffer[i + j]);
            }
            else
            {
                my_printf("   ");
            }
        }
        my_printf(" |");
        for (j = 0; j < 16; j++)
        {
            if (i + j < length)
            {
                if (buffer[i + j] >= 0x20 && buffer[i + j] <= 0x7E)
                {
                    my_printf("%c", buffer[i + j]);
                }
                else
                {
                    my_printf(".");
                }
            }
        }
        my_printf("|\r\n");
    }
}

void dump_flash_area(uint32_t start_address, uint32_t total_size)
{
    uint8_t buffer[BUFFER_SIZE];
    uint32_t bytes_remaining = total_size;
    uint32_t current_address = start_address;
    my_printf("\r\n--- Flash Dump von 0x%08X bis 0x%08X ---\r\n", start_address, start_address + total_size - 1);
    while (bytes_remaining > 0)
    {
        uint32_t chunk_size = (bytes_remaining > BUFFER_SIZE) ? BUFFER_SIZE : bytes_remaining;
        flash_read_data(current_address, buffer, chunk_size);
        print_hex_dump(buffer, chunk_size, current_address);
        bytes_remaining -= chunk_size;
        current_address += chunk_size;
    }

    my_printf("--- Flash Dump Ende ----\r\n\r\n");
}

void dump_memory_area(uint32_t start_address, uint32_t total_size)
{
    uint8_t buffer[BUFFER_SIZE];
    uint32_t bytes_remaining = total_size;
    uint32_t current_address = start_address;
    my_printf("\r\n--- Flash Dump von 0x%08X bis 0x%08X ---\r\n", start_address, start_address + total_size - 1);
    while (bytes_remaining > 0)
    {
        uint32_t chunk_size = (bytes_remaining > BUFFER_SIZE) ? BUFFER_SIZE : bytes_remaining;
        memory_read_data(current_address, buffer, chunk_size);
        print_hex_dump(buffer, chunk_size, current_address);
        bytes_remaining -= chunk_size;
        current_address += chunk_size;
    }

    my_printf("--- Flash Dump Ende ----\r\n\r\n");
}

typedef void (*ReadEfuseFuncPtr)(uint8_t *);
ReadEfuseFuncPtr readEfuse = (ReadEfuseFuncPtr)0x80292;
uint32_t counter = 0;
int main(uint32_t ptr_data[])
{
    // for(int i=0;i<1000;i++)
    //(*((int *)0x80000 + i)) = 0;
    // my_printf("%08X : %02X\r\n", 0x3b000 + i, (*((int *)0x3b000 + i)) & 0xff);
    // dump_memory_area(0x3b000, 0x4000);
    // print_hex_dump(ptr_data[0], 0x100, ptr_data[0]);
    // print_hex_dump(ptr_data[1], 0x100, ptr_data[1]);
    WDT_DIS();
    GPIOGDE = 0x3F;
    GPIOGFEN = 0x00;

    GPIOEDIR &= ~BIT(7);
    GPIOBDIR &= ~BIT(0);

    FLASH_CS_OUTPUT();
    SPI_SCK_OUTPUT();
    SPI_MOSI_OUTPUT();
    SPI_MISO_INPUT();
    FLASH_WP_OUTPUT();
    FLASH_HOLD_OUTPUT();
    SPI_WP_HIGH();
    SPI_HOLD_HIGH();

    uint32_t address_to_read = ((uint8_t *)ptr_data[1])[4] | ((uint8_t *)ptr_data[1])[3] << 8 | ((uint8_t *)ptr_data[1])[2] << 16 | ((uint8_t *)ptr_data[1])[1] << 24;

    uint8_t readFuses[8] = {0};
    
    readEfuse(&readFuses);

    my_printf("\r\nEfuse: %02X %02X %02X %02X\r\n", readFuses[0],readFuses[1],readFuses[2], readFuses[3]);
    my_printf("\r\nFlash-ID: %08X %08X\r\n", flash_read_id(), address_to_read);

    //dump_flash_area(address_to_read, DUMP_SIZE);
    //dump_memory_area(address_to_read, DUMP_SIZE);

    return 0;
    while (1)
    {
        WDT_DIS();
        LED_HIGH();
        LED1_HIGH();
        delay(150000);
        LED_LOW();
        LED1_LOW();
        delay(150000);
        counter++;
        uint32_t flashId = flash_read_id();
        my_printf("Loop %u, Flash-ID: %08X\r\n", counter, flashId);
    }
    return 0;
}
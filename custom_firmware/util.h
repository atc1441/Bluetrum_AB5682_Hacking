#pragma once
#include "stdio.h"
#include "stdint.h"
#include "macro.h"
#include <string.h>
#include "sfr.h"

void print(const char *str);
void hsuart_send(uint8_t *buf, uint16_t len);
void* my_memcpy(void* ziel, const void* quelle, size_t anzahl);
int my_printf(const char *format, ...);
void delay(volatile uint32_t count);

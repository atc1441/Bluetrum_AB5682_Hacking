#include "stdio.h"
#include "stdint.h"
#include "macro.h"
#include <string.h>
#include <unistd.h>
#include "sfr.h"
#include "util.h"
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>

#define HSUART_DMA_BUF_LEN 64
static uint32_t hsuart_dma_tx_buf[HSUART_DMA_BUF_LEN];

#undef errno
extern int errno;

void *_sbrk(int incr) {
    errno = ENOMEM;
    return (void *)-1;
}
int _close(int file) {
    errno = EBADF;
    return -1;
}
int _lseek(int file, int ptr, int dir) {
    errno = ESPIPE;
    return -1;
}
int _read(int file, char *ptr, int len) {
    errno = EBADF;
    return -1;
}
int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR;
    return 0;
}
int _isatty(int file) {
    if (file == 1 || file == 2) {
        return 1;
    }
    errno = EBADF;
    return 0;
}
int _getpid(void) {
    return 1;
}
int _kill(int pid, int sig) {
    errno = EINVAL;
    return -1;
}
void _exit(int status) {
    while (1) {}
}

void delay(volatile uint32_t count) {
    while (count--) {
    }
}

size_t strlen_for_loop(const char *str)
{
    size_t len = 0;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

void print(const char *str)
{
    uint16_t len = strlen_for_loop(str);
    if (len > 0) {
        hsuart_send((uint8_t *)str, len);
    }
}

int puts(const char *str)
{
    uint16_t len = strlen_for_loop(str);
    if (len > 0) {
        hsuart_send((uint8_t *)str, len);
    }
    return 1;
}

int _write(int file, char *ptr, int len)
{
    if (file != STDOUT_FILENO && file != STDERR_FILENO) {
        return -1;
    }
    hsuart_send((uint8_t *)ptr, (uint16_t)len);
    return len;
}

void hsuart_send(uint8_t *buf, uint16_t len)
{
    if(len > (4 * HSUART_DMA_BUF_LEN)) {
        len = 4 * HSUART_DMA_BUF_LEN;
    }
    HSUT0CPND = BIT(1);
    HSUT0CPND = BIT(13);
    my_memcpy(hsuart_dma_tx_buf, buf, len);
    HSUT0TXADR = DMA_ADR(hsuart_dma_tx_buf);
    HSUT0TXCNT = len;
}

void* my_memcpy(void* ziel, const void* quelle, size_t anzahl) {
    char* ziel_ptr = (char*)ziel;
    const char* quelle_ptr = (const char*)quelle;
    for (size_t i = 0; i < anzahl; i++) {
        ziel_ptr[i] = quelle_ptr[i];
    }
    return ziel;
}

void my_putchar(char c)
{
    hsuart_send((uint8_t *)&c, 1);
	delay(300);
}

static int print_number_adv(unsigned long long num, int base, int width, int zero_pad, const char *digits)
{
    char buffer[24];
    int i = 0;
    int count = 0;

    if (num == 0) {
        buffer[i++] = '0';
    } else {
        while (num > 0) {
            buffer[i++] = digits[num % base];
            num /= base;
        }
    }

    int num_len = i;
    int padding = width - num_len;

    if (!zero_pad && padding > 0) {
        while (padding-- > 0) {
            my_putchar(' ');
            count++;
        }
    }
    
    if (zero_pad && padding > 0) {
        while (padding-- > 0) {
            my_putchar('0');
            count++;
        }
    }

    count += num_len;
    while (i > 0) {
        my_putchar(buffer[--i]);
    }

    return count;
}


int my_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *digits_lower = "0123456789abcdef";
    const char *digits_upper = "0123456789ABCDEF";

    while (*format) {
        if (*format == '%') {
            format++;
            
            int zero_pad = 0;
            int width = 0;
            
            if (*format == '0') {
                zero_pad = 1;
                format++;
            }
            
            while (*format >= '0' && *format <= '9') {
                width = width * 10 + (*format - '0');
                format++;
            }

            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    my_putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *s = va_arg(args, const char *);
                    if (!s) {
                        s = "(null)";
                    }
                    while (*s) {
                        my_putchar(*s++);
                        count++;
                    }
                    break;
                }
                case 'd':
                case 'i': {
                    int i = va_arg(args, int);
                    unsigned int u = i;
                    if (i < 0) {
                        my_putchar('-');
                        count++;
                        u = (unsigned int)-i;
                        width--;
                    }
                    count += print_number_adv(u, 10, width, zero_pad, digits_lower);
                    break;
                }
                case 'u': {
                    unsigned int u = va_arg(args, unsigned int);
                    count += print_number_adv(u, 10, width, zero_pad, digits_lower);
                    break;
                }
                case 'x': {
                    unsigned int x = va_arg(args, unsigned int);
                    count += print_number_adv(x, 16, width, zero_pad, digits_lower);
                    break;
                }
                case 'X': {
                    unsigned int X = va_arg(args, unsigned int);
                    count += print_number_adv(X, 16, width, zero_pad, digits_upper);
                    break;
                }
                case 'o': {
                    unsigned int o = va_arg(args, unsigned int);
                    count += print_number_adv(o, 8, width, zero_pad, digits_lower);
                    break;
                }
                case 'p': {
                    void *p = va_arg(args, void *);
                    my_putchar('0');
                    my_putchar('x');
                    count += 2;
                    count += print_number_adv((unsigned long long)p, 16, width, zero_pad, digits_lower);
                    break;
                }
                case '%': {
                    my_putchar('%');
                    count++;
                    break;
                }
                default: {
                    my_putchar('%');
                    my_putchar(*format);
                    count += 2;
                    break;
                }
            }
        } else {
            my_putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}

#ifndef _CLIB_H
#define _CLIB_H

#if A_CONTROL

#define printf(...)                     a_printf(__VA_ARGS__)
#define vprintf(...)                    a_vprintf(__VA_ARGS__)
#define print_r(...)                    a_print_r(__VA_ARGS__)
#define print_r16(...)                  a_print_r16(__VA_ARGS__)
#define print_r32(...)                  a_print_r32(__VA_ARGS__)

#define printk(...)                     my_printf(__VA_ARGS__)
#define vprintk(...)                    my_vprintf(__VA_ARGS__)
#define print_kr(...)                   my_print_r(__VA_ARGS__)
#define print_kr16(...)                 my_print_r16(__VA_ARGS__)
#define print_kr32(...)                 my_print_r32(__VA_ARGS__)

#define printf_end(x)                   {WDT_DIS(); printf(x); printf("\nTEST_END\n"); while(1);}

#define sscanf(...)                     a_sscanf(__VA_ARGS__)
#define sscank(...)                     my_sscanf(__VA_ARGS__)

void a_printf(const char *format, ...);
void a_vprintf(const char *format, va_list param);

void a_print_r(const void *buf, uint cnt);
void a_print_r16(const void *buf, uint cnt);
void a_print_r32(const void *buf, uint cnt);

int a_sscanf(const char * buf, const char * fmt, ...);

#else

#define printf(...)                     my_printf(__VA_ARGS__)
#define vprintf(...)                    my_vprintf(__VA_ARGS__)
#define print_r(...)                    my_print_r(__VA_ARGS__)
#define print_r16(...)                  my_print_r16(__VA_ARGS__)
#define print_r32(...)                  my_print_r32(__VA_ARGS__)

#define sscanf(...)                     my_sscanf(__VA_ARGS__)
#endif

void uart_putchar(char ch);
void my_printf_init(void (*putchar)(char));
void my_printf(const char *format, ...);
void my_vprintf(const char *format, va_list param);

void my_print_r(const void *buf, uint cnt);
void my_print_r16(const void *buf, uint cnt);
void my_print_r32(const void *buf, uint cnt);

int my_sscanf(const char * buf, const char * fmt, ...);

int sprintf(char *buffer, const char *format, ...);
int vsprintf(char *buffer, const char *format, va_list param);
int snprintf(char *buffer, uint maxlen, const char *format, ...);
int vsnprintf(char *buffer, uint maxlen, const char *format, va_list param);

u32 swap32(u32 val);
u16 swap16(u16 val);
uint get_be16(void *ptr);
u32 get_be32(void *ptr);
void put_be16(void *ptr, uint val);
void put_be32(void *ptr, u32 val);

uint bitset_cnt(u32 val);

void delay_5ms(uint n);
void delay_ms(uint n);
void delay_us(uint n);

u32 tick_get(void);
bool tick_check_expire(u32 tick, u32 expire_val);

#endif // _CLIB_H

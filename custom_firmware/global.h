#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stddef.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "typedef.h"
#include "macro.h"
#include "clib.h"
#include "sfr.h"

//全局中断保护 CRITICAL
#define GLOBAL_INT_DISABLE()    uint32_t cpu_ie = PICCON&BIT(0); PICCONCLR = BIT(0)
#define GLOBAL_INT_RESTORE()    PICCON |= cpu_ie

#endif // _GLOBAL_H


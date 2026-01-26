#pragma once

#include "stm32u5xx_hal.h"   // or stm32xxxx_hal.h

#ifdef __cplusplus
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <string>
#include <algorithm>
#include "WString.h"
#include "print.h"

#if __has_include("cmsis_os2.h")
  #include "cmsis_os2.h"
  static inline void delay(uint32_t ms) { osDelay(ms); }
#elif __has_include("cmsis_os.h")
  #include "cmsis_os.h"
  static inline void delay(uint32_t ms) { osDelay(ms); }
#else
  static inline void delay(uint32_t ms) { HAL_Delay(ms); }
#endif

static inline uint32_t millis() { return HAL_GetTick(); }

typedef uint8_t byte;

class Stream {
public:
    virtual ~Stream() = default;
    virtual int available() { return 0; }
    virtual int read() { return -1; }
    virtual size_t write(uint8_t) { return 0; }
    virtual size_t write(const uint8_t*, size_t) { return 0; }
};

#endif // __cplusplus

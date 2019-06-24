#pragma once
#include <esp_err.h>


#if defined(NDEBUG) || defined(ERET_ABORT)
#define ERET(x) ESP_ERROR_CHECK(x)
#elif defined(CONFIG_COMPILER_OPTIMIZATION_ASSERTIONS_SILENT)
#define ERET(x) do {                          \
    esp_err_t __err_rc = (x);                 \
    if (__err_rc != ESP_OK) return __err_rc;  \
  } while(0)
#else
#define ERET(x) do {                                                            \
    esp_err_t __err_rc = (x);                                                   \
    if (__err_rc != ESP_OK) {                                                   \
      _esp_error_check_failed(__err_rc, __FILE__, __LINE__, __ASSERT_FUNC, #x); \
      return __err_rc;                                                          \
    } while(0)
#endif

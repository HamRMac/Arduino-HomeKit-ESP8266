#ifndef __HOMEKIT_DEBUG_H__
#define __HOMEKIT_DEBUG_H__

// Include ESPHOME DEBUGGER
#include "esphome/core/log.h"

namespace esphome {
    namespace homekit_client {
        extern const char *TAG;
    }
}

extern const char *esphome::homekit_client::TAG;

/*
#include <stdlib.h>
#include <stdio.h>
#include "Arduino.h"
#include <string.h>
*/

typedef unsigned char byte;

// Error Levels
#define HOMEKIT_NO_LOG 0
#define HOMEKIT_LOG_ERROR 1
#define HOMEKIT_LOG_INFO 2
#define HOMEKIT_LOG_DEBUG 3

#ifndef HOMEKIT_LOG_LEVEL
#define HOMEKIT_LOG_LEVEL HOMEKIT_LOG_INFO
#endif

#define HOMEKIT_PRINTF XPGM_PRINTF

// Debug Messages
#if HOMEKIT_LOG_LEVEL >= HOMEKIT_LOG_DEBUG

#define DEBUG(message, ...)  ESP_LOGV(esphome::homekit_client::TAG,">>> %s: " message "\n", __func__, ##__VA_ARGS__)
//static uint32_t start_time = 0;
#define DEBUG_TIME_BEGIN()//  start_time=millis();
#define DEBUG_TIME_END(func_name)//  ESP_LOGVV(esphome::homekit_client::TAG,"### [%7d] %s took %6dms\n", millis(), func_name, (millis() - start_time));
#define DEBUG_HEAP() ESP_LOGV("Free heap: %d", ESP.getFreeHeap();

#else

#define DEBUG(message, ...)
#define DEBUG_TIME_BEGIN()
#define DEBUG_TIME_END(func_name)
#define DEBUG_HEAP()

#endif

// Error Messages
#if HOMEKIT_LOG_LEVEL >= HOMEKIT_LOG_ERROR

#define ERROR(message, ...) ESP_LOGE(esphome::homekit_client::TAG,"!!! [%7d] HomeKit: " message "\n", millis(), ##__VA_ARGS__)

#else

#define ERROR(message, ...)

#endif

// Info Messages
#if HOMEKIT_LOG_LEVEL >= HOMEKIT_LOG_INFO

#define INFO(message, ...) ESP_LOGI(esphome::homekit_client::TAG,">>> [%7d] HomeKit: " message "\n", millis(), ##__VA_ARGS__)
#define INFO_HEAP() INFO("Free heap: %d", system_get_free_heap_size());

#else

#define INFO(message, ...)
#define INFO_HEAP()

#endif

char *binary_to_string(const byte *data, size_t size);
void print_binary(const char *prompt, const byte *data, size_t size);

#endif // __HOMEKIT_DEBUG_H__

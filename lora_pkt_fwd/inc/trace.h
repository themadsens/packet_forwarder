/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
  (C)2013 Semtech-Cycleo

Description:
    LoRa concentrator : Packet Forwarder trace helpers

License: Revised BSD License, see LICENSE.TXT file include in the project
Maintainer: Michael Coracin
*/


#ifndef _LORA_PKTFWD_TRACE_H
#define _LORA_PKTFWD_TRACE_H

#include "sys/time.h"

#define DEBUG_PKT_FWD   1
#define DEBUG_JIT       1
#define DEBUG_JIT_ERROR 1
#define DEBUG_TIMERSYNC 0
#define DEBUG_BEACON    0
#define DEBUG_LOG       1

#define MSG(fmt, ...) /* message that is destined to the user */                                  \
            do  {                                                                                 \
                struct timeval tv;                                                                \
                gettimeofday(&tv, NULL);                                                          \
                fprintf(stdout, "%02ld.%03ld: " fmt, tv.tv_sec%60, tv.tv_usec/1000, ##__VA_ARGS__); \
            } while (0)
#define MSG_DEBUG(FLAG, fmt, ...)                                                                         \
            do  {                                                                                         \
                if (FLAG) {                                                                               \
                    struct timeval tv;                                                                    \
                    gettimeofday(&tv, NULL);                                                              \
                    fprintf(stdout, "%02ld.%03ld: %s:%d:%s(): " fmt, tv.tv_sec%60, tv.tv_usec/1000, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
            } } while (0)



#endif
/* --- EOF ------------------------------------------------------------------ */

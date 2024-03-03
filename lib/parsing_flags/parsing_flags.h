#pragma once

#include <stdint.h>

#define L_FLAG          0b00000001
#define A_FLAG          0b00000010
#define V_FLAG          0b00000100
#define H_FLAG          0b00001000
#define DMINUS_HELP     0b10000000
#define DMINUS_VERSION  0b01000000

#define CHAR_L_FLAG 'l'
#define CHAR_A_FLAG 'a'
#define CHAR_V_FLAG 'v'
#define CHAR_H_FLAG 'h'

#define STR_DMINUS_HELP "--help"
#define STR_DMINUS_VERSION "--version"

enum STATUS : uint8_t
{
    PARSE_OK,
    PARSE_STOP,
    PARSE_ERROR,
};
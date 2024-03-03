#pragma once

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <parsing_flags/parsing_flags.h>

enum STATUS Parse_Flags(const char* input, uint8_t* result_expression);
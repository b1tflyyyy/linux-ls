#pragma once

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <parsing_flags/parsing_flags.h>

enum STATUS Parse_Flags(const char* input, uint8_t* result);
enum STATUS Set_Flag_By_Input_Data(char symbol, uint8_t* result);
void Set_DMinus_Flag(uint8_t* result, uint8_t flag);
#include "parser.h"

enum STATUS Parse_Flags(const char* input, uint8_t* result)
{
    if (input[0] == '-' && input[1] == '-')
    {
        if (!strcmp(STR_DMINUS_HELP, input))
        {
            Set_DMinus_Flag(result, DMINUS_HELP);
            return PARSE_STOP;
        }
        if (!strcmp(STR_DMINUS_VERSION, input))
        {
            Set_DMinus_Flag(result, DMINUS_VERSION);
            return PARSE_STOP;
        }
    }
    else if (input[0] == '-' && input[1] != '-')
    {
        size_t counter = 0;
        while (input[++counter] != '\0')
        {
            if (Set_Flag_By_Input_Data(input[counter], result) != PARSE_OK)
            {
                return PARSE_ERROR;
            }
        }

        return PARSE_OK;
    }

    return PARSE_ERROR;
}

enum STATUS Set_Flag_By_Input_Data(char symbol, uint8_t* result)
{
    switch (symbol)
    {
        case CHAR_A_FLAG:
        {
            *result |= A_FLAG;
            break;
        }
        case CHAR_H_FLAG:
        {
            *result |= H_FLAG;
            break;
        }
        case CHAR_L_FLAG:
        {
            *result |= L_FLAG;
            break;
        }
        case CHAR_V_FLAG:
        {
            *result |= V_FLAG;
            break;
        }
        default:
        {
            return PARSE_ERROR;
        }
    }

    return PARSE_OK;
}

void Set_DMinus_Flag(uint8_t* result, uint8_t flag)
{
    *result |= flag;
    *result &= flag;
}
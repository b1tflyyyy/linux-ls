#include "parser.h"

// TODO: rewrite
enum STATUS Parse_Flags(const char* input, uint8_t* result_expression)
{
    if (input[0] == '-' && input[1] == '-')
    {
        if (!strcmp(STR_DMINUS_HELP, input))
        {
            *result_expression |= DMINUS_HELP;
            *result_expression &= DMINUS_HELP;

            return PARSE_STOP;
        }
        if (!strcmp(STR_DMINUS_VERSION, input))
        {
            *result_expression |= DMINUS_VERSION;
            *result_expression &= DMINUS_VERSION;

            return PARSE_STOP;
        }
    }
    else if (input[0] == '-' && input[1] != '-')
    {
        size_t counter = 1;
        while (input[counter] != '\0')
        {
            switch (input[counter++])
            {
                case CHAR_A_FLAG:
                {
                    *result_expression |= A_FLAG;
                    break;
                }
                case CHAR_H_FLAG:
                {
                    *result_expression |= H_FLAG;
                    break;
                }
                case CHAR_L_FLAG:
                {
                    *result_expression |= L_FLAG;
                    break;
                }
                case CHAR_V_FLAG:
                {
                    *result_expression |= V_FLAG;
                    break;
                }
                default:
                {
                    return PARSE_ERROR;
                }
            }
        }

        return PARSE_OK;
    }

    return PARSE_ERROR;
}
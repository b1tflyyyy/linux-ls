#define _GNU_SOURCE

#include <stdio.h>

#include <parser/parser.h>
#include <dir_reader/dir_reader.h>

int main(int argc, char** argv)
{
    // char input_data[5][10] = { "-laah", "-vah", "-vah", "-va", "-a" };

    uint8_t result = 0;

    for (size_t i = 1; i < argc; ++i)
    {
        enum STATUS status = Parse_Flags(argv[i], &result);
        if (status == PARSE_STOP)
        {
            break;
        }
        if (status == PARSE_ERROR)
        {
            printf("Error parsing !!!\n");
            return -1;
        }
    }

    // For test
    const char* curr_dir = get_current_dir_name();

    size_t files_count = Get_Files_Count(curr_dir);
    struct SFile_Info* files_info = Get_Files_Info(curr_dir, files_count);

    exit(EXIT_SUCCESS);
}
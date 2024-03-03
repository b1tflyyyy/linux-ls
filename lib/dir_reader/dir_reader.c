#include "dir_reader.h"

size_t Get_Files_Count(const char* target_dir)
{
    size_t counter = 0;

    DIR* dp = opendir(target_dir);
    struct dirent* ep;

    if (dp != NULL)
    {
        while ((ep = readdir(dp)) != NULL)
        {
            ++counter;
        }

        closedir(dp);
    }

    return counter;
}

struct SFile_Info* Get_Files_Info(const char* target_dir, size_t files_count)
{
    DIR* dp = opendir(target_dir);

    struct dirent* ep;
    struct stat sb;

    struct SFile_Info* files_info = (struct SFile_Info*)malloc(sizeof(struct SFile_Info) * files_count);

    if (dp != NULL)
    {
        size_t i = 0;

        while ((ep = readdir(dp)) != NULL)
        {
            stat(ep->d_name, &sb);

            struct SFile_Info tmp = { .Size=sb.st_size, .Hard_Links=sb.st_nlink, .Modified_Date=sb.st_mtime, .File_Name=ep->d_name, .File_Owner=sb.st_ino, .Apply_Group=sb.st_gid, };
            files_info[i++] = tmp;
        }

        closedir(dp);
    }

    return files_info;
}



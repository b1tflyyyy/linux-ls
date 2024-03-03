#pragma once

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#include <parsing_flags/parsing_flags.h>

struct SFile_Info
{
    off_t Size;
    nlink_t Hard_Links;
    time_t Modified_Date;
    const char* File_Name;
    uid_t File_Owner;
    gid_t Apply_Group;
};

size_t Get_Files_Count(const char* target_dir);
struct SFile_Info* Get_Files_Info(const char* target_dir, size_t files_count);
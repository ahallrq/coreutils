#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void ls(char *path);
void ftype_str(mode_t f_mode, char *out);
void fperms_str(mode_t f_mode, char *out);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ls(".");
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            ls(argv[i]);
        }
    }
    return 0;
}

void ls(char *path)
{
        struct dirent **entrylist;
        int entrylist_size;
        int entrylist_pos;
        char *corrected_path = malloc(strlen(path) + 2);

        struct stat entry_stats;

        strcpy(corrected_path, path);
        if (path[strlen(path)-1] != '/')
        {
            strcat(corrected_path, "/");
        }

        entrylist_size = scandir(corrected_path, &entrylist, NULL, alphasort);
        if (entrylist_size < 0)
        {
            const char *err = strerror(errno);
            printf("Error scanning directory '%s': %s\n", corrected_path, err);
        }
        else
        {
            for (entrylist_pos = 0; entrylist_pos < entrylist_size; entrylist_pos++)
            {
                char *full_path = malloc(strlen(path) + strlen(entrylist[entrylist_pos]->d_name) + 1);
                strcpy(full_path, corrected_path);
                strcat(full_path, entrylist[entrylist_pos]->d_name);

                if (stat(full_path, &entry_stats) < 0)
                {
                    const char *err = strerror(errno);
                    printf("Error statting file '%s': %s\n", full_path, err);
                }

                char ftype[2] = { '\0' };
                ftype_str(entry_stats.st_mode, ftype);
                char fmode[10] = { '\0' };
                fperms_str(entry_stats.st_mode, fmode);

                printf("[%s] %s - %li bytes - %s\n", 
                    ftype, 
                    entrylist[entrylist_pos]->d_name, 
                    entry_stats.st_size,
                    fmode);
                free(entrylist[entrylist_pos]);
            }
        }

        free(entrylist);
}

void fperms_str(mode_t f_mode, char *out)
{
    sprintf(out, "%s%s%s%s%s%s%s%s%s",
        (f_mode & S_IRUSR) ? "r" : "-",
        (f_mode & S_IWUSR) ? "w" : "-",
        (f_mode & S_IXUSR) ? "x" : "-",
        (f_mode & S_IRGRP) ? "r" : "-",
        (f_mode & S_IWGRP) ? "w" : "-",
        (f_mode & S_IXGRP) ? "x" : "-",
        (f_mode & S_IROTH) ? "r" : "-",
        (f_mode & S_IWOTH) ? "w" : "-",
        (f_mode & S_IXOTH) ? "x" : "-");
    return;
}

void ftype_str(mode_t f_mode, char *out)
{
    switch (f_mode & S_IFMT)
    {
        case S_IFBLK: strcpy(out, "b"); break;
        case S_IFCHR: strcpy(out, "c"); break;
        case S_IFDIR: strcpy(out, "d"); break;
        case S_IFIFO: strcpy(out, "p"); break;
        case S_IFLNK: strcpy(out, "l"); break;
        case S_IFREG: strcpy(out, "f"); break;
        case S_IFSOCK: strcpy(out, "s"); break;
        default: strcpy(out, "?"); break;
    }

    return;
}

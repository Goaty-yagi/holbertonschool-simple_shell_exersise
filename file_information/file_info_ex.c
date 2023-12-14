#include "main.h"

/**
 * file_info_ex - call file_info_ex
 * @ar: length of av
 * @av: char array pointer
 * discription: try to find file from an argumant.
 * 
 * Return: void
 */

// int stat(const char *path, struct stat *buf);

// struct stat {
//     dev_t     st_dev;     /* ID of device containing file */
//     ino_t     st_ino;     /* inode number */
//     mode_t    st_mode;    /* protection */
//     nlink_t   st_nlink;   /* number of hard links */
//     uid_t     st_uid;     /* user ID of owner */
//     gid_t     st_gid;     /* group ID of owner */
//     dev_t     st_rdev;    /* device ID (if special file) */
//     off_t     st_size;    /* total size, in bytes */
//     blksize_t st_blksize; /* blocksize for filesystem I/O */
//     blkcnt_t  st_blocks;  /* number of blocks allocated */
//     time_t    st_atime;   /* time of last access */
//     time_t    st_mtime;   /* time of last modification */
//     time_t    st_ctime;   /* time of last status change */
// }

// On success, zero is returned. On error, -1 is 
// returned, and errno is set appropriately.


void file_info_ex(int ac, char **av)
{
    unsigned int i;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
    }
    i = 1;
    while (av[i])
    {
        if (stat(av[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
}

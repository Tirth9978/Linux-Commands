#include<stdio.h>
#include<time.h>

struct inode {
    int    inode_number;     // Unique ID
    int    permissions;      // rwxrwxrwx
    int    owner_id;         // UID
    int    group_id;         // GID
    int    size;             // File size in bytes
    int    link_count;       // Number of hard links
    time_t last_accessed;    // atime
    time_t last_modified;    // mtime  
    time_t inode_changed;    // ctime
    int    blocks[15];       // Pointers to data blocks
    // ... and more
};

int main(){

}
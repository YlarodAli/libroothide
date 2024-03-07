//
// Created by Ylarod on 2024/3/7.
//

#include <cstdlib>
#include <cstdio>
#include <sys/fcntl.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>
#include <mach-o/fat.h>
#include <mach-o/loader.h>

bool is_macho(const char *file) {
    int fd = open(file, O_RDWR);
    if (fd < 0) {
        return false;
    }

    struct fat_header header{};
    read(fd, &header, sizeof(header));

    switch (header.magic) {
        case FAT_CIGAM: {
            if (OSSwapInt32(header.nfat_arch) > 30) {
                return false; // Java byte code
            }
            return true;
        }
        case FAT_MAGIC:
        case FAT_MAGIC_64:
        case FAT_CIGAM_64:
        case MH_MAGIC:
        case MH_CIGAM:
        case MH_MAGIC_64:
        case MH_CIGAM_64:
            return true;
        default:
            return false;
    }
}

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [target]\n", getprogname());
        return 0;
    }

    const char *target = argv[1];
    if (is_macho(target)){
        printf("%s\n", target);
    }

    return 0;
}
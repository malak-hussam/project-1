#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    if (rename(argv[1], argv[2]) == 0) {
        printf("File moved.\n");
    } else {
        perror("Error moving file");
        return 1;
    }

    return 0;
}
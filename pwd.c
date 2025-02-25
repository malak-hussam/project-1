#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <linux/limits.h>

int main() {
    char cwd[PATH_MAX]; 
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s Correct/n", cwd);
    } else {
        
        printf("ERROR");
        return 1 ;
    }

    return 0;
}

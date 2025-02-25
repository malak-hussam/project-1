#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    // open file source  
    FILE *filesource = fopen(argv[1],"rb");
    if (filesource == NULL)
    {
        perror("error in opening this file");
        return 1 ;
    }
    // destination
    char destination[1024];
    FILE*filepath = fopen(destination , "wb") ;
    if (filepath == NULL)
    {
        perror("error in openiog destination file");
        return 1 ;
    }
    // copy 
    char buffer[1024] ;
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), filesource)) > 0) {
        fwrite(buffer, 1, bytes_read, filepath);
    }

    // Close both files
    fclose(filesource);
    fclose(filepath);

    printf("File copied successfully to %s\n", destination);
    return 0;
}

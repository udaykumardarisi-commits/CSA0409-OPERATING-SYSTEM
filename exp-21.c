#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char write_buf[] = "Hello, this is a test file for UNIX system calls.\n";
    char read_buf[100];

    // Create and open file for writing
    fd = open("sample.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Error creating file");
        return 1;
    }
    write(fd, write_buf, sizeof(write_buf));
    close(fd);

    // Open file for reading
    fd = open("sample.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    read(fd, read_buf, sizeof(read_buf));
    printf("File Content:\n%s\n", read_buf);
    close(fd);

    return 0;
}

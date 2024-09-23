#define _POSIX_C_SOURCE 200112L
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Sleeping for 100 microseconds...\n");
    usleep(100);
    printf("Done sleeping.\n");
    return 0;
}
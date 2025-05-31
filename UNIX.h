#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/un.h>

int open_unix_socket(const char* path);
int close_unix_socket(int fd);

#include "UNIX.h"

int open_unix_socket(const char *path) {
	struct sockaddr_un addr;
	memset(&addr, 0, sizeof addr);
	addr.sun_family = AF_UNIX;
	strncpy(addr.sun_path, path, sizeof addr.sun_path-1);
	unlink(path);

	int sockfd, client;
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("Could not open AF_UNIX socket");
		exit(EXIT_FAILURE);
	}
	if (bind(sockfd, (struct sockaddr*)&addr, sizeof addr) < 0) {
		perror("Could not bind to AF_UNIX socket");
		exit(EXIT_FAILURE);
	}
	if (listen(sockfd, 1) < 0) {
		perror("Could not listen on AF_UNIX socket");
		exit(EXIT_FAILURE);
	}
	client = accept(sockfd, NULL, NULL);
	return client;
}

int close_unix_socket(int fd) {
    return close(fd);
}

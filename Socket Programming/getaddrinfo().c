#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

int main() {
    struct addrinfo hints, *result, *p;
    
    // Setup what type of addresses we want
    memset(&hints, 0, sizeof(hints));
    
    hints.ai_family = AF_INET;      // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    
    // Convert hostname to addresses
    int status = getaddrinfo("google.com", "80", &hints, &result);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        return 1;
    }
    
    // Loop through all returned addresses
    for (p = result; p != NULL; p = p->ai_next) {
        // p->ai_addr contains ready-to-use socket address
        printf("Found address!\n");
    }
    
    // MUST FREE the memory!
    freeaddrinfo(result);
    
    return 0;
}
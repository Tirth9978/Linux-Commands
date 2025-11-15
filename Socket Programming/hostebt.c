#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

int main() {
    struct hostent *he;
    struct in_addr **addr_list;
    
    // Get host information
    he = gethostbyname("google.com");
    
    if (he == NULL) {
        printf("Failed to resolve hostname\n");
        return 1;
    }
    
    // Print official name
    printf("Official name: %s\n", he->h_name);
    
    // Print aliases
    printf("Aliases: ");
    for (int i = 0; he->h_aliases[i] != NULL; i++) {
        printf("%s ", he->h_aliases[i]);
    }
    printf("\n");
    
    // Print IP addresses
    printf("IP addresses: ");
    addr_list = (struct in_addr **)he->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        printf("%s ", inet_ntoa(*addr_list[i]));
    }
    printf("\n");
    
    return 0;
}
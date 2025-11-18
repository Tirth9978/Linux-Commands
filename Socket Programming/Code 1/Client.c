#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int s;  // socket
    struct sockaddr_in a;  // server address
    char buffer[100];  // to store received message
    
    // Step 1: Create socket (get a telephone)
    s = socket(AF_INET, SOCK_STREAM, 0);
    
    // Step 2: Setup server address (who to call?)
    a.sin_family = AF_INET;
    a.sin_port = htons(8080);  // server's port
    inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);  // localhost
    
    // Step 3: Connect to server (make the call)
    connect(s, (struct sockaddr*)&a, sizeof(a));
    printf("Connected to server! 📞\n");
    
    // Step 4: Receive message (listen to server)
    recv(s, buffer, sizeof(buffer), 0);
    printf("Server says: %s", buffer);
    
    // Step 5: Hang up
    close(s);
    
    return 0;
}
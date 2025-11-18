#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int s, c;  // s = server socket, c = client socket
    struct sockaddr_in a;  // address info
    char msg[] = "Hello from server! 👋\n";
    
    // Step 1: Create socket (get a telephone)
    s = socket(AF_INET, SOCK_STREAM, 0);
    
    // Step 2: Setup address (what's your phone number?)
    a.sin_family = AF_INET;
    a.sin_port = htons(8080);  // port 8080
    a.sin_addr.s_addr = INADDR_ANY;  // accept calls from anyone
    
    // Step 3: Bind socket to address (plug in the telephone)
    bind(s, (struct sockaddr*)&a, sizeof(a));
    
    // Step 4: Start listening (wait for calls)
    listen(s, 5);  // max 5 waiting calls
    
    printf("Server waiting for connection... ⏳\n");
    
    // Step 5: Accept connection (answer the call)
    c = accept(s, NULL, NULL);
    
    // Step 6: Send message (talk to client)
    send(c, msg, sizeof(msg), 0);
    printf("Message sent! ✅\n");
    
    // Step 7: Hang up
    close(c);
    close(s);
    
    return 0;
}
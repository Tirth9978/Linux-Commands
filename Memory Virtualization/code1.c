// This program shows virtual addresses
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Code location: %p\n", (void*)main);    // 🏠 Virtual address
    printf("Heap location: %p\n", malloc(1));      // 📦 Virtual address  
    int x = 3;
    printf("Stack location: %p\n", (void*)&x);     // 📚 Virtual address
    return x;
}
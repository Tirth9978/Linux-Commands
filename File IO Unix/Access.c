#include <unistd.h>
#include <stdio.h>

int main() {
    if (access("secret.txt", R_OK) == 0) {
        printf("✅ I can read secret.txt!\n");
    } else {
        printf("❌ I cannot read secret.txt!\n");
    }
    return 0;
}
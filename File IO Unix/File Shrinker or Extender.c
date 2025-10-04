#include <unistd.h>

// Make log file exactly 1MB
truncate("app.log", 1024 * 1024);

// Empty a file (0 bytes)
truncate("temp.txt", 0);
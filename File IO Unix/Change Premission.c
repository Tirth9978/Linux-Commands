#include <sys/stat.h>

// Make file readable by everyone
chmod("public.txt", 0644);  // rw-r--r--

// Make file private (only owner)
chmod("secret.txt", 0600);  // rw-------

// Make script executable
chmod("script.sh", 0755);   // rwxr-xr-x
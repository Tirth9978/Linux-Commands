
#include <unistd.h>

// Delete temporary file
unlink("temp_data.tmp");

// Remove one hard link (file stays if other links exist)
unlink("backup.txt");
#include <unistd.h>

// Create backup of important file
link("database.db", "database_backup.db");

// Now both point to SAME data!
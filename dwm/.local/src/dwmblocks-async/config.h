#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(cmd, interval, signal, position).
#define BLOCKS(X)           \
    X("sb-mic", 0, 6, 0)       \
    X("sb-volume", 0, 7, 0)    \
    X("sb-kbselect", 0, 8, 0)  \
    X("sb-date", 1, 10, 0)     \
    X("sb-power", 0, 5, 1)     \
    X("sb-loadavg", 5, 2, 1)   \
    X("sb-memory", 60, 3, 1)   \
    X("sb-disk", 300, 4, 1)    \
    X("sb-nettraf", 5, 1, 2)   \
    X("sb-internet", 60, 9, 2)

#endif  // CONFIG_H

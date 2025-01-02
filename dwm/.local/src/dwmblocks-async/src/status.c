#include "status.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "block.h"
#include "config.h"
#include "util.h"
#include "x11.h"

static bool has_status_changed(const status *const status) {
    return strcmp(status->current, status->previous) != 0;
}

status status_new(const block *const blocks,
                  const unsigned short block_count) {
    status status = {
        .current = {[0] = '\0'},
        .previous = {[0] = '\0'},

        .blocks = blocks,
        .block_count = block_count,
    };

    return status;
}

bool status_update(status *const status) {
    (void)strncpy(status->previous, status->current, LEN(status->current));
    status->current[0] = '\0';

    char top[LEN(status->current)] = "\0";
    char bottom_left[LEN(status->current)] = "\0";
    char bottom_right[LEN(status->current)] = "\0";

    for (unsigned short i = 0; i < status->block_count; ++i) {
        const block *const block = &status->blocks[i];

        char* current = top;
        if (block->position == 1)
            current = bottom_left;
        else if (block->position == 2)
            current = bottom_right;

        if (strlen(block->output) > 0) {
#if LEADING_DELIMITER
            (void)strncat(current, DELIMITER, LEN(DELIMITER));
#else
            if (status->current[0] != '\0') { 
                (void)strncat(current, DELIMITER, LEN(DELIMITER));
            }
#endif

#if CLICKABLE_BLOCKS
            if (block->signal > 0) {
                const char signal[] = {(char)block->signal, '\0'};
                (void)strncat(current, signal, LEN(signal));
            }
#endif

            (void)strncat(current, block->output, LEN(block->output));
        }
    }

#if TRAILING_DELIMITER
    if (top != '\0') {
        (void)strncat(top, DELIMITER, LEN(DELIMITER));
    }
    if (bottom != '\0') {
        (void)strncat(bottom, DELIMITER, LEN(DELIMITER));
    }
#endif

    (void)strncat(status->current, top, LEN(top) - 1);
    (void)strncat(status->current, ";", LEN(";"));
    (void)strncat(status->current, bottom_left, LEN(bottom_left) - 1);
    (void)strncat(status->current, ";", LEN(";"));
    (void)strncat(status->current, bottom_right, LEN(bottom_right) - 1);
    return has_status_changed(status);
}

int status_write(const status *const status, const bool is_debug_mode,
                 x11_connection *const connection) {
    if (is_debug_mode) {
        (void)printf("%s\n", status->current);
        return 0;
    }

    if (x11_set_root_name(connection, status->current) != 0) {
        return 1;
    }

    return 0;
}

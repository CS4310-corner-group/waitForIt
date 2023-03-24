#ifndef __LIBPOSIX_RENICE_H
#define __LIBPOSIX_RENICE_H

#include <Macros.h>
#include "types.h"


/**
 * @brief Change the priority of a process
 *
 *
 * @param pid Process ID of process to modify.
 * @param stat_loc Points to an integer for storing the exit status.
 * @param priority What priority to update to.
 * @param options Options
 * @return Modify priority
 */
extern C pid_t modprio(pid_t pid, int *stat_loc, int options, int priority);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_RENICE_H */

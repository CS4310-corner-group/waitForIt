/*
 * Copyright (C) 2009 Niek Linnenbank
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIBPOSIX_RENICE_H
#define __LIBPOSIX_RENICE_H

#include <Macros.h>
#include "types.h"

/**
 * @addtogroup lib
 * @{
 *
 * @addtogroup libposix
 * @{
 */

/**
 * Returns the exit status of the child process
 *
 * @param st Contains the stat_loc value from waitpid()
 *
 * @return Exit status of the child process
 */
#define WEXITSTATUS(st) (st)

/**
 * @brief Change the priority of a process
 *
 * The wait() and waitpid() functions shall obtain status information
 * pertaining to one of the caller's child processes. Various options
 * permit status information to be obtained for child processes that
 * have terminated or stopped. If status information is available for
 * two or more child processes, the order in which their status is
 * reported is unspecified.
 *
 * @param pid Process ID of process to modify.
 * @param priority What priority to update to.
 * @param options Optional flags.
 *
 * @return Process ID of the child on success or -1 on error
 */
extern C pid_t renice(pid_t pid, int priority);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_WAIT_H */

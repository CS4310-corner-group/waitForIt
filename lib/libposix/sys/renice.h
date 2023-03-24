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
 * @param st Contains the stat_loc value from renice()
 *
 * @return Exit status of the child process
 */
#define WEXITSTATUS(st) (st)

/**
 * @brief Change the priority of a process
 *
 *
 * @param pid Process ID of process to modify.
 * @param stat_loc Points to an integer for storing the exit status.
 * @param priority What priority to update to.
 *
 * @return Process ID of the child on success or -1 on error
 */
extern C pid_t modprio(pid_t pid, int *stat_loc, int priority);

/**
 * @}
 * @}
 */

#endif /* __LIBPOSIX_RENICE_H */

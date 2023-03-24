#include <FreeNOS/User.h>
#include "modprio.h"
#include "sys/types.h"
#include <errno.h>

pid_t modprio(pid_t pid, int *stat_loc, int options, int priority)
{
    const ulong result = (ulong) ProcessCtl(pid, ModifyPriority, priority);

    switch ((const API::Result) (result & 0xffff))
    {
        case API::NotFound:
            errno = ESRCH;
            return (pid_t) -1;

        case API::Success:
            if (stat_loc)
            {
                *stat_loc = result >> 16;
            }
            return pid;

        default:
            errno = EIO;
            return (pid_t) -1;
    }
}

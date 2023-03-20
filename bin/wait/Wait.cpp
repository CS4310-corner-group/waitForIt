#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"
#include <sys/types.h>
#include <sys/wait.h>


Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Waits for a process to complete");
    parser().registerPositional("PROCESS ID", "Waits until the given process is completed");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    //int pid = 0;
    ProcessID PID = atoi(arguments().get("PROCESS ID"));
    int *nullInt;

    if (waitpid(PID, nullInt, 0) == -1){
        ERROR(arguments().get("PROCESS ID") << "is not a child of this shell");
    };
   
    

    // Done
    return Success;
}

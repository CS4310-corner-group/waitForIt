#include <sys/modprio.h>
#include <stdio.h>
#include <unistd.h>
#include "Renice.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>




Renice::Renice(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Change priority of running processes");
    parser().registerPositional("PRIORITY", "Priority to change to");
    parser().registerPositional("PID", "PID of process to change priority");
    parser().registerFlag('n', "scheduling priority", "Displays priority level of processes");

}

Renice::~Renice()
{
}


Renice::Result Renice::exec()
{
    String out;
    if(arguments().get("scheduling priority")){
        //int *nullInt = 0;
        int priority = atoi(arguments().get("PRIORITY"));
        ProcessID PID = atoi(arguments().get("PID"));
        out << PID;
        modprio(PID, 0, 0, priority);
    }
    
    
    
   
    //const Vector<Argument *> & positionals = arguments().getPositionals();
    //int newPriority = positionals[0];
    //PID = positionals[1];
    //proc = procs->get(PID);
    //procs->modifyPriority(proc, priority);   
    return Success;
       
    
   
   
    
    
}
/*
 * Copyright (C) 2015 Niek Linnenbank
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


#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include "Renice.h"
#include "sys/renice.h"
#include <sys/renice.h>
#include <sys/types.h>

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
    /*
     if (modifypriority(PID, nullInt, priority) == -1){
        ERROR("Something went wrong!");
    };
    */
    modprio(PID, 0, 0, priority);
    }
    
    
    
   
    //const Vector<Argument *> & positionals = arguments().getPositionals();
    //int newPriority = positionals[0];
    //PID = positionals[1];
    //proc = procs->get(PID);
    //procs->modifyPriority(proc, priority);   
    return Success;
       
    
   
   
    
    
}
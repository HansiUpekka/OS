#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for fork(), exit() and sleep()  functions
#include <sys/types.h>  // for pid_t type
#include <sys/wait.h> // for wait()

int main()
{
    pid_t child1, child2;
    
    printf("PARENT: PID = %d\n",getpid()); // parentprocess prints its PID

    child1 = fork(); // create a child process

    if (child1 < 0)
    {
        printf("Fork Failed to create first child.\n");
        exit(1);
    }

    else if (child1 == 0)
    {
        printf ("Child 1\n");
	printf("CHILD 1 : PID = %d, PPID = %d\n\n",getpid(), getppid());
        fflush(stdout); //ensure output is flushed immediately
	sleep(20);      // keep the process running for verification
	exit(0);        //exit child process
    }
    else
    {
        child2 = fork(); // create another child process

        if (child2 < 0)
        {
            printf("Fork Failed to create second child.\n");
            exit(1);
        }
        else if (child2 == 0)
        {
            printf ("Child 2\n");
	    printf("CHILD 2 : PID = %d, PPID = %d\n\n",getpid(),getppid());
            fflush(stdout); //ensure output is flushed immediately
	    sleep(20);      //keep the process running for verification
	    exit(0);        // exit child process	
        }
        else
        {
	    // parent process
	    wait(NULL); //wait for the first child to finish
	    wait(NULL); // wait for the second child to finish
            printf ("Parent : PID = %d\n",getpid());
            fflush(stdout); //ensure output is flushed immediately
	    sleep(10); //keep the parent process running for verification
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for fork() and exit() functions
#include <sys/types.h>  // for pid_t type


int main()
{
    pid_t pid1, pid2;

    pid1 = fork(); // create a child process

    if (pid1 < 0)
    {
        printf("Fork Failed to create first child.\n");
        exit(1);
    }

    else if (pid1 == 0)
    {
        printf ("Child 1\n");
        fflush(stdout); //ensure output is flushed immediately
    }
    else
    {
        pid2 = fork(); // create another child process

        if (pid2 < 0)
        {
            printf("Fork Failed to create second child.\n");
            exit(1);
        }
        else if (pid2 == 0)
        {
            printf ("Child 2\n");
            fflush(stdout); //ensure output is flushed immediately
        }
        else
        {
            wait(NULL); // wait for child to finish
            wait(NULL); // wait for child to finish
            printf ("Parent\n");
            fflush(stdout); //ensure output is flushed immediately
        }
    }
}
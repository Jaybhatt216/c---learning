#include <stdio.h>
#include <sys/types.h>

main()
{
    pid_t pid;
    int status;
    switch(pid = fork())
    {
        case -1:
            printf("fork failed");
            break;
        case 0:  
            printf("\nfirst child %d", getpid());
            fflush(stdout);
            break;
        default:    
            sleep(5); 
            printf("\ni'm the parent %d", getpid());
            printf("\nnew child");
            fflush(stdout);
            switch(pid = fork())
            {
                case -1:
                    printf("fork failed");
                    break;
                case 0:
                    printf("\nsecond child %d", getpid());
                    break;
               
                    pid = wait(&status);
                    printf("\nParent detects process %d was done", pid);
                    pid = wait(&status);
                    printf("\nParent detects process %d was done", pid);
                    printf("\nback to parent, my pid is %d", getpid());
            }
    }

     return 0;
}
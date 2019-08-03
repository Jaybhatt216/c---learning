#include <stdio.h>

main(){
    
    int pid;
    int fd;
    printf("about to run who into a file\n");
    if ( (pid = fork()) == -1) {
        
        perror("fork"); exit(1);
        
    }
    if (pid == 0) {
        close(1);
        fd = creat("CS648", 0644);
        execlp("who","who",NULL);
        perror("execlp");
        exit(1);
    }
    
    if(pid !=0){
        wait(NULL);
        printf("done running who. results in CS648 %s %d\n");
      
    }
    
}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int i =0;


 main()
{
    void f(int);
    int i;
    
    signal( SIGINT, f );
    for(i=0; i<5; i++ ) {
        printf("hello\n");
        sleep(1);
    }
}

void f(int signum)
{
    printf("ouch!\n");
    
   
    
    if (printf("ouch!\n")) {
         i++;
    }else{ 
    
    printf(("ouch!\n"));
    }
    printf(i);
    

}
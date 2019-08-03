1.	#include <stdio.h>
2.	#include <stdlib.h>
3.	#include <unistd.h>
4.	#include <signal.h>
5.	#include "smsh.h"
6.	
7.	#define DEL_PROMPT "> "
8.	
9.	int main() {
10.	    
11.	    char *cmdline, *prompt, **arglist;
12.	    int result;
13.	    void setup();
14.	    
15.	    prompt = DFL_PROMPT;
16.	    setup();
17.	    
18.	    While (( cmdline  = next_cmd(prompt,stdin)) = NULL ) {
19.	              If (arglist = splitline(cmdline)) != NULL ){
20.	                            Result = process(arglist);
21.	                             Freelist(arglist);
22.	
23.	        }
24.	        free(cmdline);
25.	    }
26.	    return 0;
27.	    
28.	    
29.	}
30.	
31.	void setup(){
32.	    signal(SIGINT, SIG_IGN);
33.	    signal(SIGQUIT, SIG_IGN);
34.	    
35.	}
36.	
37.	void fatal(char *s1,char *s2, int n){
38.	    
39.	fprintf(stderr, "ERROR: %s, %s\n", s1, s2);
40.	exit(n);

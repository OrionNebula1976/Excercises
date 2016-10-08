
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
pid_t pid;
int main(){
        int i, n, parent, m,P;
        scanf("%d", &n);
        parent=getpid();
        for (i=0; i<n; ++n){
            pid = fork();
            m=getppid();
            if (m==parent){
                P=getpid();
                printf("My PID is %d\n",P);
	        printf("End of child process\n");
            };
        };
        return 0;
} 

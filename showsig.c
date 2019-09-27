#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>


void sig_handler(int signo)
{
    char * str = strsignal(signo);
    printf("%2d -> SIG%s\n", signo, str);
}

int main(void)
{
    int sig;
    printf ("\n");
    for (sig = 1; sig < NSIG; sig++)
    {
        if (signal(sig, sig_handler) == SIG_ERR)
            printf("Can't catch %i -> %s\n", sig, strsignal(sig));
    }

    pid_t  pid;
    pid = getpid();
   
    printf ("\nGet a list of available signals with \"kill -l\"\n"); 
    printf ("Send signals to PID = %d\n", pid) ;
    printf ("Starting listener\n\n");

    while(1) 
        sleep(1);
    return 0;
}


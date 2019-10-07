#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
 

// http://web.theurbanpenguin.com/adding-color-to-your-output-from-c/

char* color = "\033[0m";
char* nocolor = "\33[0m";
pid_t pid;
 
void sig_handler(int signo)
{
    char * str = strsignal(signo);
    printf("%sPID: %i   %2d -> SIG%s%s\n", color, pid, signo, str, nocolor);
};
 

char *setColor (char* color_str)
{
    int i = 0;
    while(color_str[i]) {
       color_str[i] = tolower(color_str[i]);
       i++;
    }
    if (strcmp(color_str, "red") == 0) return ("\33[0;31m");
    if (strcmp(color_str, "green") == 0) return ("\33[0;32m");
    if (strcmp(color_str, "yellow") == 0) return ("\33[0;33m");
    if (strcmp(color_str, "blue") == 0) return ("\33[0;34m");
    if (strcmp(color_str, "magenta") == 0) return ("\33[0;35m");
    if (strcmp(color_str, "cyan") == 0) return ("\33[0;36m");
    printf ("Available Colors for Output: red, green yello, blue, magenta, cyan\n\n");
    return ("\033[0m");
};

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        color = setColor (argv[1]);
    }
    int sig;
    pid = getpid();
    for (sig = 1; sig < NSIG; sig++)
    {
        if (signal(sig, sig_handler) == SIG_ERR)
            printf("%sPID: %i   Can't catch %i -> %s%s\n", color, pid, sig, strsignal(sig), nocolor);
    }

    //printf ("%sPID: %i   Get a list of available signals with \"kill -l\"%s\n", color, pid, nocolor);
    printf ("%sPID: %i   Send signals to PID = %d%s\n", color, pid, pid, nocolor) ;
    printf ("%sPID: %i   Starting listener%s\n", color, pid, nocolor);

    while(1)
        sleep(1);
    return 0;

}

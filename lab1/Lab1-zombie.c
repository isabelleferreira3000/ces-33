#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#define TRUE 1

int n = 0; int pid;
char *argv[];char temp[256];
int argc;

void type_prompt()
{	
   printf("\n[shell-PID=%i]$ ", getpid());
}

void read_command(char *argv[])
{	
   n = 0;
   gets(temp);
   argv[n++] = strtok (temp," ");
   while (argv[n-1] != NULL)
   argv[n++] = strtok (NULL, " ");
}

int main()
{
   int status;
   argv[0] = NULL;
   while (TRUE) /* repeat forever */ {
      type_prompt(); /* display prompt on screen */
      read_command(argv); /* read input from terminal */
      if ((pid = fork()) != 0) /* fork off child process */ {
         printf("Esperando o filho pid=%i para sempre....\n", pid);
         for (; ; );
      } 
      else {
         printf("sou o filho que vai morrer\n");
         break;
      }
   }
   return 0;
}

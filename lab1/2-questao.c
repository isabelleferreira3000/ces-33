#include  <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include  <unistd.h>
// To use time library of C 
#include <time.h> 
  
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 

int main() {    
    pid_t pid, pid1, pid2;
    pid = fork();
    
    if (pid < 0) { /*erro */
        printf("Fork 1 failed\n");
        return 1;
    }
    
    if (pid == 0) { /* processo filho */
        pid2 = fork();

        if (pid2 < 0) { /*erro */
            printf("Fork 2 failed\n");
            return 1;
        }

        if (pid2 == 0) { /* processo neto */
            pid1=getpid();
            printf("Neto 1 foi criado\n");

            int i;
            for(i = 300; i <= 350; i++) {
                printf("%d => Neto pid: %d; Pai do neto pid: %d\n", i, getpid(), getppid());
                delay(2000);
            }
            printf("Neto 1 vai morrer\n");

        } else { /* processo filho */
            pid1=getpid();
            
            wait(NULL);
            printf("Filho 1 foi criado\n");

            int i;
            for(i = 100; i <= 200; i++) {
                printf("%d => Filho pid: %d; Pai do filho pid: %d\n", i, getpid(), getppid());
                delay(1000);
            }
            printf("Filho 1 vai morrer\n");
        }


    } else { /*processo pai */
        pid1=getpid();

        wait(NULL);
        int i;
        for(i = 1; i <= 50; i++) {
            printf("%d => Pai pid: %d; Pai do pai pid: %d\n", i, getpid(), getppid());
            delay(2000);
        }
        printf("Processo pai vai morrer\n");  
    }
    return 0;
}
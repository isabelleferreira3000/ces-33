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
    pid_t pid, pid1;
    pid = fork();
    
    if (pid < 0) { /*erro */
        printf("Fork 1 failed\n");
        return 1;
    }
    
    if (pid == 0) { /* processo filho */
        pid1 = fork();

        if (pid1 < 0) { /*erro */
            printf("Fork 2 failed\n");
            return 1;
        }

        if (pid1 == 0) { /* processo neto */
            printf("Neto 1 foi criado\n");

            int i;
            for(i = 300; i <= 350; i++) {
                printf("neto: %d\n", i);
                delay(2000);
            }
            printf("Neto 1 vai morrer\n");

        } else { /* processo filho */
            wait(NULL);

            printf("Filho 1 foi criado\n");

            int i;
            for(i = 100; i <= 200; i++) {
                printf("filho: %d\n", i);
                delay(1000);
            }
            printf("Filho 1 vai morrer\n");
        }

    } else { /*processo pai */
        wait(NULL);

        int i;
        for(i = 1; i <= 50; i++) {
            printf("pai: %d\n", i);
            delay(2000);
        }
        printf("Processo pai vai morrer\n");
    }
    return 0;
}
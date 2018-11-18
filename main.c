#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {

  srand(time(NULL));
  int num1 = rand() % 16 + 5;
  int num2 = rand() % 16 + 5;
  printf("Initial Message of the Parent Process! pid: %d\n", getpid());

  if(fork()) { //parent
    if(fork()) { //parent
      int status; 
      int cpid = wait(&status); 
      printf("Child with the pid of %d was asleep for %d seconds.\n", cpid, WEXITSTATUS(status));
      printf("Parent Process is Done!\n"); 
      return 0;
    }

    else { //child2
      printf("Child 2's pid: %d\n", getpid());
      sleep(num2); 
      printf("Child 2 is done sleeping for %d seconds!\n", num2); 
      return num2;
    }
  }

  else { //child1
    printf("Child 1's pid: %d\n", getpid());
    sleep(num1); 
    printf("Child 1 is done sleeping for %d seconds!\n", num1); 
    return num1;
  }
}
  

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  prinf("Initial Message of the Parent Process!\n");
  int cpid1 = fork();

  if (fork() == 0)
    printf("Child's pid: %d", getpid())


      return 0;
  
      }

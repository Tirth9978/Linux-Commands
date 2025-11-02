// Design a Solution
/*

Design a pipe-based system where:
 -> One parent process generates random numbers
 -> Three child processes filter these numbers (even, odd, prime)
 -> The parent collects and displays categorized results
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
     pid_t pid1,pid2 ;
     int fd1[2] , fd2[2] , fd3[2];
     pipe(fd);

     pid1 = fork();

     if (pid1 == 0){

          return  1;
     }
     
     pid2 = fork();

     if (pid2 == 0){

          return 2;
     }

     close(fd[1])
     

     return 0;
}
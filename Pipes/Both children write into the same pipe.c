#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
     int fd[2];
     pipe(fd);

     pid_t pid1 = fork();

     if (pid1 == 0){
          close(fd[0]);
          char m[] = "I am Child1\n";
          write(fd[1] , m ,sizeof(m) );
          close(fd[1]);
          return 1;
     }

     pid_t pid2 = fork();

     if (pid2 == 0){
          close(fd[0]);
          char m[] = "I am Child2\n";
          write(fd[1] , m ,sizeof(m) );
          close(fd[1]);
          return 1;
     }

     char buff[1000] ;
     close(fd[1]);
     read(fd[0] , buff , sizeof(buff));
     close(fd[0]);
     printf("%s" ,buff);
     return 0;
}
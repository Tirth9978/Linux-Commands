#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
     pid_t pid ; 
     int fd[2];
     pipe(fd);
     pid = fork();

     if (pid < 0){
          printf("Fail to fork () :(");
          return 1;
     }

     if (pid == 0){
          close(fd[1]);
          int arr[5] ;
          read(fd[0] , arr , sizeof(arr));
          for (int i=0;i<5;i++){
               printf("%d " , arr[i]);
          }
          printf("\n");

          close(fd[0]);
     }

     else {
          close(fd[0]);
          int arr[] = {1,2,3,4,5};

          write(fd[1] , arr , sizeof(arr));
          close(fd[1]);
     }
     return 0;
}
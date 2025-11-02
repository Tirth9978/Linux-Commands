#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * multiplyBy2(void * arg){
     int num = (*(int*)arg) ;
     int * result =(int *) malloc(sizeof(int));
     printf("I am calculate the Result :))\n");
     sleep(2);
     printf("Done\n");

     *result = num * 2;
     pthread_exit(result);
}

int main(){
     pthread_t id ;
     int num;
     int * result ;
     printf("Enter the Number : ");
     scanf("%d" , & num);
     
     pthread_create(&id, NULL, multiplyBy2, &num);

     pthread_join(id , (void**)&result);
     printf("Ans : %d\n",result);
     return 0;
}
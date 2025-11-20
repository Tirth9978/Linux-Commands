#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int main(void)
{
	//void (*oldHandler) () /* To hold old handler value */
	void (*oldHandler) ();
	printf("I can be Control-C ed\n");
	sleep(3);
	void (*oldHandler)()= signal(SIGINT, SIG_IGN); /* Ignore Control-C */
	printf("I am protected from Control-C now\n");
	sleep(3);
	signal(SIGINT, oldHandler); /* Restore old handler */
	printf("I can be Control-C ed again\n");
	sleep(3);
	printf("Bye! \n");
}

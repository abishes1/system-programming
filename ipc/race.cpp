//Program to demonstrate a race condition
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
int balance = 0;
void *computebal( void *arg ) {
	int b,c;
	b = balance;
	for(int i=0; i < 5000; i++) {
		c = 5000 * 123478;
	}
	b += 10;
	balance = b;
	return NULL;
}

int main(){
	int i;
	pthread_t thread_id[200];
	cout << "Balance before thread: " << balance << endl;
	for(i=0;i < 200;i++) {
		pthread_create(&thread_id[i],NULL,computebal,NULL);
	}

	for(i=0;i < 200;i++) {
		pthread_join(thread_id[i],NULL);
	}
	cout << "Balance after thread: " << balance << endl;
	exit(EXIT_SUCCESS);
}


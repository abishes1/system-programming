//Program to send message to a message queue
#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 256
using namespace std;
struct mesg_buffer {
	long mesg_type;
	char mesg_text[MAX];
}mesg;

int main(){
	key_t key;
	int msgid,err;

	key = ftok("keyfile",65);
	msgid = msgget(key, 0666 | IPC_CREAT);
	if(msgid == -1){
		perror("Error Creating message queue");
		exit(EXIT_FAILURE);
	}
	err = msgrcv(msgid,&mesg,sizeof(mesg),1,0);
	if(err == -1){
		perror("Error receiving message queue");
		exit(EXIT_FAILURE);
	}

	cout << "Data got from queue: " << mesg.mesg_text << endl;
	err = msgctl(msgid,IPC_RMID,NULL);
	if(err == -1){
		perror("Error destroying message queue");
		exit(EXIT_FAILURE);
	}

	return 0;
}

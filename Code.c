// 2.write a program that uses msgctl() and prints number of messages,number of bytes in
// message queue and also get Maximum number of bytes in queue for already existing
// message queue and also remove message queue at the end.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>
#include<string.h>

typedef struct{
    long msgtype;
    char buffer[100];
}msg;

int main(){
    msg m1, m2;

    m1.msgtype = 10;
    for(int i=0; i<100; i++){
        m1.buffer[i] = 'a';
    }

    int message_queue;
    struct msqid_ds buf;

    message_queue = msgget(32, IPC_CREAT|0664);

    msgsnd(message_queue, &m1, sizeof(msg), 0);
    msgsnd(message_queue, &m2, sizeof(msg), 0);

    printf("ID of created nessage queue = %d\n", message_queue);
    msgctl(message_queue, IPC_STAT, &buf);

    printf("details of the message queue...\n");
    printf("number of messages in message queue = %hi\n", buf.msg_qnum);
    printf("number of bytes in message queue = %u\n", buf.msg_cbytes);
    printf("maximum number of bytes in a message queue = %hi\n", buf.msg_qbytes); //msg_qbytes
    
    printf("message queue with ID = %d removed\n", message_queue);
    msgctl(message_queue, IPC_RMID, NULL);

    return 0;
}
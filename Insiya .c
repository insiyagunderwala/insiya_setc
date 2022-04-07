// 1.write a program that creates a shared memory region and displays shared memory id
// and also print address at which shared area in this process starts from.

#include<stdio.h>
#include<sys/shm.h>

#define SIZE 0x1000

int main(){
    key_t key;
    int *allocated_mem_addr;

    int shared_id =  shmget(key, SIZE, IPC_CREAT|0600);
    if(shared_id<0){
        printf("Sorry! space can't being shared\n");
    }
    printf("id of allocated shared region: %d\n", shared_id);
    allocated_mem_addr = shmat(shared_id, NULL, 0);
    printf("starting pointer of the allocated region: %p\n", allocated_mem_addr);

    return 0;
}
// 3.Write a program parent process writing to pipe and child reading toggled data from pipe,
// and also analyse the data flow order from write end to read end.

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int fds[2];

char* toggle(char str[]){
    char* ret_str=str;
    for(int i=0; i<strlen(str); i++){
        if(ret_str[i]>='A' && ret_str[i]<='Z')
        ret_str[i]=ret_str[i]+32;
        else if(ret_str[i]>='a' && ret_str[i]<='z')
        ret_str[i]=ret_str[i]-32;
    }
    return ret_str;
}

int main(){
    int res;
    pid_t p;
    res = pipe(fds);
    // fds[0] for reading and fds[1] for writing

    if(res==-1){
        perror("pipe");
        exit(1);
    }

    p = fork();

    if(p==0){
        char buf_to_read[100];
        int n;
        // close(fds[1]);
        n = read(fds[0], buf_to_read, 100); //will return the length of the buffer readed
        for(int i=0; i<n; i++){
            printf("%c", buf_to_read[i]);
        }
    } else{
        char buf1[20] = "this is buffeR 1";
        char buf2[20] = "this is buffeR 2";
        // close(fds[0]);
        char *b1 = toggle(buf1);
        char *b2 = toggle(buf2);
        write(fds[1], b1, 20);
        write(fds[1], b2, 20);
    }

    return 0;
}


/* data flow order:
When the fork() is called, parent process will be executed first(inside else block). Parent process will performs the toggle operation by calling the toggle function and writes data to the pipe. Once parent process executes, child process will be executed and written data will be stored to the buffer called buf_to_read. */

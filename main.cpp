#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 256

typedef int filedescriptor;

using namespace std;

int main(int argc,char* argv[])
{
    if (argc!=2){
        return -1;
    }

    filedescriptor fileDescriptor;
    if((fileDescriptor=open(argv[1],O_WRONLY))==-1){
        return -2;
    }


    char cstrBuffer[BUFFER_SIZE];

    while(fgets(cstrBuffer,BUFFER_SIZE,stdin)!=nullptr){

        if(write(fileDescriptor,cstrBuffer,strlen(cstrBuffer))==-1){
            return -3;
        }

    }

    close(fileDescriptor);
    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main(){
    system("gcc hello.c -o hello");
    system("./hello >> output");
    return 1;
}

#include <sys/file.h>
#include <errno.h>

int main(void)
{
    int nfhandle = open("lololo.ll", O_RDONLY, 0700);
    perror("ERROR");
    printf("ERR_NO: %d",errno);
    return 0;
}

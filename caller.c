#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>

int main() {
   printf("hello STDOUT\n");
   fprintf(stderr, "ERROR: this is an error");
}
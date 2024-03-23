 //Name the program file as “write.c” and save Ctrl + X in nano editor
#include<unistd.h>
int main()
{
write(1,"hello\n",6);    
//1 is the file descriptor, "hello\n" is the data, 6 is the count  of characters in data //
}

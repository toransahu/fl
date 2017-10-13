/*
The declaration of execvpe is only included if _GNU_SOURCE is
defined before including unistd.h as it is a GNU extension.
*/
#define _GNU_SOURCE
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

DIR *opendir(const char *name);

struct dirent *readdir(DIR *dirp);

void main()
{
  FILE *in;
  extern FILE *popen();
  char buff[512];
  char ch;
  char pid[20];
  pid_t pid;

  in = popen("ls /proc | grep '[0-9]'", "r");
  fgets(buff, 512, in);

  //printf("%s\n",buff );

  ch = fgetc(in);
  /*
  sprintf(pid ,"%d", ch);
  char *const parmList[6] = {"ps","-p",pid,"-o","rss",NULL};
  printf("%s",pid);
  execvp("/bin/ps", parmList);
  */

  while (ch != EOF)
  {
      printf ("%c", ch);
      sprintf(pid ,"%d", ch);
      char *const parmList[6] = {"ps","-p",pid,"-o","rss",NULL};
      execvp("/bin/ps", parmList);
      ch = fgetc(in);
  }


//  fclose(in);

  if (pclose(in) != 0)
        fprintf(stderr," Error: Failed to close command stream \n");



}

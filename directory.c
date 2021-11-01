#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <strings.h>

int main(){
  DIR * currentDir = opendir("./");
  struct dirent * currentEntry = readdir(currentDir);
  while (currentEntry != NULL){
    printf("This directory is %s\n",currentEntry->d_name);
    currentEntry = readdir(currentDir);
  }
  return 0;
}

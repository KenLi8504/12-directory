#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <strings.h>
#include <sys/stat.h>

int main(){
  DIR * currentDir = opendir("./");
  struct stat temp;
  unsigned long counter = 0;

  struct dirent * currentEntry = readdir(currentDir);

  while (currentEntry != NULL){
    if (currentEntry -> d_type != 4){
      stat(currentEntry->d_name,&temp);
      counter = counter + temp.st_size;
    }
    currentEntry = readdir(currentDir);
  }

  printf("The total size of all non-directories in this directory is %lu bytes\n",counter);

  rewinddir(currentDir);
  currentEntry = readdir(currentDir);

  printf("The following below are directories\n");
  while (currentEntry != NULL){
    if (currentEntry -> d_type == 4){
      printf("\t%s\n",currentEntry->d_name);
    }
    currentEntry = readdir(currentDir);
  }

  rewinddir(currentDir);
  currentEntry = readdir(currentDir);

  printf("The following below are not directories\n");
  while (currentEntry != NULL){
    if (currentEntry -> d_type != 4){
      printf("\t%s\n",currentEntry->d_name);
    }
    currentEntry = readdir(currentDir);
  }
  return 0;
}

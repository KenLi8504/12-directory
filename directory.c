#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <strings.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv){
  char directory[1000];
  if (argc == 2){
    strcpy(directory, argv[1]);
    //printf("%s\n",directory);
  }
  else if (argc > 2){
    printf("Too many arguments my guy, put only 1.\n");
  }
  else{
    char temp[10000];
    printf("Please input a directory:");
    fgets(temp,10000,stdin);
    strncpy(directory,temp,strlen(temp)-1);
    // printf("The directory is %s\n",directory);
    // printf("This directory is %lu bytes long \n",strlen(directory));
  }

  DIR * currentDir;
  if (opendir(directory) == 0){
    printf("Error %d: %s \n", errno, strerror(errno));
    return 0;
  }
  else{
    currentDir = opendir(directory);
  }
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

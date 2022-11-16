#define _OPEN_THREADS
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void *thread(void *arg) 
{
  char *ret;
  printf("thread() entered with argument '%s'\n", (char *)arg);
  ret = (char*) malloc(20);
  strcpy(ret, "This is a test");
  pthread_exit(ret);
}

int main() 
{
  pthread_t thread;
  void *ret;

  pthread_create(&thread, NULL, thread, "thread 1");
  pthread_join(thread, &ret);
  printf("thread exited with '%s'\n", (char *)ret);
}

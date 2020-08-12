#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#define LOG_TAG	"LOGC"
#include "log.h"

#include <pthread.h>
#include <unistd.h>

#define MAX_THREAD_NUM	10

void *logging_thread(void *arg)
{
	int index = *((int*) arg);
	fprintf(stderr, "Thread %d start\n", index);

	//while (1) {
	for (int i = 0; i < 10000; i++) {
		LOGE("%d I send message %d", index, i);
		usleep(1000);
	}
	fprintf(stderr, "Thread %d end\n", index);

	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t thread_id[MAX_THREAD_NUM];
	int ids[MAX_THREAD_NUM];
	int i;

	for (i = 0; i < MAX_THREAD_NUM; i++) {
		ids[i] = i;
		pthread_create(&thread_id[i], NULL, logging_thread, &ids[i]);
	}

	for (i = 0; i < MAX_THREAD_NUM; i++) {
		pthread_join(thread_id[i], NULL);
	}
	uninit_log();

	return 0;
}
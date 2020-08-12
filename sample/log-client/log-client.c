#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>


#define LOG_TAG	"LOGC"
#include "log.h"

#include <unistd.h>

#ifndef WIN32
#include <execinfo.h>
void sig_seg(int sig, struct sigcontext ctx) {
	size_t size;
	void *trace[10];
	char **traceStr;

	// get void*'s for all entries on the stack
	size = backtrace(trace, 10);

	// print out all the frames to stderr
	traceStr = backtrace_symbols(trace, size);
	
	for (int i = 0; i < 10; i++) {
		LOGE("%s", traceStr[i]);
	}

	exit(1);
}
#endif

int main()
{
#ifndef WIN32
	struct sigaction sa;
	sa.sa_handler = (void *)sig_seg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGSEGV, &sa, NULL);
#endif
	
	for (int i = 0; i < 100; i++) {
		LOGE("Hello world %s", "error");
		LOGD("Hello world %s", "debug");
		LOGI("Hello world %s", "info");
		sleep(1);
	}

	uninit_log();

	return 0;
}
#ifndef __LOG_H__
#define __LOG_H__

#ifdef WIN32
	#ifndef PATH_MAX
	#define PATH_MAX 260
	#endif
	#define FILE_SEPARATOR		'\\'
	#define FILE_NEWLINE		"\r\n"
#else
	#include <linux/limits.h>
	#define FILE_SEPARATOR		'/'
	#define FILE_NEWLINE		"\n"
#endif

#define DEF_LOGD_PORT		9278
#define LOGD_MAX_BUF_LEN	2048
#define LOG_MAGIC_NUMBER	0x243E2537

#ifndef LOG_TAG
	#define LOG_TAG	""
#endif


#define LOGE(fmt, ...) do { send2logd(LOG_TAG, LOG_ERROR, fmt, ##__VA_ARGS__); } while (0)
#define LOGI(fmt, ...) do { send2logd(LOG_TAG, LOG_NORMAL, fmt, ##__VA_ARGS__); } while (0)
#define LOGD(fmt, ...) do { send2logd(LOG_TAG, LOG_DEBUG, fmt, ##__VA_ARGS__); } while (0)

typedef enum LogLevel {
	LOG_FATAL,
	LOG_ALARM,
	LOG_ERROR,
	LOG_WARNING,
	LOG_NORMAL,
	LOG_DEBUG
} LogLevel;

typedef void* (*file_monitor_fn)(void* arg);
typedef struct {
	char file[PATH_MAX];
	file_monitor_fn fun;
	int running;
} file_monitor_st;

#ifdef __cplusplus
extern "C" {
#endif

void send2logd(const char *tag, int level, const char *fmt, ...);
int uninit_log();

#ifdef __cplusplus
}
#endif

#endif
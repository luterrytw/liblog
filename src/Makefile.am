ACLOCAL_AMFLAGS = -I m4
include_HEADERS = ../inc/log.h
AM_CFLAGS = -I../inc -Wall -fPIC -g
lib_LTLIBRARIES = liblog.la
liblog_la_SOURCES = log.c inotify_file_monitor.c udp-socket.c
liblog_la_LDFLAGS = -Wl,-rpath,. -ldl -lpthread -version-info 1:0:0

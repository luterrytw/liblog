#!/bin/bash
gcc -Wall log-client/log-client.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o ../release/log-client
gcc -Wall log-thread/log-thread.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o ../release/log-thread

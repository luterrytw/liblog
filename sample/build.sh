#!/bin/bash
gcc -Wall log-client/log-client.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o log-client/log-client
gcc -Wall log-thread/log-thread.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o log-thread/log-thread
cp log-client/log-client ../../out/usr/local/bin/
cp log-thread/log-thread ../../out/usr/local/bin/

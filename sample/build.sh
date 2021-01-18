#!/bin/bash
gcc -Wall -g log-client/log-client.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o log-client/log-client
gcc -Wall -g log-thread/log-thread.c -I../inc -L../src/.libs/ -llog -lpthread -Wl,-rpath,. -o log-thread/log-thread
cp log-client/log-client ../../out/lib/
cp log-thread/log-thread ../../out/lib/

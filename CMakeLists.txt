cmake_minimum_required(VERSION 3.10)
project(untitled3 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled3 main.c read.c write.c system.c filereadwrite.c lseek.c thread.c thread2.c fib&fact.c fork.c altmessage.c orphane.c zombie.c zombie.h dirent.c dirent2.c exec.c race.c deadlock.c)

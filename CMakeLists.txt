CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
PROJECT (LCKERNEL)

# SOURCE FILES
set(srcs
Rope.c
)

# HEADER FILES
set(hdrs
Rope.h
)

add_executable(Rope ${srcs} ${hdrs})


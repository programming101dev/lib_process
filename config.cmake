# Project metadata
set(PROJECT_NAME "p101_process")
set(PROJECT_VERSION "0.0.1")
set(PROJECT_DESCRIPTION "Process lifecycle, execution, signals, scheduling, and limits")
set(PROJECT_LANGUAGE "C")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(STANDARD_FLAGS
        -D_POSIX_C_SOURCE=200809L
        -D_XOPEN_SOURCE=700
        -Werror
)
set(DARWIN_STANDARD_FLAGS -D_DARWIN_C_SOURCE)
set(LINUX_STANDARD_FLAGS -D_GNU_SOURCE)
set(BSD_STANDARD_FLAGS -D_BSD_SOURCE -D__BSD_VISIBLE)

set(LIBRARY_TARGETS p101_process)
set(p101_process_SOURCES
        src/posix/sched.c
        src/posix/setjmp.c
        src/posix/signal.c
        src/posix/stdio.c
        src/posix/stdlib.c
        src/posix/sys/times.c
        src/posix/sys/wait.c
        src/posix/unistd.c
        src/posix_optional/sched.c
        src/posix_optional/spawn.c
        src/posix_xsi/signal.c
        src/posix_xsi/stdlib.c
        src/posix_xsi/sys/resource.c
        src/posix_xsi/unistd.c
)
set(p101_process_HEADERS
        include/p101_process/process.h
)
set(p101_process_LINK_LIBRARIES
        p101_error
        p101_env
        p101_c
)


#ifndef LIBP101_PROCESS_P101_UNISTD_H
#define LIBP101_PROCESS_P101_UNISTD_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LIBP101_PROCESS_SHARED_DECLARATIONS
    #define LIBP101_PROCESS_SHARED_DECLARATIONS
    #include <p101_env/env.h>
    #include <p101_error/attributes.h>
    #include <sched.h>
    #include <setjmp.h>
    #include <signal.h>
    #include <spawn.h>
    #include <stdio.h>
    #include <sys/resource.h>
    #include <sys/signal.h>
    #include <sys/times.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <unistd.h>
#endif    // LIBP101_PROCESS_SHARED_DECLARATIONS

#ifdef __cplusplus
extern "C"
{
#endif

    unsigned p101_alarm(const struct p101_env *env, unsigned seconds);
    int      p101_execv(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[]);
    int      p101_execve(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[], char *const envp[]);
    int      p101_execvp(const struct p101_env *env, struct p101_error *err, const char *file, char *const argv[]);
    pid_t    p101_fork(const struct p101_env *env, struct p101_error *err);
    pid_t    p101_getpgid(const struct p101_env *env, struct p101_error *err, pid_t pid);
    pid_t    p101_getpgrp(const struct p101_env *env);
    pid_t    p101_getpid(const struct p101_env *env);
    pid_t    p101_getppid(const struct p101_env *env);
    pid_t    p101_getsid(const struct p101_env *env, struct p101_error *err, pid_t pid);
    int      p101_nice(const struct p101_env *env, struct p101_error *err, int value);
    int      p101_pause(const struct p101_env *env, struct p101_error *err);
    int      p101_setpgid(const struct p101_env *env, struct p101_error *err, pid_t pid, pid_t pgid);
    pid_t    p101_setsid(const struct p101_env *env, struct p101_error *err);
    unsigned p101_sleep(const struct p101_env *env, unsigned seconds);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_P101_UNISTD_H

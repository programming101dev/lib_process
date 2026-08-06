#ifndef LIBP101_PROCESS_P101_SIGNAL_H
#define LIBP101_PROCESS_P101_SIGNAL_H

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

    int p101_kill(const struct p101_env *env, struct p101_error *err, pid_t pid, int sig);
    int p101_killpg(const struct p101_env *env, struct p101_error *err, pid_t pgrp, int sig);
    int p101_sigaction(const struct p101_env *env, struct p101_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
    int p101_sigaddset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo);
    int p101_sigaltstack(const struct p101_env *env, struct p101_error *err, const stack_t *restrict ss, stack_t *restrict oss);
    int p101_sigdelset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo);
    int p101_sigemptyset(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int p101_sigfillset(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int p101_sigismember(const struct p101_env *env, struct p101_error *err, const sigset_t *set, int signo);
    int p101_sigpending(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int p101_sigprocmask(const struct p101_env *env, struct p101_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset);
    int p101_sigsuspend(const struct p101_env *env, struct p101_error *err, const sigset_t *sigmask);
    int p101_sigwait(const struct p101_env *env, struct p101_error *err, const sigset_t *restrict set, int *restrict sig);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_P101_SIGNAL_H

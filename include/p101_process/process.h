#ifndef LIBP101_PROCESS_PROCESS_H
#define LIBP101_PROCESS_PROCESS_H

/*
 * Copyright 2026 D'Arcy Smith.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 */

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

#ifdef __cplusplus
extern "C"
{
#endif

    unsigned                p101_alarm(const struct p101_env *env, unsigned seconds);
    int                     p101_execv(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[]);
    int                     p101_execve(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[], char *const envp[]);
    int                     p101_execvp(const struct p101_env *env, struct p101_error *err, const char *file, char *const argv[]);
    pid_t                   p101_fork(const struct p101_env *env, struct p101_error *err);
    pid_t                   p101_getpgid(const struct p101_env *env, struct p101_error *err, pid_t pid);
    pid_t                   p101_getpgrp(const struct p101_env *env);
    pid_t                   p101_getpid(const struct p101_env *env);
    pid_t                   p101_getppid(const struct p101_env *env);
    int                     p101_getpriority(const struct p101_env *env, struct p101_error *err, int which, id_t who);
    int                     p101_getrlimit(const struct p101_env *env, struct p101_error *err, int resource, struct rlimit *rlp);
    int                     p101_getrusage(const struct p101_env *env, struct p101_error *err, int who, struct rusage *r_usage);
    pid_t                   p101_getsid(const struct p101_env *env, struct p101_error *err, pid_t pid);
    int                     p101_kill(const struct p101_env *env, struct p101_error *err, pid_t pid, int sig);
    int                     p101_killpg(const struct p101_env *env, struct p101_error *err, pid_t pgrp, int sig);
    int                     p101_nice(const struct p101_env *env, struct p101_error *err, int value);
    int                     p101_pause(const struct p101_env *env, struct p101_error *err);
    int                     p101_pclose(const struct p101_env *env, struct p101_error *err, FILE *stream);
    FILE                   *p101_popen(const struct p101_env *env, struct p101_error *err, const char *command, const char *mode) P101_ATTR_WARN_UNUSED_RESULT;
    P101_ATTR_NORETURN void p101_posix_exit_immediately(const struct p101_env *env, int status);
    int   p101_posix_spawn(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict path, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                           char *const envp[restrict]);
    int   p101_posix_spawn_file_actions_addclose(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes);
    int   p101_posix_spawn_file_actions_adddup2(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes, int newfildes);
    int   p101_posix_spawn_file_actions_addopen(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *restrict file_actions, int fildes, const char *restrict path, int oflag, mode_t mode);
    int   p101_posix_spawn_file_actions_destroy(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions);
    int   p101_posix_spawn_file_actions_init(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions);
    int   p101_posix_spawnattr_destroy(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr);
    int   p101_posix_spawnattr_getflags(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, short *restrict flags);
    int   p101_posix_spawnattr_getpgroup(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, pid_t *restrict pgroup);
    int   p101_posix_spawnattr_getsigdefault(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigdefault);
    int   p101_posix_spawnattr_getsigmask(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigmask);
    int   p101_posix_spawnattr_init(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr);
    int   p101_posix_spawnattr_setflags(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, short flags);
    int   p101_posix_spawnattr_setpgroup(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, pid_t pgroup);
    int   p101_posix_spawnattr_setsigdefault(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigdefault);
    int   p101_posix_spawnattr_setsigmask(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigmask);
    int   p101_posix_spawnp(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict file, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                            char *const envp[restrict]);
    int   p101_putenv(const struct p101_env *env, struct p101_error *err, char *string);
    int   p101_sched_get_priority_max(const struct p101_env *env, struct p101_error *err, int policy);
    int   p101_sched_get_priority_min(const struct p101_env *env, struct p101_error *err, int policy);
    int   p101_sched_yield(const struct p101_env *env, struct p101_error *err);
    int   p101_setenv(const struct p101_env *env, struct p101_error *err, const char *envname, const char *envval, int overwrite);
    int   p101_setpgid(const struct p101_env *env, struct p101_error *err, pid_t pid, pid_t pgid);
    int   p101_setpriority(const struct p101_env *env, struct p101_error *err, int which, id_t who, int value);
    int   p101_setrlimit(const struct p101_env *env, struct p101_error *err, int resource, const struct rlimit *rlp);
    pid_t p101_setsid(const struct p101_env *env, struct p101_error *err);
    int   p101_sigaction(const struct p101_env *env, struct p101_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);
    int   p101_sigaddset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo);
    int   p101_sigaltstack(const struct p101_env *env, struct p101_error *err, const stack_t *restrict ss, stack_t *restrict oss);
    int   p101_sigdelset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo);
    int   p101_sigemptyset(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int   p101_sigfillset(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int   p101_sigismember(const struct p101_env *env, struct p101_error *err, const sigset_t *set, int signo);
    P101_ATTR_NORETURN void p101_siglongjmp(const struct p101_env *env, sigjmp_buf jmpbuf, int val);
    int                     p101_sigpending(const struct p101_env *env, struct p101_error *err, sigset_t *set);
    int                     p101_sigprocmask(const struct p101_env *env, struct p101_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset);
    int                     p101_sigsuspend(const struct p101_env *env, struct p101_error *err, const sigset_t *sigmask);
    int                     p101_sigwait(const struct p101_env *env, struct p101_error *err, const sigset_t *restrict set, int *restrict sig);
    unsigned                p101_sleep(const struct p101_env *env, unsigned seconds);
    clock_t                 p101_times(const struct p101_env *env, struct p101_error *err, struct tms *buffer);
    int                     p101_unsetenv(const struct p101_env *env, struct p101_error *err, const char *name);
    pid_t                   p101_wait(const struct p101_env *env, struct p101_error *err, int *stat_loc);
    int                     p101_waitid(const struct p101_env *env, struct p101_error *err, idtype_t idtype, id_t id, siginfo_t *infop, int options);
    pid_t                   p101_waitpid(const struct p101_env *env, struct p101_error *err, pid_t pid, int *stat_loc, int options);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_PROCESS_H

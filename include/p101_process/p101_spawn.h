#ifndef LIBP101_PROCESS_P101_SPAWN_H
#define LIBP101_PROCESS_P101_SPAWN_H

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

    int p101_posix_spawn(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict path, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                         char *const envp[restrict]);
    int p101_posix_spawn_file_actions_addclose(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes);
    int p101_posix_spawn_file_actions_adddup2(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes, int newfildes);
    int p101_posix_spawn_file_actions_addopen(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *restrict file_actions, int fildes, const char *restrict path, int oflag, mode_t mode);
    int p101_posix_spawn_file_actions_destroy(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions);
    int p101_posix_spawn_file_actions_init(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions);
    int p101_posix_spawnattr_destroy(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr);
    int p101_posix_spawnattr_getflags(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, short *restrict flags);
    int p101_posix_spawnattr_getpgroup(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, pid_t *restrict pgroup);
    int p101_posix_spawnattr_getsigdefault(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigdefault);
    int p101_posix_spawnattr_getsigmask(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigmask);
    int p101_posix_spawnattr_init(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr);
    int p101_posix_spawnattr_setflags(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, short flags);
    int p101_posix_spawnattr_setpgroup(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, pid_t pgroup);
    int p101_posix_spawnattr_setsigdefault(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigdefault);
    int p101_posix_spawnattr_setsigmask(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigmask);
    int p101_posix_spawnp(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict file, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                          char *const envp[restrict]);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_P101_SPAWN_H

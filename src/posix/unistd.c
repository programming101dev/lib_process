/*
 * Copyright 2021-2024 D'Arcy Smith.
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

#include "p101_process/process.h"
#include <p101_env/wrapper.h>

unsigned p101_alarm(const struct p101_env *env, unsigned seconds)
{
    unsigned ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = alarm(seconds);

    P101_TRACE_EXIT(env);
    return ret_val;
}

void p101_posix_exit_immediately(const struct p101_env *env, int status)
{
    P101_TRACE(env);
    errno = 0;
    P101_TRACE_EXIT(env);
    p101_env_complete_event_streams(env);
    _exit(status);
}

int p101_execv(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    P101_TRACK_EXEC(env, path);
    errno   = 0;
    ret_val = execv(path, argv);

    if(ret_val == -1)
    {
        int actual_error;

        actual_error = errno;
        P101_TRACK_EXEC_FAILURE(env, path);
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_execve(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[], char *const envp[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    P101_TRACK_EXEC(env, path);
    errno   = 0;
    ret_val = execve(path, argv, envp);

    if(ret_val == -1)
    {
        int actual_error;

        actual_error = errno;
        P101_TRACK_EXEC_FAILURE(env, path);
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_execvp(const struct p101_env *env, struct p101_error *err, const char *file, char *const argv[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    P101_TRACK_EXEC(env, file);
    errno   = 0;
    ret_val = execvp(file, argv);

    if(ret_val == -1)
    {
        int actual_error;

        actual_error = errno;
        P101_TRACK_EXEC_FAILURE(env, file);
        P101_ERROR_RAISE_ERRNO(err, actual_error);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_fork(const struct p101_env *env, struct p101_error *err)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = fork();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }
    else if(ret_val == 0)
    {
        p101_env_after_fork_child(env);
    }
    else if(ret_val > 0)
    {
        pid_t child_pid;
        pid_t parent_pid;

        parent_pid = p101_getpid(env);
        child_pid  = ret_val;
        P101_TRACK_FORK(env, parent_pid, child_pid);
    }

    if(ret_val != 0)
    {
        P101_TRACE_EXIT(env);
    }
    return ret_val;
}

pid_t p101_getpgid(const struct p101_env *env, struct p101_error *err, pid_t pid)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = getpgid(pid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_getpgrp(const struct p101_env *env)
{
    pid_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getpgrp();

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_getpid(const struct p101_env *env)
{
    pid_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getpid();

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_getppid(const struct p101_env *env)
{
    pid_t ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = getppid();

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_getsid(const struct p101_env *env, struct p101_error *err, pid_t pid)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = getsid(pid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_pause(const struct p101_env *env, struct p101_error *err)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = pause();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_setpgid(const struct p101_env *env, struct p101_error *err, pid_t pid, pid_t pgid)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = setpgid(pid, pgid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

pid_t p101_setsid(const struct p101_env *env, struct p101_error *err)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, -1);
    errno   = 0;
    ret_val = setsid();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_TRACE_EXIT(env);
    return ret_val;
}

unsigned p101_sleep(const struct p101_env *env, unsigned seconds)
{
    unsigned ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = sleep(seconds);

    P101_TRACE_EXIT(env);
    return ret_val;
}

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
#include <sched.h>

int p101_sched_yield(const struct p101_env *env, struct p101_error *err)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sched_yield();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

/*
 * Copyright 2022-2024 D'Arcy Smith.
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

void p101_siglongjmp(const struct p101_env *env, sigjmp_buf jmpbuf, int val)
{
    P101_TRACE(env);
    errno = 0;
    P101_TRACE_EXIT(env);
    siglongjmp(jmpbuf, val);
}

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

int p101_kill(const struct p101_env *env, struct p101_error *err, pid_t pid, int sig)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = kill(pid, sig);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigaction(const struct p101_env *env, struct p101_error *err, int sig, const struct sigaction *restrict act, struct sigaction *restrict oact)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigaction(sig, act, oact);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigaddset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno = 0;

#ifdef __APPLE__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wsign-conversion"
    ret_val = sigaddset(set, signo);
    #pragma GCC diagnostic pop
#else
    ret_val = sigaddset(set, signo);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigdelset(const struct p101_env *env, struct p101_error *err, sigset_t *set, int signo)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno = 0;
#ifdef __APPLE__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wsign-conversion"
    ret_val = sigdelset(set, signo);
    #pragma GCC diagnostic pop
#else
    ret_val = sigdelset(set, signo);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigemptyset(const struct p101_env *env, struct p101_error *err, sigset_t *set)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigemptyset(set);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigfillset(const struct p101_env *env, struct p101_error *err, sigset_t *set)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigfillset(set);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigismember(const struct p101_env *env, struct p101_error *err, const sigset_t *set, int signo)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno = 0;
#ifdef __APPLE__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wsign-conversion"
    ret_val = sigismember(set, signo);
    #pragma GCC diagnostic pop
#else
    ret_val = sigismember(set, signo);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigpending(const struct p101_env *env, struct p101_error *err, sigset_t *set)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigpending(set);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigprocmask(const struct p101_env *env, struct p101_error *err, int how, const sigset_t *restrict set, sigset_t *restrict oset)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigprocmask(how, set, oset);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigsuspend(const struct p101_env *env, struct p101_error *err, const sigset_t *sigmask)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigsuspend(sigmask);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigwait(const struct p101_env *env, struct p101_error *err, const sigset_t *restrict set, int *restrict sig)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    errno   = 0;
    ret_val = sigwait(set, sig);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

/*
 *Copyright 2021-2024 D'Arcy Smith.
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */

#include <stdint.h>

static int stdio_error_code(int error_code);

static int stdio_error_code(int error_code)
{
    if(error_code == 0)
    {
        error_code = EIO;
    }

    return error_code;
}

int p101_pclose(const struct p101_env *env, struct p101_error *err, FILE *stream)
{
    int actual_error;
    int fd;
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    fd    = fileno(stream);
    errno = 0;
    P101_TRACK_POINTER_RESOURCE_RELEASE(env, "stdio-stream", stream, "pclose");
    ret_val      = pclose(stream);
    actual_error = errno;

    if(fd >= 0)
    {
        P101_TRACK_CLOSE(env, fd);
    }

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(actual_error));
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

FILE *p101_popen(const struct p101_env *env, struct p101_error *err, const char *command, const char *mode)
{
    FILE *ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, NULL);
    errno   = 0;
    ret_val = popen(command, mode);    // NOLINT(cert-env33-c, bugprone-command-processor)

    if(ret_val == NULL)
    {
        P101_ERROR_RAISE_ERRNO(err, stdio_error_code(errno));
    }
    else
    {
        int fd;

        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "stdio-stream", ret_val, 0U, "popen");
        fd = fileno(ret_val);
        if(fd >= 0)
        {
            P101_TRACK_OPEN(env, fd);
        }
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

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

#include <stdlib.h>
#include <unistd.h>

int p101_setenv(const struct p101_env *env, struct p101_error *err, const char *envname, const char *envval, int overwrite)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = setenv(envname, envval, overwrite);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_unsetenv(const struct p101_env *env, struct p101_error *err, const char *name)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = unsetenv(name);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

/*
 * Copyright 2022-2024 D'Arcy Smith.
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

clock_t p101_times(const struct p101_env *env, struct p101_error *err, struct tms *buffer)
{
    clock_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, (clock_t)-1);
    errno   = 0;
    ret_val = times(buffer);

    if(ret_val == (clock_t)-1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

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

pid_t p101_wait(const struct p101_env *env, struct p101_error *err, int *stat_loc)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = wait(stat_loc);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_waitid(const struct p101_env *env, struct p101_error *err, idtype_t idtype, id_t id, siginfo_t *infop, int options)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = waitid(idtype, id, infop, options);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

pid_t p101_waitpid(const struct p101_env *env, struct p101_error *err, pid_t pid, int *stat_loc, int options)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = waitpid(pid, stat_loc, options);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

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

unsigned p101_alarm(const struct p101_env *env, unsigned seconds)
{
    unsigned ret_val;

    P101_TRACE(env);
    errno   = 0;
    ret_val = alarm(seconds);

    P101_TRACE_EXIT(env);
    return ret_val;
}

int p101_execv(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
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

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_execve(const struct p101_env *env, struct p101_error *err, const char *path, char *const argv[], char *const envp[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
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

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_execvp(const struct p101_env *env, struct p101_error *err, const char *file, char *const argv[])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
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

    P101_WRAPPER_DONE(env);
    return ret_val;
}

pid_t p101_fork(const struct p101_env *env, struct p101_error *err)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
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
        P101_WRAPPER_DONE(env);
    }
    return ret_val;
}

pid_t p101_getpgid(const struct p101_env *env, struct p101_error *err, pid_t pid)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = getpgid(pid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
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
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = getsid(pid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_pause(const struct p101_env *env, struct p101_error *err)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = pause();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_setpgid(const struct p101_env *env, struct p101_error *err, pid_t pid, pid_t pgid)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = setpgid(pid, pgid);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

pid_t p101_setsid(const struct p101_env *env, struct p101_error *err)
{
    pid_t ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = setsid();

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
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

int p101_sched_get_priority_max(const struct p101_env *env, struct p101_error *err, int policy)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sched_get_priority_max(policy);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sched_get_priority_min(const struct p101_env *env, struct p101_error *err, int policy)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sched_get_priority_min(policy);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

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

int p101_posix_spawn(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict path, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                     char *const envp[restrict])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawn(pid, path, file_actions, attrp, argv, envp);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else if(pid != NULL)
    {
        P101_TRACK_SPAWN(env, (long)p101_getpid(env), (long)*pid, path);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawn_file_actions_addclose(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawn_file_actions_addclose(file_actions, fildes);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawn_file_actions_adddup2(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions, int fildes, int newfildes)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawn_file_actions_adddup2(file_actions, fildes, newfildes);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawn_file_actions_addopen(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *restrict file_actions, int fildes, const char *restrict path, int oflag, mode_t mode)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawn_file_actions_addopen(file_actions, fildes, path, oflag, mode);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawn_file_actions_destroy(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions)
{
    char resource_id[P101_ENV_POINTER_RESOURCE_ID_SIZE];
    int  ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    p101_env_pointer_resource_id(resource_id, sizeof(resource_id), (const void *)file_actions);
    ret_val = posix_spawn_file_actions_destroy(file_actions);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else
    {
        P101_TRACK_RESOURCE_RELEASE(env, "spawn-file-actions", resource_id, NULL);
    }
    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawn_file_actions_init(const struct p101_env *env, struct p101_error *err, posix_spawn_file_actions_t *file_actions)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawn_file_actions_init(file_actions);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else
    {
        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "spawn-file-actions", (const void *)file_actions, 0U, NULL);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_destroy(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr)
{
    char resource_id[P101_ENV_POINTER_RESOURCE_ID_SIZE];
    int  ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    p101_env_pointer_resource_id(resource_id, sizeof(resource_id), (const void *)attr);
    ret_val = posix_spawnattr_destroy(attr);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else
    {
        P101_TRACK_RESOURCE_RELEASE(env, "spawn-attributes", resource_id, NULL);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_getflags(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, short *restrict flags)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_getflags(attr, flags);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_getpgroup(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, pid_t *restrict pgroup)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_getpgroup(attr, pgroup);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_getsigdefault(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigdefault)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_getsigdefault(attr, sigdefault);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_getsigmask(const struct p101_env *env, struct p101_error *err, const posix_spawnattr_t *restrict attr, sigset_t *restrict sigmask)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_getsigmask(attr, sigmask);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_init(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_init(attr);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else
    {
        P101_TRACK_POINTER_RESOURCE_ACQUIRE(env, "spawn-attributes", (const void *)attr, 0U, NULL);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_setflags(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, short flags)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_setflags(attr, flags);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_setpgroup(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *attr, pid_t pgroup)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_setpgroup(attr, pgroup);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_setsigdefault(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigdefault)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_setsigdefault(attr, sigdefault);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnattr_setsigmask(const struct p101_env *env, struct p101_error *err, posix_spawnattr_t *restrict attr, const sigset_t *restrict sigmask)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnattr_setsigmask(attr, sigmask);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_posix_spawnp(const struct p101_env *env, struct p101_error *err, pid_t *restrict pid, const char *restrict file, const posix_spawn_file_actions_t *file_actions, const posix_spawnattr_t *restrict attrp, char *const argv[restrict],
                      char *const envp[restrict])
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN_CODE(env, err, ret_val);
    ret_val = posix_spawnp(pid, file, file_actions, attrp, argv, envp);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, ret_val);
    }
    else if(pid != NULL)
    {
        P101_TRACK_SPAWN(env, (long)p101_getpid(env), (long)*pid, file);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_killpg(const struct p101_env *env, struct p101_error *err, pid_t pgrp, int sig)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = killpg(pgrp, sig);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_sigaltstack(const struct p101_env *env, struct p101_error *err, const stack_t *restrict ss, stack_t *restrict oss)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = sigaltstack(ss, oss);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

#include <p101_c/p101_string.h>
#include <string.h>

int p101_putenv(const struct p101_env *env, struct p101_error *err, char *string)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = putenv(string);

    if(ret_val != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_getpriority(const struct p101_env *env, struct p101_error *err, int which, id_t who)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno = 0;
#ifdef __linux__
    ret_val = getpriority((__priority_which_t)which, who);
#elif defined(__FreeBSD__)
    ret_val = getpriority(which, (int)who);
#else
    ret_val = getpriority(which, who);
#endif

    if(ret_val == -1 && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_getrlimit(const struct p101_env *env, struct p101_error *err, int resource, struct rlimit *rlp)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    if(resource < 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        ret_val = -1;
        goto p101_wrapper_done_;
    }
    errno = 0;
#ifdef __linux__
    ret_val = getrlimit((__rlimit_resource_t)resource, rlp);
#else
    ret_val = getrlimit(resource, rlp);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_getrusage(const struct p101_env *env, struct p101_error *err, int who, struct rusage *r_usage)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = getrusage(who, r_usage);

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_setpriority(const struct p101_env *env, struct p101_error *err, int which, id_t who, int value)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno = 0;
#ifdef __linux__
    ret_val = setpriority((__priority_which_t)which, who, value);
#elif defined(__FreeBSD__)
    ret_val = setpriority(which, (int)who, value);
#else
    ret_val = setpriority(which, who, value);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

int p101_setrlimit(const struct p101_env *env, struct p101_error *err, int resource, const struct rlimit *rlp)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    if(resource < 0)
    {
        P101_ERROR_RAISE_ERRNO(err, EINVAL);
        ret_val = -1;
        goto p101_wrapper_done_;
    }
    errno = 0;
#ifdef __linux__
    ret_val = setrlimit((__rlimit_resource_t)resource, rlp);
#else
    ret_val = setrlimit(resource, rlp);
#endif

    if(ret_val == -1)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

#ifdef __linux__
    #include <crypt.h>
#endif

int p101_nice(const struct p101_env *env, struct p101_error *err, int value)
{
    int ret_val;

    P101_TRACE(env);
    P101_WRAPPER_FAULT_RETURN(env, err, ret_val, -1);
    errno   = 0;
    ret_val = nice(value);

    if(ret_val == -1 && errno != 0)
    {
        P101_ERROR_RAISE_ERRNO(err, errno);
    }

    P101_WRAPPER_DONE(env);
    return ret_val;
}

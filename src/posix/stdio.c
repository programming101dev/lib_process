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

#include "p101_process/process.h"
#include <p101_env/wrapper.h>
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

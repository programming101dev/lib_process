#include "p101_process/process.h"
#include <p101_c/p101_string.h>
#include <p101_env/wrapper.h>
#include <stdlib.h>
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

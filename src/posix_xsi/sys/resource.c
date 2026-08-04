#include "p101_process/process.h"
#include <p101_env/wrapper.h>

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

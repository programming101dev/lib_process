#include <p101_env/env.h>
#include <p101_error/error.h>
#include <p101_process/process.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int failures;

#define EXPECT(condition)                                                                                                                                                                                                                                          \
    do                                                                                                                                                                                                                                                             \
    {                                                                                                                                                                                                                                                              \
        if(!(condition))                                                                                                                                                                                                                                           \
        {                                                                                                                                                                                                                                                          \
            fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition);                                                                                                                                                                                   \
            failures++;                                                                                                                                                                                                                                            \
        }                                                                                                                                                                                                                                                          \
    } while(0)

static void handle_alarm(int signal_number)
{
    (void)signal_number;
}

static void test_process_getters(const struct p101_env *env)
{
    /* P101_TEST_CASE(p101_getpid) */
    EXPECT(p101_getpid(env) == getpid());
    /* P101_TEST_CASE(p101_getppid) */
    EXPECT(p101_getppid(env) == getppid());
    /* P101_TEST_CASE(p101_getpgrp) */
    EXPECT(p101_getpgrp(env) == getpgrp());
    /* P101_TEST_CASE(p101_sleep) */
    EXPECT(p101_sleep(env, 0) == 0);
}

static void test_signal_waits(const struct p101_env *env, struct p101_error *err)
{
    struct sigaction action = {0};
    sigset_t         mask;

    action.sa_handler = handle_alarm;
    EXPECT(sigemptyset(&action.sa_mask) == 0);
    EXPECT(sigaction(SIGALRM, &action, NULL) == 0);

    /* P101_TEST_CASE(p101_alarm) */
    EXPECT(p101_alarm(env, 1) == 0);
    /* P101_TEST_CASE(p101_pause) */
    EXPECT(p101_pause(env, err) == -1);
    p101_error_reset(err);

    EXPECT(sigemptyset(&mask) == 0);
    EXPECT(p101_alarm(env, 1) == 0);
    /* P101_TEST_CASE(p101_sigsuspend) */
    EXPECT(p101_sigsuspend(env, err, &mask) == -1);
    p101_error_reset(err);
    EXPECT(p101_alarm(env, 0) == 0);
}

static void test_siglongjmp(const struct p101_env *env)
{
    sigjmp_buf jump_buffer;
    int        value;

    value = sigsetjmp(jump_buffer, 1);
    if(value == 0)
    {
        /* P101_TEST_CASE(p101_siglongjmp) */
        p101_siglongjmp(env, jump_buffer, 17);
    }
    EXPECT(value == 17);
}

int main(void)
{
    struct p101_error *err;
    struct p101_env   *env;

    err = p101_error_create(false);
    if(err == NULL)
    {
        return EXIT_FAILURE;
    }
    env = p101_env_create(err, NULL);
    if(env == NULL)
    {
        p101_error_destroy(err);
        return EXIT_FAILURE;
    }
    test_process_getters(env);
    test_signal_waits(env, err);
    test_siglongjmp(env);
    p101_env_destroy(env);
    p101_error_destroy(err);
    return failures == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

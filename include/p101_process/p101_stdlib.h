#ifndef LIBP101_PROCESS_P101_STDLIB_H
#define LIBP101_PROCESS_P101_STDLIB_H

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

    int p101_putenv(const struct p101_env *env, struct p101_error *err, char *string) P101_ATTR_SEMANTIC_ROLE("p101:environment:invalidates-borrowed");
    int p101_setenv(const struct p101_env *env, struct p101_error *err, const char *envname, const char *envval, int overwrite) P101_ATTR_SEMANTIC_ROLE("p101:environment:invalidates-borrowed");
    int p101_unsetenv(const struct p101_env *env, struct p101_error *err, const char *name) P101_ATTR_SEMANTIC_ROLE("p101:environment:invalidates-borrowed");

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_P101_STDLIB_H

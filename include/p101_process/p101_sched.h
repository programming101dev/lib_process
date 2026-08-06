#ifndef LIBP101_PROCESS_P101_SCHED_H
#define LIBP101_PROCESS_P101_SCHED_H

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

    int p101_sched_get_priority_max(const struct p101_env *env, struct p101_error *err, int policy);
    int p101_sched_get_priority_min(const struct p101_env *env, struct p101_error *err, int policy);
    int p101_sched_yield(const struct p101_env *env, struct p101_error *err);

#ifdef __cplusplus
}
#endif

#endif    // LIBP101_PROCESS_P101_SCHED_H

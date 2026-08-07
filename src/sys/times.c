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

#include "p101_process/sys/p101_times.h"
#include <p101_env/wrapper.h>

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

/*
 * clock_t is an int on FreeBSD and a long or unsigned long elsewhere, so
 * (clock_t)-1 — the sentinel these functions must return and compare against —
 * is a redundant cast on one platform and a required one on the others. No
 * single spelling satisfies every platform, so GCC's redundant-cast report is
 * disabled for this function alone. The guard is narrow: clang has no such
 * diagnostic. -Wpragmas and -Wunknown-warning-option are silenced first so
 * compilers that do not know -Wuseless-cast accept the pragma instead of
 * complaining about it.
 */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpragmas"
#pragma GCC diagnostic ignored "-Wunknown-warning-option"
#pragma GCC diagnostic ignored "-Wuseless-cast"

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

#pragma GCC diagnostic pop

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>
#include "php_ext.h"
#include "kernel/debug.h"
#include "kernel/main.h"
#include "kernel/string.h"

#ifndef ZEPHIR_RELEASE

void zephir_vdump(zval *var, const char *func)
{
    if (Z_TYPE_P(var) > IS_CALLABLE) {
        fprintf(stderr, "%s: (%p) has invalid type %u\n", func, var, Z_TYPE_P(var));
    }

    if (!Z_REFCOUNTED_P(var)) {
    	fprintf(stderr, "%s: (%p) is not reference-counted, type=%d\n", func, var, Z_TYPE_P(var));
        return;
    }

    if (Z_REFCOUNT_P(var) == 0) {
        fprintf(stderr, "%s: (%p) has 0 references, type=%d\n", func, var, Z_TYPE_P(var));
    } else {
        if (Z_REFCOUNT_P(var) >= 1000000) {
            fprintf(stderr, "%s: (%p) has too many references (%u), type=%d\n", func, var, Z_REFCOUNT_P(var), Z_TYPE_P(var));
        }
    }
}

#endif

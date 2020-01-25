
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
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

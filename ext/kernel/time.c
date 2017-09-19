
/*
 +------------------------------------------------------------------------+
 | Zephir Language                                                        |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Zephir Team  (http://www.zephir-lang.com)      |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@zephir-lang.com so we can send you a copy immediately.      |
 +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef PHP_WIN32
#include "win32/time.h"
#elif defined(NETWARE)
#include <sys/timeval.h>
#include <sys/time.h>
#else
#include <sys/time.h>
#endif

#include <ctype.h>

#include "php.h"
#include "php_ext.h"

#include "kernel/main.h"
#include "kernel/time.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

void zephir_time(zval *return_value)
{
	RETURN_LONG(time(NULL));
}

void zephir_microtime(zval *return_value, zval *get_as_float TSRMLS_DC)
{
#ifdef PHP_WIN32
	zval z_as_float;
	zval *params[1];

ZEPHIR_SINIT_VAR(z_as_float);
if (get_as_float && ZEPHIR_IS_TRUE(get_as_float)) {
	ZVAL_BOOL(&z_as_float, 1);
} else {
	ZVAL_BOOL(&z_as_float, 0);
}

	params[0] = &z_as_float;

	zephir_return_call_function(return_value, NULL, ZEND_STRL("microtime"), NULL, 0, 1, params TSRMLS_CC);
	return;
#else
	struct timeval tp = {0};
	char ret[100];

	if (gettimeofday(&tp, NULL)) {
		RETURN_FALSE;
	}

	if (get_as_float && ZEPHIR_IS_TRUE(get_as_float)) {
		RETURN_DOUBLE((double)(tp.tv_sec + tp.tv_usec / MICRO_IN_SEC));
	}

	snprintf(ret, 100, "%.8F %ld", tp.tv_usec / MICRO_IN_SEC, tp.tv_sec);
	RETURN_STRING(ret, 1);
#endif
}

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
#include "kernel/operators.h"

void zephir_time(zval *return_value)
{
	RETURN_LONG(time(NULL));
}

void zephir_microtime(zval *return_value, zval *get_as_float)
{
	struct timeval tp = {0};
	char ret[100];

	if (gettimeofday(&tp, NULL)) {
		RETURN_FALSE;
	}

	if (get_as_float && ZEPHIR_IS_TRUE(get_as_float)) {
		RETURN_DOUBLE((double)(tp.tv_sec + tp.tv_usec / MICRO_IN_SEC));
	}

	snprintf(ret, 100, "%.8F %ld", tp.tv_usec / MICRO_IN_SEC, tp.tv_sec);
	RETURN_STRING(ret);
}

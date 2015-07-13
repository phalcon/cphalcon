/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
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

#include <php.h>

#include "kernel/main.h"
#include "kernel/time.h"
#include "kernel/operators.h"

void phalcon_time(zval *return_value)
{
	RETURN_LONG(time(NULL));
}

void phalcon_microtime(zval *return_value, zval *get_as_float TSRMLS_DC)
{
	struct timeval tp = {0};
	char ret[100];

	if (gettimeofday(&tp, NULL)) {
		RETURN_FALSE;
	}

	if (get_as_float && PHALCON_IS_TRUE(get_as_float)) {
		RETURN_DOUBLE((double)(tp.tv_sec + tp.tv_usec / MICRO_IN_SEC));
	}

	snprintf(ret, 100, "%.8F %ld", tp.tv_usec / MICRO_IN_SEC, tp.tv_sec);
	RETURN_STRING(ret, 1);
}

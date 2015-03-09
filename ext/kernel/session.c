
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team  (http://www.zephir-lang.com)      |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/session.h"

#ifdef ZEPHIR_USE_PHP_SESSION
#include <ext/session/php_session.h>
#endif

void zephir_session_start(TSRMLS_D)
{
#ifdef ZEPHIR_USE_PHP_SESSION
	php_session_start(TSRMLS_C);
#else
	//zephir_call_func_params(NULL, NULL, SL("session_start") TSRMLS_CC, 0);
#endif
}

void zephir_session_destroy(TSRMLS_D)
{
	//zephir_call_func_params(NULL, NULL, SL("session_destroy") TSRMLS_CC, 0);
}

void zephir_get_session_id(zval *return_value, zval **return_value_ptr TSRMLS_DC)
{
#ifdef ZEPHIR_USE_PHP_SESSION
	if (PS(id)) {
		RETURN_STRING(PS(id), 1);
	}

	RETURN_EMPTY_STRING();
#else
	//zephir_call_func_params(return_value, return_value_ptr, SL("session_id") TSRMLS_CC, 0);
#endif
}

void zephir_set_session_id(zval *sid TSRMLS_DC)
{
#ifdef ZEPHIR_USE_PHP_SESSION
	zval copy;
	int use_copy = 0;

	if (unlikely(Z_TYPE_P(sid) != IS_STRING)) {
		zend_make_printable_zval(sid, &copy, &use_copy);
		if (use_copy) {
			sid = &copy;
		}
	}

	if (PS(id)) {
		efree(PS(id));
	}

	PS(id) = estrndup(Z_STRVAL_P(sid), Z_STRLEN_P(sid));

	if (unlikely(use_copy)) {
		zval_dtor(&copy);
	}
#else
	//zephir_call_func_params(NULL, NULL, SL("session_id") TSRMLS_CC, 1, sid);
#endif
}

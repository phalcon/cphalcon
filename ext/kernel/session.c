/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "kernel/session.h"

#ifdef PHALCON_USE_PHP_SESSION
#include <ext/session/php_session.h>
#endif

#include "kernel/main.h"
#include "kernel/fcall.h"

int phalcon_session_start(TSRMLS_D)
{
#ifdef PHALCON_USE_PHP_SESSION
	php_session_start(TSRMLS_C);
	return SUCCESS;
#else
	return phalcon_call_func_aparams(NULL, SL("session_start"), 0, NULL TSRMLS_CC);
#endif
}

int phalcon_session_destroy(TSRMLS_D)
{
	return phalcon_call_func_aparams(NULL, SL("session_destroy"), 0, NULL TSRMLS_CC);
}

int phalcon_get_session_id(zval *return_value, zval **return_value_ptr TSRMLS_DC)
{
#ifdef PHALCON_USE_PHP_SESSION
	if (PS(id)) {
		RETVAL_STRING(PS(id), 1);
	}
	else {
		RETVAL_EMPTY_STRING();
	}

	return SUCCESS;
#else
	return phalcon_return_call_function(return_value, return_value_ptr, SL("session_id"), 0, NULL TSRMLS_CC);
#endif
}

int phalcon_set_session_id(zval *sid TSRMLS_DC)
{
#ifdef PHALCON_USE_PHP_SESSION
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

	return SUCCESS;
#else
	zval *params[] = { sid };
	return phalcon_call_func_aparams(NULL, SL("session_id"), 1, params TSRMLS_CC);
#endif
}

int phalcon_session_write_close(TSRMLS_D)
{
	return phalcon_call_func_aparams(NULL, SL("session_write_close"), 0, NULL TSRMLS_CC);
}

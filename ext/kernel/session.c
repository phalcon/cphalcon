/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/session.h"

#ifdef PHALCON_USE_PHP_SESSION
#include "ext/session/php_session.h"
#endif

void phalcon_session_start(TSRMLS_D)
{
#ifdef PHALCON_USE_PHP_SESSION
	php_session_start(TSRMLS_C);
#else
	phalcon_call_func_ex(NULL, SL("session_start"), 0 TSRMLS_CC);
#endif
}

void phalcon_session_destroy(TSRMLS_D)
{
	phalcon_call_func_ex(NULL, SL("session_destroy"), 0 TSRMLS_CC);
}

void phalcon_get_session_id(zval *return_value TSRMLS_DC)
{
#ifdef PHALCON_USE_PHP_SESSION
	if (PS(id)) {
		RETURN_STRING(PS(id), 1);
	}

	RETURN_EMPTY_STRING();
#else
	phalcon_call_func_ex(return_value, SL("session_id"), 1 TSRMLS_CC);
#endif
}

void phalcon_set_session_id(zval *sid TSRMLS_DC)
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
#else
	phalcon_call_func_one_param(NULL, SL("session_id"), sid, 0 TSRMLS_CC);
#endif
}

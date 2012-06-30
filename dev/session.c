
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
/**
 * Phalcon_Session
 *
 * Session client-server persistent state data management. This component
 * allow you to separate your session data between application or modules.
 * With this, it's possible to use the same index to refer a variable
 * but they can be in different applications.
 *
 * 
 */

/**
 * Starts session, optionally using an adapter
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, start){

	zval *options = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_start");
	
	PHALCON_MM_RESTORE();
}

/**
 * Destroys a session, optionally also deleting the session cookie.  Calling this function before calling Phalcon_Session::start() is an error.
 *
 * @param array $delete_cookie
 */
PHP_METHOD(Phalcon_Session, destroy){

	zval *session_cookie_name = NULL,
		*session_cookie_value = NULL,
		*session_cookie_expiration = NULL,
		*session_cookie_params = NULL,
		*session_cookie_path_key = NULL,
		*session_cookie_path = NULL,
		*session_cookie_domain_key = NULL,
		*session_cookie_domain = NULL,
		*session_cookie_secure_key = NULL,
		*session_cookie_secure = NULL,
		*session_cookie_httponly_key = NULL,
		*session_cookie_httponly = NULL,
		*cookies = NULL,
		*set_cookie_return = NULL,
		*session_destroy_return = NULL;
	zval* set_cookie_params[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

	zend_bool delete_cookie = FALSE;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|b", &delete_cookie) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (delete_cookie) {
		PHALCON_ALLOC_ZVAL_MM(session_cookie_params);
		PHALCON_CALL_FUNC(session_cookie_params, "session_get_cookie_params");

		PHALCON_ALLOC_ZVAL_MM(session_cookie_name);
		PHALCON_CALL_FUNC(session_cookie_name, "session_name");
		set_cookie_params[0] = session_cookie_name;

		PHALCON_ALLOC_ZVAL_MM(session_cookie_value);
		ZVAL_STRING(session_cookie_value, "", 1);
		set_cookie_params[1] = session_cookie_value;

		PHALCON_INIT_VAR(session_cookie_expiration);
		ZVAL_LONG(session_cookie_expiration, 1);
		set_cookie_params[2] = session_cookie_expiration;

		PHALCON_ALLOC_ZVAL_MM(session_cookie_path_key);
		ZVAL_STRING(session_cookie_path_key, "path", 1);
		PHALCON_ALLOC_ZVAL_MM(session_cookie_path);
		phalcon_array_fetch(&session_cookie_path, session_cookie_params, session_cookie_path_key, PHALCON_NOISY TSRMLS_CC);
		set_cookie_params[3] = session_cookie_path;

		PHALCON_ALLOC_ZVAL_MM(session_cookie_domain_key);
		ZVAL_STRING(session_cookie_domain_key, "domain", 1);
		PHALCON_ALLOC_ZVAL_MM(session_cookie_domain);
		phalcon_array_fetch(&session_cookie_domain, session_cookie_params, session_cookie_domain_key, PHALCON_NOISY TSRMLS_CC);
		set_cookie_params[4] = session_cookie_domain;

		PHALCON_ALLOC_ZVAL_MM(session_cookie_secure_key);
		ZVAL_STRING(session_cookie_secure_key, "secure", 1);
		PHALCON_ALLOC_ZVAL_MM(session_cookie_secure);
		phalcon_array_fetch(&session_cookie_secure, session_cookie_params, session_cookie_secure_key, PHALCON_NOISY TSRMLS_CC);
		set_cookie_params[5] = session_cookie_secure;

		PHALCON_ALLOC_ZVAL_MM(session_cookie_httponly_key);
		ZVAL_STRING(session_cookie_httponly_key, "httponly", 1);
		PHALCON_ALLOC_ZVAL_MM(session_cookie_httponly);
		phalcon_array_fetch(&session_cookie_httponly, session_cookie_params, session_cookie_httponly_key, PHALCON_NOISY TSRMLS_CC);
		set_cookie_params[6] = session_cookie_httponly;

		PHALCON_ALLOC_ZVAL_MM(set_cookie_return);
		PHALCON_CALL_FUNC_PARAMS(set_cookie_return, "setcookie", 7, set_cookie_params);
	}

	PHALCON_ALLOC_ZVAL_MM(session_destroy_return);
	PHALCON_CALL_FUNC(session_destroy_return, "session_destroy");
	
	RETURN_DZVAL(session_destroy_return);
}

/**
 * Sets session options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, setOptions){

	zval *options = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(options, SL("uniqueId")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, SL("uniqueId"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_static_property(SL("Phalcon_Session"), SL("_uniqueId"), r0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, get){

	zval *index = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Session"), SL("_uniqueId") TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t0, index);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, g0, key, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(r1);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a session variable in an application context
 *
 * @param string $index
 * @param string $value
 */
PHP_METHOD(Phalcon_Session, set){

	zval *index = NULL, *value = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Session"), SL("_uniqueId") TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t0, index);
	phalcon_array_update(&g0, r0, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a session variable is set in an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, has){

	zval *index = NULL, *key = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Session"), SL("_uniqueId") TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t0, index);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, remove){

	zval *index = NULL, *key = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *g0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Session"), SL("_uniqueId") TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t0, index);
	PHALCON_CPY_WRT(key, r0);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	phalcon_array_unset(g0, key);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns active session id
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session, getId){

	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "session_id");
	RETURN_DZVAL(r0);
}

/**
 * Checks if session cookie exists
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session, exists){
	zval *session_cookie_name = NULL,
		 *cookies = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(session_cookie_name);
	PHALCON_CALL_FUNC(session_cookie_name, "session_name");

	phalcon_get_global(&cookies, SL("_COOKIE")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(cookies, session_cookie_name);

	PHALCON_MM_RESTORE();

	if (eval_int) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}



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
  |          Jere Jones <jere.jones@gmail.com>                             |
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"

/**
 * Phalcon\Session
 *
 * Session client-server persistent state data management. This component
 * allows you to separate your session data between application or modules.
 * With this, it's possible to use the same index to refer a variable
 * but they can be in different applications.
 *
 * <code>
 * $session = new Phalcon\Session\Adapter\Files(array(
 *    'uniqueId' => 'my-private-app'
 * ));
 *
 * $session->start();
 *
 * $session->set('var', 'some-value');
 *
 * echo $session->get('var');
 * </code>
 */


/**
 * Phalcon\Session construtor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, __construct){

	zval *options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setoptions", options, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts session, optionally using an adapter
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, start){

	zval *headers_sent;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers_sent);
	PHALCON_CALL_FUNC(headers_sent, "headers_sent");
	if (PHALCON_IS_FALSE(headers_sent)) {
		PHALCON_CALL_FUNC_NORETURN("session_start");
		phalcon_update_property_bool(this_ptr, SL("_started"), 1 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Sets session options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session, setOptions){

	zval *options, *unique_id;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(options) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(options, SS("uniqueId"));
		if (eval_int) {
			PHALCON_INIT_VAR(unique_id);
			phalcon_array_fetch_string(&unique_id, options, SL("uniqueId"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_uniqueId"), unique_id TSRMLS_CC);
		}
		phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_session_exception_ce, "Options must be an Array");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Get internal options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Session, getOptions){

	zval *options;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	RETURN_CCTOR(options);
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, get){

	zval *index, *unique_id, *key, *value;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(unique_id);
	phalcon_read_property(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch(&value, g0, key, PH_NOISY_CC);
		
		RETURN_CCTOR(value);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Sets a session variable in an application context
 *
 * @param string $index
 * @param string $value
 */
PHP_METHOD(Phalcon_Session, set){

	zval *index, *value, *unique_id, *key;
	zval *g0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(unique_id);
	phalcon_read_property(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	phalcon_array_update_zval(&g0, key, &value, PH_COPY TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a session variable is set in an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, has){

	zval *index, *unique_id, *key;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(unique_id);
	phalcon_read_property(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	eval_int = phalcon_array_isset(g0, key);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Removes a session variable from an application context
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session, remove){

	zval *index, *unique_id, *key;
	zval *g0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(unique_id);
	phalcon_read_property(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
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

	zval *session_id;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(session_id);
	PHALCON_CALL_FUNC(session_id, "session_id");
	
	RETURN_CCTOR(session_id);
}

/**
 * Check whether the session has been started
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session, isStarted){

	zval *started;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(started);
	phalcon_read_property(&started, this_ptr, SL("_started"), PH_NOISY_CC);
	
	RETURN_CCTOR(started);
}

/**
 * Destroys the active session
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session, destroy){

	zval *destroyed;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(destroyed);
	PHALCON_CALL_FUNC(destroyed, "session_destroy");
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	RETURN_CCTOR(destroyed);
}



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

#include "main/SAPI.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/session.h"

/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */


/**
 * Phalcon\Session\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Session_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Session, Adapter, session_adapter, phalcon_session_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_session_adapter_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_session_adapter_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_session_adapter_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Session\Adapter constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session_Adapter, __construct){

	zval *options = NULL;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) {
		phalcon_call_method_params(NULL, NULL, this_ptr, SL("setoptions"), zend_inline_hash_func(SS("setoptions")) TSRMLS_CC, 1, options);
	}
}

PHP_METHOD(Phalcon_Session_Adapter, __destruct) {

	zval *started;

	started = phalcon_fetch_nproperty_this(getThis(), SL("_started"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(started)) {
		phalcon_session_write_close(TSRMLS_C);
		phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	}
}

/**
 * Starts the session (if headers are already sent the session will not be started)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, start){

	if (!SG(headers_sent)) {
		phalcon_session_start(TSRMLS_C);
		phalcon_update_property_bool(this_ptr, SL("_started"), 1 TSRMLS_CC);
		RETURN_TRUE;
	}
	
	RETURN_FALSE;
}

/**
 * Sets session's options
 *
 *<code>
 *	$session->setOptions(array(
 *		'uniqueId' => 'my-private-app'
 *	));
 *</code>
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Session_Adapter, setOptions){

	zval *options, *unique_id;

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string_fetch(&unique_id, options, SS("uniqueId"))) {
			phalcon_update_property_this(this_ptr, SL("_uniqueId"), unique_id TSRMLS_CC);
		}

		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	}
}

/**
 * Get internal options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Session_Adapter, getOptions){

	RETURN_MEMBER(getThis(), "_options");
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 * @param mixed $defaultValue
 * @param bool $remove
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter, get){

	zval *index, *default_value = NULL, *remove = NULL, *unique_id, *key, *_SESSION;
	zval *value;

	PHALCON_MM_GROW();
	phalcon_fetch_params(1, 1, 2, &index, &default_value, &remove);
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	if (!remove) {
		remove = PHALCON_GLOBAL(z_false);
	}
	
	unique_id = phalcon_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, _SESSION, key)) {
		if (PHALCON_IS_NOT_EMPTY(value)) {
			RETVAL_ZVAL(value, 1, 0);
		}
		else {
			RETVAL_ZVAL(default_value, 1, 0);
		}

		if (zend_is_true(remove)) {
			phalcon_array_unset(&_SESSION, key, 0);
		}

		PHALCON_MM_RESTORE();
		return;
	}

	RETURN_CTOR(default_value);
}

/**
 * Sets a session variable in an application context
 *
 *<code>
 *	$session->set('auth', 'yes');
 *</code>
 *
 * @param string $index
 * @param string $value
 */
PHP_METHOD(Phalcon_Session_Adapter, set){

	zval *index, *value, *unique_id, *key, *_SESSION;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &index, &value);
	
	unique_id = phalcon_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	phalcon_array_update_zval(&_SESSION, key, &value, PH_COPY);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a session variable is set in an application context
 *
 *<code>
 *	var_dump($session->has('auth'));
 *</code>
 *
 * @param string $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, has){

	zval *index, *unique_id, *key, *_SESSION;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	unique_id = phalcon_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	if (phalcon_array_isset(_SESSION, key)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Removes a session variable from an application context
 *
 *<code>
 *	$session->remove('auth');
 *</code>
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Session_Adapter, remove){

	zval *index, *unique_id, *key, *_SESSION;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	unique_id = phalcon_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	phalcon_array_unset(&_SESSION, key, 0);

	PHALCON_MM_RESTORE();
}

/**
 * Returns active session id
 *
 *<code>
 *	echo $session->getId();
 *</code>
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session_Adapter, getId){


	phalcon_get_session_id(return_value, return_value_ptr TSRMLS_CC);
}

/**
 * Check whether the session has been started
 *
 *<code>
 *	var_dump($session->isStarted());
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, isStarted){


	RETURN_MEMBER(this_ptr, "_started");
}

/**
 * Destroys the active session
 *
 *<code>
 *	var_dump($session->destroy());
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, destroy){

	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	phalcon_session_destroy(TSRMLS_C);
	RETURN_TRUE;
}

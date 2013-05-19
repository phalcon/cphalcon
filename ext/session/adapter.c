
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

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"

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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		phalcon_call_method_p1_noret(this_ptr, "setoptions", options);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts the session (if headers are already sent the session will not be started)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, start){

	zval *headers_sent;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers_sent);
	PHALCON_CALL_FUNC(headers_sent, "headers_sent");
	if (PHALCON_IS_FALSE(headers_sent)) {
		PHALCON_CALL_FUNC_NORETURN("session_start");
		phalcon_update_property_bool(this_ptr, SL("_started"), 1 TSRMLS_CC);
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("uniqueId"))) {
			PHALCON_OBS_VAR(unique_id);
			phalcon_array_fetch_string(&unique_id, options, SL("uniqueId"), PH_NOISY_CC);
			phalcon_update_property_this(this_ptr, SL("_uniqueId"), unique_id TSRMLS_CC);
		}
		phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
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
PHP_METHOD(Phalcon_Session_Adapter, getOptions){

	zval *options;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	RETURN_CCTOR(options);
}

/**
 * Gets a session variable from an application context
 *
 * @param string $index
 * @param mixed $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter, get){

	zval *index, *default_value = NULL, *unique_id, *key, *_SESSION;
	zval *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &index, &default_value);
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	PHALCON_OBS_VAR(unique_id);
	phalcon_read_property_this(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	if (phalcon_array_isset(_SESSION, key)) {
	
		PHALCON_OBS_VAR(value);
		phalcon_array_fetch(&value, _SESSION, key, PH_NOISY_CC);
		if (PHALCON_IS_NOT_EMPTY(value)) {
			RETURN_CCTOR(value);
		}
	}
	
	RETURN_CCTOR(default_value);
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
	
	PHALCON_OBS_VAR(unique_id);
	phalcon_read_property_this(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, unique_id, index);
	phalcon_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	phalcon_array_update_zval(&_SESSION, key, &value, PH_COPY TSRMLS_CC);
	
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
 */
PHP_METHOD(Phalcon_Session_Adapter, has){

	zval *index, *unique_id, *key, *_SESSION;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_OBS_VAR(unique_id);
	phalcon_read_property_this(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
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
	
	PHALCON_OBS_VAR(unique_id);
	phalcon_read_property_this(&unique_id, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	
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

	zval *session_id;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(session_id);
	PHALCON_CALL_FUNC(session_id, "session_id");
	RETURN_CCTOR(session_id);
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

	zval *started;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(started);
	phalcon_read_property_this(&started, this_ptr, SL("_started"), PH_NOISY_CC);
	RETURN_CCTOR(started);
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

	zval *destroyed;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(destroyed);
	PHALCON_CALL_FUNC(destroyed, "session_destroy");
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	RETURN_CCTOR(destroyed);
}


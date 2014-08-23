
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Session, Adapter, phalcon, session_adapter, phalcon_session_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_session_adapter_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_session_adapter_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_adapter_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Session\Adapter constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Starts the session (if headers are already sent the session will not be started)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, start) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_started"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets session's options
 *
 *<code>
 *	session->setOptions(array(
 *		'uniqueId' => 'my-private-app'
 *	));
 *</code>
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter, setOptions) {

	zval *options, *uniqueId;

	zephir_fetch_params(0, 1, 0, &options);



	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_session_exception_ce, "Options must be an Array", "phalcon/session/adapter.zep", 79);
		return;
	}
	if (zephir_array_isset_string_fetch(&uniqueId, options, SS("uniqueId"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_uniqueId"), uniqueId TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

/**
 * Get internal options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Session_Adapter, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Gets a session variable from an application context
 *
 * @param string index
 * @param mixed defaultValue
 * @param boolean remove
 * @return mixed
 */
PHP_METHOD(Phalcon_Session_Adapter, get) {

	zval *index_param = NULL, *defaultValue = NULL, *remove = NULL, *value, *key, *_0, *_SESSION;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &remove);

	zephir_get_strval(index, index_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!remove) {
		remove = ZEPHIR_GLOBAL(global_false);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VV(key, _0, index);
	ZEPHIR_OBS_VAR(value);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	if (zephir_array_isset_fetch(&value, _SESSION, key, 0 TSRMLS_CC)) {
		if (!(ZEPHIR_IS_EMPTY(value))) {
			if (zephir_is_true(remove)) {
				zephir_array_unset(&_SESSION, key, PH_SEPARATE);
			}
			RETURN_CCTOR(value);
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets a session variable in an application context
 *
 *<code>
 *	session->set('auth', 'yes');
 *</code>
 *
 * @param string index
 * @param string value
 */
PHP_METHOD(Phalcon_Session_Adapter, set) {

	int _2;
	zval *index_param = NULL, *value, *_SESSION, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(index, index_param);


	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, index);
	_2 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, _1, &value, PH_COPY | PH_SEPARATE);
	if (_2) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a session variable is set in an application context
 *
 *<code>
 *	var_dump($session->has('auth'));
 *</code>
 *
 * @param string index
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, has) {

	zval *index_param = NULL, *_SESSION, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, index);
	RETURN_MM_BOOL(zephir_array_isset(_SESSION, _1));

}

/**
 * Removes a session variable from an application context
 *
 *<code>
 *	$session->remove('auth');
 *</code>
 *
 * @param string index
 */
PHP_METHOD(Phalcon_Session_Adapter, remove) {

	zval *index_param = NULL, *_0, *_1, *_SESSION;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, index);
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_array_unset(&_SESSION, _1, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Session_Adapter, getId) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Session_Adapter, isStarted) {


	RETURN_MEMBER(this_ptr, "_started");

}

/**
 * Destroys the active session
 *
 *<code>
 *	var_dump(session->destroy());
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Session_Adapter, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL);
	zephir_check_call_status();
	RETURN_MM();

}



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
#include "kernel/array.h"
#include "ext/session/php_session.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Manager
 *
 * Session manager class
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Manager)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session, Manager, phalcon, session_manager, phalcon_di_abstractinjectionaware_ce, phalcon_session_manager_method_entry, 0);

	/**
	 * @var SessionHandlerInterface|null
	 */
	zend_declare_property_null(phalcon_session_manager_ce, SL("adapter"), ZEND_ACC_PRIVATE);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_manager_ce, SL("name"), "", ZEND_ACC_PRIVATE);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_session_manager_ce, SL("options"), ZEND_ACC_PRIVATE);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_manager_ce, SL("uniqueId"), "", ZEND_ACC_PRIVATE);
	phalcon_session_manager_ce->create_object = zephir_init_properties_Phalcon_Session_Manager;

	zend_class_implements(phalcon_session_manager_ce, 1, phalcon_session_managerinterface_ce);
	return SUCCESS;
}

/**
 * Manager constructor.
 *
 * @param array options = [
 *     'uniqueId' => null
 * ]
 */
PHP_METHOD(Phalcon_Session_Manager, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Alias: Gets a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Manager, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias: Check whether a session variable is set in an application context
 */
PHP_METHOD(Phalcon_Session_Manager, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Alias: Sets a session variable in an application context
 */
PHP_METHOD(Phalcon_Session_Manager, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Alias: Removes a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Manager, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Destroy/end a session
 */
PHP_METHOD(Phalcon_Session_Manager, destroy)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SESSION, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_destroy", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_SESSION);
		array_init(&_SESSION);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether the session has been started
 */
PHP_METHOD(Phalcon_Session_Manager, exists)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 2));
}

/**
 * Gets a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Manager, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remove;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, *remove_param = NULL, _SESSION, __$null, uniqueKey, value, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_BOOL(remove)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 2, &key_param, &defaultValue, &remove_param);
	zephir_get_strval(&key, key_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!remove_param) {
		remove = 0;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	ZEPHIR_INIT_VAR(&value);
	ZVAL_NULL(&value);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_CCTOR(&value);
	}
	ZEPHIR_CALL_METHOD(&uniqueKey, this_ptr, "getuniquekey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&value, phalcon_helper_arr_ce, "get", &_1, 16, &_SESSION, &uniqueKey, defaultValue);
	zephir_check_call_status();
	if (remove) {
		zephir_array_unset(&_SESSION, &uniqueKey, PH_SEPARATE);
	}
	RETURN_CCTOR(&value);
}

/**
 * Returns the stored session adapter
 */
PHP_METHOD(Phalcon_Session_Manager, getAdapter)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "adapter");
}

/**
 * Returns the session id
 */
PHP_METHOD(Phalcon_Session_Manager, getId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the name of the session
 */
PHP_METHOD(Phalcon_Session_Manager, getName)
{
	zval _0, _1, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &_0)) {
		ZEPHIR_CALL_FUNCTION(&_2$$3, "session_name", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &_2$$3);
	}
	RETURN_MM_MEMBER(getThis(), "name");
}

/**
 * Check whether a session variable is set in an application context
 */
PHP_METHOD(Phalcon_Session_Manager, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _SESSION, uniqueKey, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&uniqueKey, this_ptr, "getuniquekey", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_array_isset(&_SESSION, &uniqueKey));
}

/**
 * Get internal options
 */
PHP_METHOD(Phalcon_Session_Manager, getOptions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "options");
}

/**
 * Regenerates the session id using the adapter.
 */
PHP_METHOD(Phalcon_Session_Manager, regenerateId)
{
	zend_bool delete = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deleteOldSession = NULL, deleteOldSession_sub, __$true, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&deleteOldSession_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(deleteOldSession)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &deleteOldSession);
	if (!deleteOldSession) {
		deleteOldSession = &deleteOldSession_sub;
		deleteOldSession = &__$true;
	}


	delete = zephir_get_boolval(deleteOldSession);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZVAL_BOOL(&_1$$3, (delete ? 1 : 0));
		ZEPHIR_CALL_FUNCTION(NULL, "session_regenerate_id", NULL, 0, &_1$$3);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

/**
 * Removes a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Manager, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _SESSION, _0, uniqueKey;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&uniqueKey);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&uniqueKey, this_ptr, "getuniquekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_array_unset(&_SESSION, &uniqueKey, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets a session variable in an application context
 */
PHP_METHOD(Phalcon_Session_Manager, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _SESSION, uniqueKey, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&uniqueKey, this_ptr, "getuniquekey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_array_update_zval(&_SESSION, &uniqueKey, value, PH_COPY | PH_SEPARATE);
	ZEPHIR_MM_RESTORE();
}

/**
 * Set the adapter for the session
 */
PHP_METHOD(Phalcon_Session_Manager, setAdapter)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, php_session_iface_entry)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &adapter);


	zephir_update_property_zval(this_ptr, ZEND_STRL("adapter"), adapter);
	RETURN_THISW();
}

/**
 * Set session Id
 */
PHP_METHOD(Phalcon_Session_Manager, setId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, _0, _1$$3;
	zval id, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);
	zephir_get_strval(&id, id_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SS(&_2$$3, "The session has already been started. ", "To change the id, use regenerateId()");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 272, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Session/Manager.zep", 254);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 0, &id);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Set the session name. Throw exception if the session has started
 * and do not allow poop names
 *
 * @param  string name
 *
 * @throws InvalidArgumentException
 *
 * @return Manager
 */
PHP_METHOD(Phalcon_Session_Manager, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cannot set session name after a session has started", "phalcon/Session/Manager.zep", 277);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/^[\\p{L}\\p{N}_-]+$/u");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/^[\\p{L}\\p{N}_-]+$/u");
	zephir_preg_match(&_3, &_4, &name, &_1, 0, 0 , 0 );
	if (UNEXPECTED(!zephir_is_true(&_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The name contains non alphanum characters", "phalcon/Session/Manager.zep", 283);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets session's options
 */
PHP_METHOD(Phalcon_Session_Manager, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, _0, _2, _3;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "uniqueId");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 16, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueId"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Starts the session (if headers are already sent the session will not be
 * started)
 */
PHP_METHOD(Phalcon_Session_Manager, start)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _COOKIE, name, value, _0, _1, _2, _7, _3$$6, _4$$6, _5$$6, _6$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);


	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));

	ZEPHIR_CALL_METHOD(&name, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exists", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 363);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC);
	if (UNEXPECTED(!(zephir_is_instance_of(&_2, SL("SessionHandlerInterface"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "The session adapter is not valid", "phalcon/Session/Manager.zep", 327);
		return;
	}
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, &_COOKIE, &name, 0)) {
		ZEPHIR_INIT_VAR(&_3$$6);
		ZEPHIR_INIT_VAR(&_4$$6);
		ZVAL_STRING(&_4$$6, "/^[a-z0-9]+$/iD");
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZVAL_STRING(&_6$$6, "/^[a-z0-9]+$/iD");
		zephir_preg_match(&_5$$6, &_6$$6, &value, &_3$$6, 0, 0 , 0 );
		if (!(zephir_is_true(&_5$$6))) {
			zephir_array_unset(&_COOKIE, &name, PH_SEPARATE);
		}
	}
	zephir_read_property(&_7, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("session_start", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the status of the current session.
 */
PHP_METHOD(Phalcon_Session_Manager, status)
{
	zval status;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&status, 0)) {
			RETURN_MM_LONG(0);
		}
		if (ZEPHIR_IS_LONG(&status, 2)) {
			RETURN_MM_LONG(2);
		}
	} while(0);

	RETURN_MM_LONG(1);
}

/**
 * Returns the key prefixed
 */
PHP_METHOD(Phalcon_Session_Manager, getUniqueKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, uniqueId, _0, _1$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueId, &_0);
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("uniqueId"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, "#", &key);
		RETURN_MM();
	} else {
		RETURN_CTOR(&key);
	}
}

zend_object *zephir_init_properties_Phalcon_Session_Manager(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}



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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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

	zephir_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_ACTIVE"), 2);

	zephir_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_NONE"), 1);

	zephir_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_DISABLED"), 0);

	zend_class_implements(phalcon_session_adapter_ce TSRMLS_CC, 1, phalcon_session_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Session\Adapter constructor
 */
PHP_METHOD(Phalcon_Session_Adapter, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

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
 * Starts the session (if headers are already sent the session will not be started)
 */
PHP_METHOD(Phalcon_Session_Adapter, start) {

	zend_bool _2$$3;
	zval __$true, __$false, _0, _1$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 23);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_started"), PH_NOISY_CC | PH_READONLY);
		_2$$3 = !zephir_is_true(&_1$$3);
		if (_2$$3) {
			ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "status", NULL, 0);
			zephir_check_call_status();
			_2$$3 = !ZEPHIR_IS_LONG_IDENTICAL(&_3$$3, 2);
		}
		if (_2$$3) {
			ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 24);
			zephir_check_call_status();
			if (1) {
				zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
			}
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets session's options
 *
 *<code>
 * $session->setOptions(
 *     [
 *         "uniqueId" => "my-private-app",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, setOptions) {

	zval *options_param = NULL, uniqueId;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&uniqueId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	if (zephir_array_isset_string_fetch(&uniqueId, &options, SL("uniqueId"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_uniqueId"), &uniqueId);
	}
	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get internal options
 */
PHP_METHOD(Phalcon_Session_Adapter, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 * Set session name
 */
PHP_METHOD(Phalcon_Session_Adapter, setName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 25, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get session name
 */
PHP_METHOD(Phalcon_Session_Adapter, getName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_name", NULL, 25);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter, regenerateId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deleteOldSession_param = NULL, _0;
	zend_bool deleteOldSession;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &deleteOldSession_param);

	if (!deleteOldSession_param) {
		deleteOldSession = 1;
	} else {
		deleteOldSession = zephir_get_boolval(deleteOldSession_param);
	}


	ZVAL_BOOL(&_0, (deleteOldSession ? 1 : 0));
	ZEPHIR_CALL_FUNCTION(NULL, "session_regenerate_id", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Gets a session variable from an application context
 *
 * <code>
 * $session->get("auth", "yes");
 * </code>
 */
PHP_METHOD(Phalcon_Session_Adapter, get) {

	zend_bool remove;
	zval *index_param = NULL, *defaultValue = NULL, defaultValue_sub, *remove_param = NULL, *_SESSION, __$null, value, key, uniqueId;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&uniqueId);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &remove_param);

	zephir_get_strval(&index, index_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!remove_param) {
		remove = 0;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	zephir_read_property(&uniqueId, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		ZEPHIR_INIT_VAR(&key);
		ZEPHIR_CONCAT_VSV(&key, &uniqueId, "#", &index);
	} else {
		ZEPHIR_CPY_WRT(&key, &index);
	}
	ZEPHIR_OBS_VAR(&value);
	if (zephir_array_isset_fetch(&value, _SESSION, &key, 0 TSRMLS_CC)) {
		if (remove) {
			zephir_array_unset(_SESSION, &key, PH_SEPARATE);
		}
		RETURN_CCTOR(&value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets a session variable in an application context
 *
 *<code>
 * $session->set("auth", "yes");
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, set) {

	zval *index_param = NULL, *value, value_sub, *_SESSION, uniqueId, _0$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(&index, index_param);


	zephir_read_property(&uniqueId, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &uniqueId, "#", &index);
		zephir_array_update_zval(_SESSION, &_0$$3, value, PH_COPY | PH_SEPARATE);
		RETURN_MM_NULL();
	}
	zephir_array_update_zval(_SESSION, &index, value, PH_COPY | PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a session variable is set in an application context
 *
 *<code>
 * var_dump(
 *     $session->has("auth")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, has) {

	zval *index_param = NULL, *_SESSION, uniqueId, _0$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	zephir_read_property(&uniqueId, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &uniqueId, "#", &index);
		RETURN_MM_BOOL(zephir_array_isset(_SESSION, &_0$$3));
	}
	RETURN_MM_BOOL(zephir_array_isset(_SESSION, &index));

}

/**
 * Removes a session variable from an application context
 *
 * <code>
 * $session->remove("auth");
 * </code>
 */
PHP_METHOD(Phalcon_Session_Adapter, remove) {

	zval *index_param = NULL, *_SESSION, uniqueId, _0$$3;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	zephir_read_property(&uniqueId, this_ptr, SL("_uniqueId"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &uniqueId, "#", &index);
		zephir_array_unset(_SESSION, &_0$$3, PH_SEPARATE);
		RETURN_MM_NULL();
	}
	zephir_array_unset(_SESSION, &index, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns active session id
 *
 *<code>
 * echo $session->getId();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, getId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 27);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set the current session id
 *
 *<code>
 * $session->setId($id);
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, setId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(&id, id_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 27, &id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether the session has been started
 *
 *<code>
 * var_dump(
 *     $session->isStarted()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, isStarted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_started");

}

/**
 * Destroys the active session
 *
 *<code>
 * var_dump(
 *     $session->destroy()
 * );
 *
 * var_dump(
 *     $session->destroy(true)
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *removeData_param = NULL, __$true, __$false;
	zend_bool removeData;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &removeData_param);

	if (!removeData_param) {
		removeData = 0;
	} else {
		removeData = zephir_get_boolval(removeData_param);
	}


	if (removeData) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesessiondata", NULL, 0);
		zephir_check_call_status();
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 28);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the status of the current session.
 *
 *<code>
 * var_dump(
 *     $session->status()
 * );
 *
 * if ($session->status() !== $session::SESSION_ACTIVE) {
 *     $session->start();
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, status) {

	zval status;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 29);
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
 * Alias: Gets a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Sets a session variable in an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *value, value_sub;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &index, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Check whether a session variable is set in an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Removes a session variable from an application context
 *
 * <code>
 * unset($session->auth);
 * </code>
 */
PHP_METHOD(Phalcon_Session_Adapter, __unset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(&index, index_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "remove", NULL, 0, &index);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter, __destruct) {

	zval __$true, __$false, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_started"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 30);
		zephir_check_call_status();
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter, removeSessionData) {

	zend_string *_3$$4;
	zend_ulong _2$$4;
	zval *_SESSION = NULL, uniqueId, key, _0$$4, *_1$$4, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SL("_SESSION"));
	if (!_SESSION) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}

	ZEPHIR_OBS_VAR(&uniqueId);
	zephir_read_property(&uniqueId, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_SESSION)) {
		RETURN_MM_NULL();
	}
	if (!(ZEPHIR_IS_EMPTY(&uniqueId))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_is_iterable(_SESSION, 1, "phalcon/session/adapter.zep", 359);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_SESSION), _2$$4, _3$$4, _1$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$4);
			} else {
				ZVAL_LONG(&key, _2$$4);
			}
			ZEPHIR_INIT_NVAR(&_0$$4);
			ZVAL_COPY(&_0$$4, _1$$4);
			ZEPHIR_INIT_LNVAR(_4$$5);
			ZEPHIR_CONCAT_VS(&_4$$5, &uniqueId, "#");
			if (zephir_start_with(&key, &_4$$5, NULL)) {
				zephir_array_unset(_SESSION, &key, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_0$$4);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_INIT_NVAR(_SESSION);
		array_init(_SESSION);
	}
	ZEPHIR_MM_RESTORE();

}


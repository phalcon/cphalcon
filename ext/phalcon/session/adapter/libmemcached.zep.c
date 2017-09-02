
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Phalcon\Session\Adapter\Libmemcached
 *
 * This adapter store sessions in libmemcached
 *
 * <code>
 * use Phalcon\Session\Adapter\Libmemcached;
 *
 * $session = new Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             \Memcached::OPT_HASH       => \Memcached::HASH_MD5,
 *             \Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "lifetime" => 3600,
 *         "prefix"   => "my_",
 *     ]
 * );
 *
 * $session->start();
 *
 * $session->set("var", "some-value");
 *
 * echo $session->get("var");
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Libmemcached, phalcon, session_adapter_libmemcached, phalcon_session_adapter_ce, phalcon_session_adapter_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_libmemcached_ce, SL("_libmemcached"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_session_adapter_libmemcached_ce, SL("_lifetime"), 8600, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLibmemcached) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_libmemcached");

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLifetime) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lifetime");

}

/**
 * Phalcon\Session\Adapter\Libmemcached constructor
 *
 * @throws \Phalcon\Session\Exception
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct) {

	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, servers, client, lifetime, prefix, statsKey, persistentId, _0, _1, _2, _3, _5, _8;
	zval options, _4, _6, _7, _9, _10, _11, _12, _13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&statsKey);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_OBS_VAR(&servers);
	if (!(zephir_array_isset_string_fetch(&servers, &options, SL("servers"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "No servers given in options", "phalcon/session/adapter/libmemcached.zep", 76);
		return;
	}
	ZEPHIR_OBS_VAR(&client);
	if (!(zephir_array_isset_string_fetch(&client, &options, SL("client"), 0))) {
		ZEPHIR_INIT_NVAR(&client);
		ZVAL_NULL(&client);
	}
	ZEPHIR_OBS_VAR(&lifetime);
	if (!(zephir_array_isset_string_fetch(&lifetime, &options, SL("lifetime"), 0))) {
		ZEPHIR_INIT_NVAR(&lifetime);
		ZVAL_LONG(&lifetime, 8600);
	}
	ZVAL_LONG(&_0, 2592000);
	ZEPHIR_CALL_FUNCTION(&_1, "min", NULL, 407, &lifetime, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_lifetime"), &_1);
	ZEPHIR_OBS_VAR(&prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0))) {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_NULL(&prefix);
	}
	ZEPHIR_OBS_VAR(&statsKey);
	if (!(zephir_array_isset_string_fetch(&statsKey, &options, SL("statsKey"), 0))) {
		ZEPHIR_INIT_NVAR(&statsKey);
		ZVAL_STRING(&statsKey, "");
	}
	ZEPHIR_OBS_VAR(&persistentId);
	if (!(zephir_array_isset_string_fetch(&persistentId, &options, SL("persistent_id"), 0))) {
		ZEPHIR_INIT_NVAR(&persistentId);
		ZVAL_STRING(&persistentId, "phalcon-session");
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_4, SL("lifetime"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 309, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 5, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("client"), &client, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("prefix"), &prefix, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("statsKey"), &statsKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_6, SL("persistent_id"), &persistentId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 310, &_3, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_libmemcached"), &_2);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_7, this_ptr);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "open");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "close");
	zephir_array_fast_append(&_9, &_8);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_10, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "read");
	zephir_array_fast_append(&_10, &_8);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_11, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "write");
	zephir_array_fast_append(&_11, &_8);
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_12, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "destroy");
	zephir_array_fast_append(&_12, &_8);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_13, this_ptr);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "gc");
	zephir_array_fast_append(&_13, &_8);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 408, &_7, &_9, &_10, &_11, &_12, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, getThis(), "__construct", &_14, 0, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, _0, _1, _2;
	zval sessionId, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(&sessionId, sessionId_param);


	zephir_read_property(&_0, this_ptr, SL("_libmemcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("_lifetime"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &sessionId, &_2);
	zephir_check_call_status();
	zephir_get_strval(&_3, &_1);
	RETURN_CTOR(&_3);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, _0, _1;
	zval sessionId, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(&sessionId, sessionId_param);
	zephir_get_strval(&data, data_param);


	zephir_read_property(&_0, this_ptr, SL("_libmemcached"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("_lifetime"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "save", NULL, 0, &sessionId, &data, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, id, _1, _2, _3$$5, _4$$5;
	zval sessionId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionId_param);

	if (!sessionId_param) {
		ZEPHIR_INIT_VAR(&sessionId);
		ZVAL_STRING(&sessionId, "");
	} else {
		zephir_get_strval(&sessionId, sessionId_param);
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&sessionId, "")) {
		ZEPHIR_CALL_METHOD(&id, this_ptr, "getid", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&id, &sessionId);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesessiondata", NULL, 0);
	zephir_check_call_status();
	_0 = !(ZEPHIR_IS_EMPTY(&id));
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("_libmemcached"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2, &_1, "exists", NULL, 0, &id);
		zephir_check_call_status();
		_0 = zephir_is_true(&_2);
	}
	if (_0) {
		zephir_read_property(&_3$$5, this_ptr, SL("_libmemcached"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$5, &_3$$5, "delete", NULL, 0, &id);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(&_4$$5));
	}
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}



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
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Phalcon\Session\Adapter\Memcache
 *
 * This adapter store sessions in memcache
 *
 * <code>
 * use Phalcon\Session\Adapter\Memcache;
 *
 * $session = new Memcache(
 *     [
 *         "uniqueId"   => "my-private-app",
 *         "host"       => "127.0.0.1",
 *         "port"       => 11211,
 *         "persistent" => true,
 *         "lifetime"   => 3600,
 *         "prefix"     => "my_",
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
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Memcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Memcache, phalcon, session_adapter_memcache, phalcon_session_adapter_ce, phalcon_session_adapter_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_session_adapter_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_session_adapter_memcache_ce, SL("_lifetime"), 8600, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, getMemcache) {

	

	RETURN_MEMBER(getThis(), "_memcache");

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, getLifetime) {

	

	RETURN_MEMBER(getThis(), "_lifetime");

}

/**
 * Phalcon\Session\Adapter\Memcache constructor
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, __construct) {

	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *lifetime = NULL, *_3, *_4, *_6, *_8 = NULL, *_0$$3, *_1$$4, *_2$$5;
	zval *options = NULL, *_5, *_7, *_9, *_10, *_11, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	if (!(zephir_array_isset_string(options, SS("host")))) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_LONG(_1$$4, 11211);
		zephir_array_update_string(&options, SL("port"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_LONG(_2$$5, 0);
		zephir_array_update_string(&options, SL("persistent"), &_2$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(lifetime);
	if (zephir_array_isset_string_fetch(&lifetime, options, SS("lifetime"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_lifetime"), lifetime TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_3);
	object_init_ex(_3, phalcon_cache_backend_memcache_ce);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("_lifetime"), PH_NOISY_CC);
	zephir_array_update_string(&_5, SL("lifetime"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 350, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 353, _4, options);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_memcache"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "open", 1);
	zephir_array_fast_append(_7, _8);
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_9, this_ptr);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "close", 1);
	zephir_array_fast_append(_9, _8);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, this_ptr);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "read", 1);
	zephir_array_fast_append(_10, _8);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, this_ptr);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "write", 1);
	zephir_array_fast_append(_11, _8);
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_12, this_ptr);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "destroy", 1);
	zephir_array_fast_append(_12, _8);
	ZEPHIR_INIT_VAR(_13);
	zephir_create_array(_13, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_13, this_ptr);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_STRING(_8, "gc", 1);
	zephir_array_fast_append(_13, _8);
	ZEPHIR_CALL_FUNCTION(NULL, "session_set_save_handler", NULL, 450, _7, _9, _10, _11, _12, _13);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_memcache_ce, getThis(), "__construct", &_14, 451, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, open) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Memcache, close) {

	

	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *_0, *_1 = NULL, *_2;
	zval *sessionId = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId_param);

	zephir_get_strval(sessionId, sessionId_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "get", NULL, 0, sessionId, _2);
	zephir_check_call_status();
	zephir_get_strval(_3, _1);
	RETURN_CTOR(_3);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId_param = NULL, *data_param = NULL, *_0, *_1;
	zval *sessionId = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId_param, &data_param);

	zephir_get_strval(sessionId, sessionId_param);
	zephir_get_strval(data, data_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "save", NULL, 0, sessionId, data, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, destroy) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId = NULL, *id = NULL, *_1, *_2 = NULL, *_3$$5, *_4$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionId);

	if (!sessionId) {
		sessionId = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(sessionId) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&id, this_ptr, "getid", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(id, sessionId);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "removesessiondata", NULL, 0);
	zephir_check_call_status();
	_0 = !(ZEPHIR_IS_EMPTY(id));
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_2, _1, "exists", NULL, 0, id);
		zephir_check_call_status();
		_0 = zephir_is_true(_2);
	}
	if (_0) {
		_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$5, _3$$5, "delete", NULL, 0, id);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(_4$$5));
	}
	RETURN_MM_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter_Memcache, gc) {

	

	RETURN_BOOL(1);

}


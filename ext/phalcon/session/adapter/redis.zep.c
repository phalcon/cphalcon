
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Redis;
 *
 * $session = new Manager();
 * $adapter = new Redis(
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * $session->setHandler($adapter);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Redis, phalcon, session_adapter_redis, phalcon_session_adapter_noop_ce, phalcon_session_adapter_redis_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct) {

	zval _10;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_3 = NULL;
	zval options, *options_param = NULL, params, _1, _2, _4, _5, _6, _7, _8, _9, _11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_redis_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_1);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "host");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "127.0.0.1");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_helper_arr_ce, "get", &_3, 155, &options, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("host"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "port");
	ZVAL_LONG(&_1, 6379);
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_helper_arr_ce, "get", &_3, 155, &options, &_4, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("port"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "index");
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_CE_STATIC(&_7, phalcon_helper_arr_ce, "get", &_3, 155, &options, &_4, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("index"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "persistent");
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_CE_STATIC(&_8, phalcon_helper_arr_ce, "get", &_3, 155, &options, &_4, &_1);
	zephir_check_call_status();
	zephir_array_update_string(&params, SL("persistent"), &_8, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "ttl");
	ZEPHIR_CALL_CE_STATIC(&_9, phalcon_helper_arr_ce, "get", &_3, 155, &options, &_4, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ttl"), &_9);
	ZEPHIR_INIT_NVAR(&_4);
	object_init_ex(&_4, phalcon_cache_backend_redis_ce);
	ZEPHIR_INIT_NVAR(&_5);
	object_init_ex(&_5, phalcon_cache_frontend_none_ce);
	if (zephir_has_constructor(&_5 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_create_array(&_10, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_11);
		zephir_read_property(&_11, this_ptr, SL("ttl"), PH_NOISY_CC);
		zephir_array_update_string(&_10, SL("lifetime"), &_11, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 0, &_10);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 335, &_5, &params);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("connection"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Redis, destroy) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, name, _1, _2, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&name, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	_0 = 1 != ZEPHIR_IS_EMPTY(&name);
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2, &_1, "exists", NULL, 0, &name);
		zephir_check_call_status();
		_0 = zephir_is_true(&_2);
	}
	if (_0) {
		zephir_read_property(&_3$$3, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "delete", NULL, 0, &name);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_get_boolval(&_4$$3));
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Redis, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, name, data, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	ZEPHIR_CALL_METHOD(&name, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &name, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&data);

}

PHP_METHOD(Phalcon_Session_Adapter_Redis, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *data, data_sub, name, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &data);



	ZEPHIR_CALL_METHOD(&name, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "save", NULL, 0, &name, data, &_1);
	zephir_check_call_status();
	RETURN_MM();

}


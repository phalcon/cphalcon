
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
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
 * use Phalcon\Session\Adapter\Libmemcached
 *
 * $session = new Manager();
 * $adapter = new Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *              Memcached::OPT_HASH       => Memcached::HASH_MD5,
 *              Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "ttl"    => 3600,
 *         "prefix" => "my_",
 *     ]
 * );
 *
 * $session->setAdapter($adapter);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Libmemcached, phalcon, session_adapter_libmemcached, phalcon_session_adapter_noop_ce, phalcon_session_adapter_libmemcached_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct) {

	zval _7, _9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options, *options_param = NULL, client, persistentId, prefix, servers, statsKey, ttl, _1, _2, _3, _4, _5, _6, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&client);
	ZVAL_UNDEF(&persistentId);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&servers);
	ZVAL_UNDEF(&statsKey);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_libmemcached_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_1);
	ZEPHIR_OBS_VAR(&servers);
	if (!(zephir_array_isset_string_fetch(&servers, &options, SL("servers"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "No 'servers' specified in the options", "phalcon/session/adapter/libmemcached.zep", 62);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "client");
	ZEPHIR_CALL_METHOD(&client, this_ptr, "arraygetdefault", NULL, 0, &options, &_3, &_2);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "ttl");
	ZEPHIR_CALL_METHOD(&ttl, this_ptr, "arraygetdefault", NULL, 0, &options, &_3, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "statsKey");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_METHOD(&statsKey, this_ptr, "arraygetdefault", NULL, 0, &options, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "persistent_id");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "phalcon-session");
	ZEPHIR_CALL_METHOD(&persistentId, this_ptr, "arraygetdefault", NULL, 0, &options, &_3, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_5, 2592000);
	ZEPHIR_CALL_FUNCTION(&_6, "min", NULL, 412, &ttl, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ttl"), &_6);
	ZEPHIR_INIT_NVAR(&_3);
	object_init_ex(&_3, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_NVAR(&_4);
	object_init_ex(&_4, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("ttl"), PH_NOISY_CC);
	zephir_array_update_string(&_7, SL("lifetime"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 318, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 5, 0 TSRMLS_CC);
	zephir_array_update_string(&_9, SL("servers"), &servers, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("client"), &client, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("prefix"), &prefix, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("statsKey"), &statsKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("persistent_id"), &persistentId, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 319, &_4, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("connection"), &_3);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy) {

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

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read) {

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

PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write) {

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
	ZEPHIR_CALL_METHOD(NULL, &_0, "save", NULL, 0, &name, data, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


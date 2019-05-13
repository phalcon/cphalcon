
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_SerializerFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Storage, SerializerFactory, phalcon, storage_serializerfactory, phalcon_storage_serializerfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_serializerfactory_ce, SL("mapper"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_serializerfactory_ce, SL("services"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_storage_serializerfactory_ce->create_object = zephir_init_properties_Phalcon_Storage_SerializerFactory;
	return SUCCESS;

}

/**
 * SerializerFactory constructor.
 *
 * @param array services
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, __construct) {

	zend_string *_4;
	zend_ulong _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL, helpers, name, service, _0, *_1, _2, _5$$3, _6$$4;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&helpers);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_INIT_VAR(&helpers);
	zephir_create_array(&helpers, 6, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&helpers, SL("base64"), SL("\\Phalcon\\Storage\\Serializer\\Base64"));
	add_assoc_stringl_ex(&helpers, SL("igbinary"), SL("\\Phalcon\\Storage\\Serializer\\Igbinary"));
	add_assoc_stringl_ex(&helpers, SL("json"), SL("\\Phalcon\\Storage\\Serializer\\Json"));
	add_assoc_stringl_ex(&helpers, SL("msgpack"), SL("\\Phalcon\\Storage\\Serializer\\Msgpack"));
	add_assoc_stringl_ex(&helpers, SL("none"), SL("\\Phalcon\\Storage\\Serializer\\None"));
	add_assoc_stringl_ex(&helpers, SL("php"), SL("\\Phalcon\\Storage\\Serializer\\Php"));
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &helpers, &services TSRMLS_CC);
	ZEPHIR_CPY_WRT(&helpers, &_0);
	zephir_is_iterable(&helpers, 0, "phalcon/Storage/SerializerFactory.zep", 51);
	if (Z_TYPE_P(&helpers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&helpers), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _1);
			zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
			zephir_read_property(&_5$$3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_5$$3, &name, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &helpers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &helpers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &helpers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &helpers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
				zephir_read_property(&_6$$4, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_6$$4, &name, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &helpers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * @param string name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_SerializerFactory, newInstance) {

	zend_class_entry *_7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, definition, _0, _3, _8, _9, _1$$3, _4$$4, _5$$4, _6$$4;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_storage_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service ", &name, " is not registered");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Storage/SerializerFactory.zep", 64 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &name))) {
		zephir_read_property(&_4$$4, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_4$$4, &name, PH_NOISY | PH_READONLY, "phalcon/Storage/SerializerFactory.zep", 68 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$4);
		zephir_fetch_safe_class(&_6$$4, &definition);
		_7$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$4), Z_STRLEN_P(&_6$$4), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_5$$4, _7$$4);
		if (zephir_has_constructor(&_5$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &_5$$4);
		ZEPHIR_INIT_NVAR(&_5$$4);
	}
	zephir_read_property(&_8, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_9, &_8, &name, PH_NOISY | PH_READONLY, "phalcon/Storage/SerializerFactory.zep", 72 TSRMLS_CC);
	RETURN_CTOR(&_9);

}

zend_object *zephir_init_properties_Phalcon_Storage_SerializerFactory(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("services"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("mapper"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}


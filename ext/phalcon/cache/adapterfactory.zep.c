
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Factory to create Cache adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_AdapterFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache, AdapterFactory, phalcon, cache_adapterfactory, phalcon_factory_abstractfactory_ce, phalcon_cache_adapterfactory_method_entry, 0);

	/**
	 * @var SerializerFactory
	 */
	zend_declare_property_null(phalcon_cache_adapterfactory_ce, SL("serializerFactory"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *factory = NULL, factory_sub, *services_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &factory, &services_param);

	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	zephir_update_property_zval(this_ptr, SL("serializerFactory"), factory);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, newInstance) {

	zend_class_entry *_4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *options_param = NULL, definition, _0, _6, _7, _1$$3, _2$$3, _3$$3, _5$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &options_param);

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
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY | PH_READONLY, "phalcon/Cache/AdapterFactory.zep", 48 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fetch_safe_class(&_3$$3, &definition);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_4$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_2$$3, _4$$3);
		if (zephir_has_constructor(&_2$$3 TSRMLS_CC)) {
			zephir_read_property(&_5$$3, this_ptr, SL("serializerFactory"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_5$$3, &options);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &_2$$3);
	}
	zephir_read_property(&_6, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &name, PH_NOISY | PH_READONLY, "phalcon/Cache/AdapterFactory.zep", 52 TSRMLS_CC);
	RETURN_CTOR(&_7);

}

/**
 * Returns the available adapters
 */
PHP_METHOD(Phalcon_Cache_AdapterFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("apcu"), SL("\\Phalcon\\Cache\\Adapter\\Apcu"));
	add_assoc_stringl_ex(return_value, SL("libmemcached"), SL("\\Phalcon\\Cache\\Adapter\\Libmemcached"));
	add_assoc_stringl_ex(return_value, SL("memory"), SL("\\Phalcon\\Cache\\Adapter\\Memory"));
	add_assoc_stringl_ex(return_value, SL("redis"), SL("\\Phalcon\\Cache\\Adapter\\Redis"));
	add_assoc_stringl_ex(return_value, SL("stream"), SL("\\Phalcon\\Cache\\Adapter\\Stream"));
	return;

}


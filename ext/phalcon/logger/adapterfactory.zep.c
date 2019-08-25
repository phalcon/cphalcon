
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, AdapterFactory, phalcon, logger_adapterfactory, phalcon_factory_abstractfactory_ce, phalcon_logger_adapterfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Create a new instance of the adapter
 */
PHP_METHOD(Phalcon_Logger_AdapterFactory, newInstance) {

	zend_class_entry *_4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *name_param = NULL, *fileName_param = NULL, *options_param = NULL, definition, _0, _5, _6, _1$$3, _2$$3, _3$$3;
	zval name, fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &fileName_param, &options_param);

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
	if (UNEXPECTED(Z_TYPE_P(fileName_param) != IS_STRING && Z_TYPE_P(fileName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fileName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(fileName_param) == IS_STRING)) {
		zephir_get_strval(&fileName, fileName_param);
	} else {
		ZEPHIR_INIT_VAR(&fileName);
		ZVAL_EMPTY_STRING(&fileName);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY | PH_READONLY, "phalcon/Logger/AdapterFactory.zep", 39 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fetch_safe_class(&_3$$3, &definition);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_4$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_2$$3, _4$$3);
		if (zephir_has_constructor(&_2$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &fileName, &options);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("services"), &name, &_2$$3);
	}
	zephir_read_property(&_5, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name, PH_NOISY | PH_READONLY, "phalcon/Logger/AdapterFactory.zep", 43 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

PHP_METHOD(Phalcon_Logger_AdapterFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("noop"), SL("\\Phalcon\\Logger\\Adapter\\Noop"));
	add_assoc_stringl_ex(return_value, SL("stream"), SL("\\Phalcon\\Logger\\Adapter\\Stream"));
	add_assoc_stringl_ex(return_value, SL("syslog"), SL("\\Phalcon\\Logger\\Adapter\\Syslog"));
	return;

}


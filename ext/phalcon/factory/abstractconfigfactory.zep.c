
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Factory_AbstractConfigFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Factory, AbstractConfigFactory, phalcon, factory_abstractconfigfactory, phalcon_factory_abstractconfigfactory_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Checks the config if it is a valid object
 */
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, checkConfig)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, _1$$3, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Config must be array or Phalcon\\Config\\Config object");
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getexception", NULL, 0, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Factory/AbstractConfigFactory.zep", 29);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(config, 1, 0);
	RETURN_MM();
}

/**
 * Checks if the config has "adapter"
 */
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, checkConfigElement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element, _1$$3;
	zval *config_param = NULL, *element_param = NULL, _0$$3;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(config)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &config_param, &element_param);
	zephir_get_arrval(&config, config_param);
	zephir_get_strval(&element, element_param);


	if (UNEXPECTED(!(zephir_array_isset(&config, &element)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "You must provide '", &element, "' option in factory config parameter.");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getexception", NULL, 0, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Factory/AbstractConfigFactory.zep", 43);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&config);
}

/**
 * Returns the exception object for the child class
 */
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, getException)
{
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, exception, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);


	ZEPHIR_CALL_METHOD(&exception, this_ptr, "getexceptionclass", NULL, 0);
	zephir_check_call_status();
	zephir_fetch_safe_class(&_0, &exception);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &message);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Exception");
}



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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Loads Logger Adapter class using 'adapter' option
 *
 *<code>
 *  use Phalcon\Logger\Factory;
 *
 *  $options = [
 *      'adapters' => [
 *          'type' => 'stream',
 *          'name' => 'log.txt',
 *      ]
 *  ];
 *
 *  $logger = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Logger, Factory, phalcon, logger_factory, phalcon_factory_ce, phalcon_logger_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Logger_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Logger\\Adapter");
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, &_0, config);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Logger_Factory, loadClass) {

	zend_class_entry *_8$$10;
	zend_string *_5;
	zend_ulong _4;
	zend_bool _0;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objectName_param = NULL, *config = NULL, config_sub, adapter, adapterName, adapters, className, element, key, logger, loggerName, name, type, *_2, *_3, _1$$3, _6$$10, _7$$10;
	zval objectName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objectName);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&adapterName);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&logger);
	ZVAL_UNDEF(&loggerName);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &objectName_param, &config);

	zephir_get_strval(&objectName, objectName_param);
	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/logger/factory.zep", 53);
		return;
	}
	ZEPHIR_OBS_VAR(&loggerName);
	if (!(zephir_array_isset_string_fetch(&loggerName, config, SL("name"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide the 'name' option in factory config parameter.", "phalcon/logger/factory.zep", 57);
		return;
	}
	ZEPHIR_OBS_VAR(&adapters);
	if (!(zephir_array_isset_string_fetch(&adapters, config, SL("adapters"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide the 'adapters' option in factory config parameter.", "phalcon/logger/factory.zep", 61);
		return;
	}
	zephir_is_iterable(&adapters, 0, "phalcon/logger/factory.zep", 80);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&adapters), _2)
	{
		ZEPHIR_INIT_NVAR(&adapter);
		ZVAL_COPY(&adapter, _2);
		ZEPHIR_OBS_NVAR(&name);
		if (!(zephir_array_isset_string_fetch(&name, &adapter, SL("name"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "The adapters section of your configuration is missing the 'name' option", "phalcon/logger/factory.zep", 69);
			return;
		}
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_string_fetch(&type, &adapter, SL("adapter"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "The adapters section of your configuration is missing the 'adapter' option", "phalcon/logger/factory.zep", 73);
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&adapter);
	ZEPHIR_INIT_VAR(&logger);
	object_init_ex(&logger, phalcon_logger_ce);
	ZEPHIR_CALL_METHOD(NULL, &logger, "__construct", NULL, 299, &loggerName);
	zephir_check_call_status();
	zephir_is_iterable(&adapters, 0, "phalcon/logger/factory.zep", 92);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&adapters), _4, _5, _3)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_5 != NULL) { 
			ZVAL_STR_COPY(&key, _5);
		} else {
			ZVAL_LONG(&key, _4);
		}
		ZEPHIR_INIT_NVAR(&element);
		ZVAL_COPY(&element, _3);
		ZEPHIR_OBS_NVAR(&name);
		zephir_array_fetch_string(&name, &element, SL("name"), PH_NOISY, "phalcon/logger/factory.zep", 83 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &element, SL("adapter"), PH_NOISY, "phalcon/logger/factory.zep", 84 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&adapterName);
		ZEPHIR_CONCAT_SV(&adapterName, "A", &key);
		ZEPHIR_INIT_NVAR(&_6$$10);
		zephir_camelize(&_6$$10, &type, NULL  );
		ZEPHIR_INIT_NVAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &objectName, "\\", &_6$$10);
		ZEPHIR_INIT_NVAR(&adapter);
		zephir_fetch_safe_class(&_7$$10, &className);
		_8$$10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7$$10), Z_STRLEN_P(&_7$$10), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&adapter, _8$$10);
		if (zephir_has_constructor(&adapter TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &adapter, "__construct", NULL, 0, &name);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &logger, "addadapter", &_9, 300, &adapterName, &adapter);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&logger);

}



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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Loads Config Adapter class using 'adapter' option, if no extension is provided it will be added to filePath
 *
 *<code>
 * use Phalcon\Config\Factory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 * $config = Factory::load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Factory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, Factory, phalcon, config_factory, phalcon_factory_ce, phalcon_config_factory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Config_Factory, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\Config\\Adapter");
	ZEPHIR_RETURN_CALL_SELF("loadclass", NULL, 0, &_0, config);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Phalcon_Config_Factory, loadClass) {

	zend_class_entry *_16$$8, *_12$$11, *_14$$13;
	zend_bool _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespace_param = NULL, *config = NULL, config_sub, adapter, className, mode, callbacks, filePath, extension, oldConfig, _0$$3, _1$$3, _2$$3, _3$$3, _5$$5, _6$$8, _7$$8, _8$$8, _15$$8, _9$$9, _10$$9, _11$$11, _13$$13;
	zval namespace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespace);
	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&callbacks);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&oldConfig);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &namespace_param, &config);

	zephir_get_strval(&namespace, namespace_param);
	ZEPHIR_SEPARATE_PARAM(config);


	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(&oldConfig, config);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, ".");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strrchr", NULL, 125, config, &_0$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_INIT_VAR(&extension);
		zephir_substr(&extension, &_1$$3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (ZEPHIR_IS_EMPTY(&extension)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You need to provide extension in file path", "phalcon/config/factory.zep", 49);
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$3, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(config, &_3$$3);
	}
	_4 = Z_TYPE_P(config) == IS_OBJECT;
	if (_4) {
		_4 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD(&_5$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_5$$5);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/config/factory.zep", 63);
		return;
	}
	ZEPHIR_OBS_VAR(&filePath);
	if (!(zephir_array_isset_string_fetch(&filePath, config, SL("filePath"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/config/factory.zep", 67);
		return;
	}
	ZEPHIR_OBS_VAR(&adapter);
	if (zephir_array_isset_string_fetch(&adapter, config, SL("adapter"), 0)) {
		ZEPHIR_INIT_VAR(&_6$$8);
		zephir_camelize(&_6$$8, &adapter, NULL  );
		ZEPHIR_INIT_VAR(&className);
		ZEPHIR_CONCAT_VSV(&className, &namespace, "\\", &_6$$8);
		ZEPHIR_INIT_VAR(&_7$$8);
		ZVAL_STRING(&_7$$8, ".");
		ZEPHIR_INIT_VAR(&_8$$8);
		zephir_fast_strpos(&_8$$8, &filePath, &_7$$8, 0 );
		if (!(zephir_is_true(&_8$$8))) {
			ZEPHIR_CALL_FUNCTION(&_9$$9, "lcfirst", NULL, 53, &adapter);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_10$$9);
			ZEPHIR_CONCAT_VSV(&_10$$9, &filePath, ".", &_9$$9);
			ZEPHIR_CPY_WRT(&filePath, &_10$$9);
		}
		if (ZEPHIR_IS_STRING(&className, "Phalcon\\Config\\Adapter\\Ini")) {
			ZEPHIR_OBS_VAR(&mode);
			if (zephir_array_isset_string_fetch(&mode, config, SL("mode"), 0)) {
				zephir_fetch_safe_class(&_11$$11, &className);
				_12$$11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_11$$11), Z_STRLEN_P(&_11$$11), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(return_value, _12$$11);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath, &mode);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		} else if (ZEPHIR_IS_STRING(&className, "Phalcon\\Config\\Adapter\\Yaml")) {
			ZEPHIR_OBS_VAR(&callbacks);
			if (zephir_array_isset_string_fetch(&callbacks, config, SL("callbacks"), 0)) {
				zephir_fetch_safe_class(&_13$$13, &className);
				_14$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13$$13), Z_STRLEN_P(&_13$$13), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(return_value, _14$$13);
				if (zephir_has_constructor(return_value TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath, &callbacks);
					zephir_check_call_status();
				}
				RETURN_MM();
			}
		}
		zephir_fetch_safe_class(&_15$$8, &className);
		_16$$8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_15$$8), Z_STRLEN_P(&_15$$8), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(return_value, _16$$8);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/config/factory.zep", 89);
	return;

}


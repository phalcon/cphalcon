
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * Loads Config Adapter class using 'adapter' option, if no extension is
 * provided it will be added to filePath
 *
 *<code>
 * use Phalcon\Config\ConfigFactory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 * $config = (new ConfigFactory())->load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Config, ConfigFactory, phalcon, config_configfactory, phalcon_config_configfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * @param \Phalcon\Config|array config
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, load) {

	zend_class_entry *_15, *_11$$11, *_13$$13;
	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, adapter, className, mode, callbacks, filePath, extension, oldConfig, _5, _6, _7, _14, _0$$3, _1$$3, _2$$3, _4$$5, _8$$9, _9$$9, _10$$11, _12$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&callbacks);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&oldConfig);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(&oldConfig, config);
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, ".");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "strrchr", NULL, 145, config, &_0$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_INIT_VAR(&extension);
		zephir_substr(&extension, &_1$$3, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&extension))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You need to provide extension in file path", "phalcon/Config/ConfigFactory.zep", 46);
			return;
		}
		ZEPHIR_INIT_NVAR(config);
		zephir_create_array(config, 2, 0 TSRMLS_CC);
		zephir_array_update_string(config, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(config, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
	}
	_3 = Z_TYPE_P(config) == IS_OBJECT;
	if (_3) {
		_3 = zephir_instance_of_ev(config, phalcon_config_ce TSRMLS_CC);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_4$$5);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/Config/ConfigFactory.zep", 62);
		return;
	}
	ZEPHIR_OBS_VAR(&filePath);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&filePath, config, SL("filePath"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 68);
		return;
	}
	ZEPHIR_OBS_VAR(&adapter);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&adapter, config, SL("adapter"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 74);
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_camelize(&_5, &adapter, NULL  );
	ZEPHIR_INIT_VAR(&className);
	ZEPHIR_CONCAT_SV(&className, "Phalcon\\Config\\Adapter\\", &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, ".");
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strpos(&_7, &filePath, &_6, 0 );
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_FUNCTION(&_8$$9, "lcfirst", NULL, 68, &adapter);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$9);
		ZEPHIR_CONCAT_VSV(&_9$$9, &filePath, ".", &_8$$9);
		ZEPHIR_CPY_WRT(&filePath, &_9$$9);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&className, "Phalcon\\Config\\Adapter\\Ini")) {
		if (zephir_array_isset_string_fetch(&mode, config, SL("mode"), 1)) {
			zephir_fetch_safe_class(&_10$$11, &className);
			_11$$11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10$$11), Z_STRLEN_P(&_10$$11), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _11$$11);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath, &mode);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	} else if (ZEPHIR_IS_STRING_IDENTICAL(&className, "Phalcon\\Config\\Adapter\\Yaml")) {
		ZEPHIR_OBS_VAR(&callbacks);
		if (zephir_array_isset_string_fetch(&callbacks, config, SL("callbacks"), 0)) {
			zephir_fetch_safe_class(&_12$$13, &className);
			_13$$13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_12$$13), Z_STRLEN_P(&_12$$13), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(return_value, _13$$13);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath, &callbacks);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	}
	zephir_fetch_safe_class(&_14, &className);
	_15 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_14), Z_STRLEN_P(&_14), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _15);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &filePath);
		zephir_check_call_status();
	}
	RETURN_MM();

}


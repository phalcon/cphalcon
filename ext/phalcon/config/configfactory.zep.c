
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"
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
 *
 * $config = (new ConfigFactory())->load($options);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, ConfigFactory, phalcon, config_configfactory, phalcon_factory_abstractfactory_ce, phalcon_config_configfactory_method_entry, 0);

	return SUCCESS;

}

/**
 * ConfigFactory constructor.
 *
 * @param array services
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, __construct) {

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
		zephir_get_arrval(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Load a config to create a new instance
 *
 * @param $config
 *
 * @return object
 * @throws Exception
 * @throws FactoryException
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, load) {

	zend_bool _2;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, adapter, extension, first, oldConfig, second, _4, _5, _6, _9, _10, _0$$3, _1$$3, _3$$5, _7$$9, _8$$9, _12$$10, _13$$10, _14$$11, _15$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&oldConfig);
	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(&oldConfig, config);
		ZVAL_LONG(&_0$$3, 4);
		ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 95, config, &_0$$3);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&extension))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You need to provide the extension in the file path", "phalcon/Config/ConfigFactory.zep", 70);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_1$$3, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$3, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	_2 = Z_TYPE_P(config) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(config, phalcon_config_config_ce TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_3$$5);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Config must be array or Phalcon\\Config\\Config object", "phalcon/Config/ConfigFactory.zep", 86);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("filePath"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 92);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("adapter"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 98);
		return;
	}
	zephir_array_fetch_string(&_4, config, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 101 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fast_strtolower(&adapter, &_4);
	ZEPHIR_OBS_VAR(&first);
	zephir_array_fetch_string(&first, config, SL("filePath"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 102 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&second);
	ZVAL_NULL(&second);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ".");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strpos(&_6, &first, &_5, 0 );
	if (!(zephir_is_true(&_6))) {
		ZEPHIR_CALL_FUNCTION(&_7$$9, "lcfirst", NULL, 82, &adapter);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_CONCAT_VSV(&_8$$9, &first, ".", &_7$$9);
		ZEPHIR_CPY_WRT(&first, &_8$$9);
	}
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_STRING(&_9, "ini");
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "yaml");
	if (ZEPHIR_IS_IDENTICAL(&_9, &adapter)) {
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "mode");
		ZVAL_LONG(&_13$$10, 1);
		ZEPHIR_CALL_CE_STATIC(&second, phalcon_helper_arr_ce, "get", &_11, 8, config, &_12$$10, &_13$$10);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_IDENTICAL(&_10, &adapter)) {
		ZEPHIR_INIT_VAR(&_14$$11);
		array_init(&_14$$11);
		ZEPHIR_INIT_VAR(&_15$$11);
		ZVAL_STRING(&_15$$11, "callbacks");
		ZEPHIR_CALL_CE_STATIC(&second, phalcon_helper_arr_ce, "get", &_11, 8, config, &_15$$11, &_14$$11);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &first, &second);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @param string $name
 * @param string $fileName
 * @param null   $params
 *
 * @return object
 * @throws FactoryException
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, newInstance) {

	zend_class_entry *_7$$4, *_10$$5;
	zend_bool _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *fileName_param = NULL, *params = NULL, params_sub, __$null, definition, _0, _11, _12, _1$$3, _2$$3, _4$$3, _5$$4, _6$$4, _8$$5, _9$$5;
	zval name, fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &fileName_param, &params);

	zephir_get_strval(&name, name_param);
	zephir_get_strval(&fileName, fileName_param);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkservice", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		zephir_read_property(&_1$$3, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&definition, &_1$$3, &name, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 133 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "json");
		_3$$3 = ZEPHIR_IS_IDENTICAL(&_2$$3, &name);
		if (!(_3$$3)) {
			ZEPHIR_SINIT_VAR(_4$$3);
			ZVAL_STRING(&_4$$3, "php");
			_3$$3 = ZEPHIR_IS_IDENTICAL(&_4$$3, &name);
		}
		if (_3$$3) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_fetch_safe_class(&_6$$4, &definition);
			_7$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6$$4), Z_STRLEN_P(&_6$$4), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(&_5$$4, _7$$4);
			if (zephir_has_constructor(&_5$$4 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 0, &fileName);
				zephir_check_call_status();
			}
			zephir_update_property_array(this_ptr, SL("services"), &name, &_5$$4);
		} else {
			ZEPHIR_INIT_VAR(&_8$$5);
			zephir_fetch_safe_class(&_9$$5, &definition);
			_10$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_9$$5), Z_STRLEN_P(&_9$$5), ZEND_FETCH_CLASS_AUTO);
			object_init_ex(&_8$$5, _10$$5);
			if (zephir_has_constructor(&_8$$5 TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 0, &fileName, params);
				zephir_check_call_status();
			}
			zephir_update_property_array(this_ptr, SL("services"), &name, &_8$$5);
		}
	}
	zephir_read_property(&_11, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_12, &_11, &name, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 142 TSRMLS_CC);
	RETURN_CTOR(&_12);

}

/**
 * Returns the adapters for the factory
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getAdapters) {

	zval *this_ptr = getThis();


	zephir_create_array(return_value, 5, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("grouped"), SL("\\Phalcon\\Config\\Adapter\\Grouped"));
	add_assoc_stringl_ex(return_value, SL("ini"), SL("\\Phalcon\\Config\\Adapter\\Ini"));
	add_assoc_stringl_ex(return_value, SL("json"), SL("\\Phalcon\\Config\\Adapter\\Json"));
	add_assoc_stringl_ex(return_value, SL("php"), SL("\\Phalcon\\Config\\Adapter\\Php"));
	add_assoc_stringl_ex(return_value, SL("yaml"), SL("\\Phalcon\\Config\\Adapter\\Yaml"));
	return;

}


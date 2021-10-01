
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Loads Config Adapter class using 'adapter' option, if no extension is
 * provided it will be added to filePath
 *
 *```php
 * use Phalcon\Config\ConfigFactory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 *
 * $config = (new ConfigFactory())->load($options);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, ConfigFactory, phalcon, config_configfactory, phalcon_factory_abstractfactory_ce, phalcon_config_configfactory_method_entry, 0);

	zend_declare_property_string(phalcon_config_configfactory_ce, SL("exception"), "Phalcon\\Config\\Exception", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * ConfigFactory constructor.
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(services)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
 * @param string|array|\Phalcon\Config config = [
 *      'adapter' => 'ini',
 *      'filePath' => 'config.ini',
 *      'mode' => null,
 *      'callbacks' => null
 * ]
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, load)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);


	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(&oldConfig, config);
		ZVAL_LONG(&_0$$3, 4);
		ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 110, config, &_0$$3);
		zephir_check_call_status();
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&extension))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You need to provide the extension in the file path", "phalcon/Config/ConfigFactory.zep", 66);
			return;
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		zephir_array_update_string(&_1$$3, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$3, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	_2 = Z_TYPE_P(config) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&_3$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_3$$5);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/Config/ConfigFactory.zep", 82);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("filePath"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 88);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("adapter"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 94);
		return;
	}
	zephir_array_fetch_string(&_4, config, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 97);
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fast_strtolower(&adapter, &_4);
	ZEPHIR_OBS_VAR(&first);
	zephir_array_fetch_string(&first, config, SL("filePath"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 98);
	ZEPHIR_INIT_VAR(&second);
	ZVAL_NULL(&second);
	ZVAL_LONG(&_5, 4);
	ZEPHIR_CALL_FUNCTION(&_6, "pathinfo", NULL, 110, &first, &_5);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&_6)) {
		ZEPHIR_CALL_FUNCTION(&_7$$9, "lcfirst", NULL, 96, &adapter);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$9);
		ZEPHIR_CONCAT_VSV(&_8$$9, &first, ".", &_7$$9);
		ZEPHIR_CPY_WRT(&first, &_8$$9);
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "ini");
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "yaml");
	if (ZEPHIR_IS_IDENTICAL(&_9, &adapter)) {
		ZEPHIR_INIT_VAR(&_12$$10);
		ZVAL_STRING(&_12$$10, "mode");
		ZVAL_LONG(&_13$$10, 1);
		ZEPHIR_CALL_CE_STATIC(&second, phalcon_helper_arr_ce, "get", &_11, 10, config, &_12$$10, &_13$$10);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_IDENTICAL(&_10, &adapter)) {
		ZEPHIR_INIT_VAR(&_14$$11);
		array_init(&_14$$11);
		ZEPHIR_INIT_VAR(&_15$$11);
		ZVAL_STRING(&_15$$11, "callbacks");
		ZEPHIR_CALL_CE_STATIC(&second, phalcon_helper_arr_ce, "get", &_11, 10, config, &_15$$11, &_14$$11);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &first, &second);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a new Config instance
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, newInstance)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *fileName_param = NULL, *params = NULL, params_sub, __$null, definition, options, _0, _2;
	zval name, fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR(fileName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &fileName_param, &params);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&fileName, fileName_param);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}


	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&options);
	array_init(&options);
	zephir_array_append(&options, &fileName, PH_SEPARATE, "phalcon/Config/ConfigFactory.zep", 123);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "json");
	_1 = !ZEPHIR_IS_IDENTICAL(&_0, &name);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "php");
		_1 = !ZEPHIR_IS_IDENTICAL(&_2, &name);
	}
	if (_1) {
		zephir_array_append(&options, params, PH_SEPARATE, "phalcon/Config/ConfigFactory.zep", 126);
	}
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the adapters for the factory
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getAdapters)
{
	zval *this_ptr = getThis();



	zephir_create_array(return_value, 5, 0);
	add_assoc_stringl_ex(return_value, SL("grouped"), SL("Phalcon\\Config\\Adapter\\Grouped"));
	add_assoc_stringl_ex(return_value, SL("ini"), SL("Phalcon\\Config\\Adapter\\Ini"));
	add_assoc_stringl_ex(return_value, SL("json"), SL("Phalcon\\Config\\Adapter\\Json"));
	add_assoc_stringl_ex(return_value, SL("php"), SL("Phalcon\\Config\\Adapter\\Php"));
	add_assoc_stringl_ex(return_value, SL("yaml"), SL("Phalcon\\Config\\Adapter\\Yaml"));
	return;
}


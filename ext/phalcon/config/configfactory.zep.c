
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


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
 * @param string|array|\Phalcon\Config\Config config = [
 *                                    'adapter'   => 'ini',
 *                                    'filePath'  => 'config.ini',
 *                                    'mode'      => null,
 *                                    'callbacks' => null
 *                                    ]
 *
 * @return ConfigInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, adapter, configArray, filePath, param, _0, _1, _2, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);


	ZEPHIR_CALL_METHOD(&configArray, this_ptr, "parseconfig", NULL, 0, config);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &configArray, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 60);
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fast_strtolower(&adapter, &_0);
	ZEPHIR_OBS_VAR(&filePath);
	zephir_array_fetch_string(&filePath, &configArray, SL("filePath"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 61);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_FUNCTION(&_2, "pathinfo", NULL, 116, &filePath, &_1);
	zephir_check_call_status();
	if (1 == ZEPHIR_IS_EMPTY(&_2)) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "lcfirst", NULL, 104, &adapter);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, ".", &_3$$3);
		zephir_concat_self(&filePath, &_4$$3);
	}
	do {
		if (ZEPHIR_IS_STRING(&adapter, "ini")) {
			ZEPHIR_INIT_VAR(&param);
			ZVAL_LONG(&param, 1);
			if (zephir_array_isset_string(&configArray, SL("mode"))) {
				ZEPHIR_OBS_NVAR(&param);
				zephir_array_fetch_string(&param, &configArray, SL("mode"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 71);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &filePath, &param);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&adapter, "yaml")) {
			ZEPHIR_INIT_NVAR(&param);
			ZVAL_NULL(&param);
			if (zephir_array_isset_string(&configArray, SL("callbacks"))) {
				ZEPHIR_OBS_NVAR(&param);
				zephir_array_fetch_string(&param, &configArray, SL("callbacks"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 78);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &filePath, &param);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &filePath);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a new Config instance
 *
 * @param string     $name
 * @param string     $fileName
 * @param mixed|null $params
 *
 * @return ConfigInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, newInstance)
{
	zval arguments;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *fileName_param = NULL, *params = NULL, params_sub, __$null, definition;
	zval name, fileName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&arguments);
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
	ZEPHIR_INIT_VAR(&arguments);
	zephir_create_array(&arguments, 1, 0);
	zephir_array_fast_append(&arguments, &fileName);
	do {
		if (ZEPHIR_IS_STRING(&name, "grouped") || ZEPHIR_IS_STRING(&name, "ini") || ZEPHIR_IS_STRING(&name, "yaml")) {
			if (Z_TYPE_P(params) != IS_NULL) {
				zephir_array_append(&arguments, params, PH_SEPARATE, "phalcon/Config/ConfigFactory.zep", 112);
			}
			break;
		}
	} while(0);

	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getExceptionClass)
{
	zval *this_ptr = getThis();



	RETURN_STRING("Phalcon\\Config\\Exception");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getServices)
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

/**
 * @param mixed $config
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, parseConfig)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, extension, oldConfig, _0$$3, _1$$3, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&oldConfig);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
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
		ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 116, config, &_0$$3);
		zephir_check_call_status();
		if (1 == ZEPHIR_IS_EMPTY(&extension)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You need to provide the extension in the file path", "phalcon/Config/ConfigFactory.zep", 161);
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
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Config must be array or Phalcon\\Config\\Config object", "phalcon/Config/ConfigFactory.zep", 177);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkconfigarray", NULL, 218, config);
	zephir_check_call_status();
	RETVAL_ZVAL(config, 1, 0);
	RETURN_MM();
}

/**
 * @param array $config
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, checkConfigArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *config_param = NULL;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(config)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);


	if (1 != zephir_array_isset_string(&config, SL("filePath"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'filePath' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 195);
		return;
	}
	if (1 != zephir_array_isset_string(&config, SL("adapter"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Config/ConfigFactory.zep", 201);
		return;
	}
	ZEPHIR_MM_RESTORE();
}


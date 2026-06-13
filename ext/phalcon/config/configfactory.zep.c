
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, adapter, aliases, configArray, filePath, param, spec, _0, _1, _2, _6, _7, _3$$3, _4$$4, _8$$5, _9$$5, _10$$5, _11$$6, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&aliases);
	ZVAL_UNDEF(&configArray);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&spec);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_CALL_METHOD(&configArray, this_ptr, "parseconfig", NULL, 0, config);
	zephir_check_call_status();
	zephir_array_fetch_string(&_0, &configArray, SL("adapter"), PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 63);
	ZEPHIR_INIT_VAR(&adapter);
	zephir_fast_strtolower(&adapter, &_0);
	zephir_memory_observe(&filePath);
	zephir_array_fetch_string(&filePath, &configArray, SL("filePath"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 64);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_CALL_FUNCTION(&_2, "pathinfo", NULL, 168, &filePath, &_1);
	zephir_check_call_status();
	if (1 == ZEPHIR_IS_EMPTY(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, ".", &adapter);
		zephir_concat_self(&filePath, &_3$$3);
	}
	ZEPHIR_CALL_METHOD(&aliases, this_ptr, "getadapteraliases", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_value(&aliases, &adapter)) {
		zephir_array_fetch(&_4$$4, &aliases, &adapter, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 73);
		ZEPHIR_CPY_WRT(&adapter, &_4$$4);
	}
	ZEPHIR_CALL_METHOD(&spec, this_ptr, "getextraarguments", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_array_isset_value(&spec, &adapter);
	if (_5) {
		zephir_array_fetch(&_6, &spec, &adapter, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 78);
		zephir_array_fetch_string(&_7, &_6, SL("option"), PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 78);
		_5 = Z_TYPE_P(&_7) != IS_NULL;
	}
	if (_5) {
		zephir_array_fetch(&_8$$5, &spec, &adapter, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 79);
		zephir_memory_observe(&param);
		zephir_array_fetch_string(&param, &_8$$5, SL("default"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 79);
		zephir_array_fetch(&_9$$5, &spec, &adapter, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 81);
		zephir_array_fetch_string(&_10$$5, &_9$$5, SL("option"), PH_READONLY, "phalcon/Config/ConfigFactory.zep", 81);
		if (zephir_array_isset_value(&configArray, &_10$$5)) {
			ZEPHIR_OBS_NVAR(&param);
			zephir_array_fetch(&_11$$6, &spec, &adapter, PH_NOISY | PH_READONLY, "phalcon/Config/ConfigFactory.zep", 82);
			zephir_memory_observe(&_12$$6);
			zephir_array_fetch_string(&_12$$6, &_11$$6, SL("option"), PH_NOISY, "phalcon/Config/ConfigFactory.zep", 82);
			zephir_array_fetch(&param, &configArray, &_12$$6, PH_NOISY, "phalcon/Config/ConfigFactory.zep", 82);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &adapter, &filePath, &param);
		zephir_check_call_status();
		RETURN_MM();
	}
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
	zend_bool _0;
	zval arguments;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, fileName_zv, *params = NULL, params_sub, __$null, definition, spec;
	zend_string *name = NULL, *fileName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&fileName_zv);
	ZVAL_UNDEF(&params_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&spec);
	ZVAL_UNDEF(&arguments);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR(fileName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(params)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		params = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&fileName_zv);
	ZVAL_STR_COPY(&fileName_zv, fileName);
	if (!params) {
		params = &params_sub;
		params = &__$null;
	}
	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&arguments);
	zephir_create_array(&arguments, 1, 0);
	zephir_array_fast_append(&arguments, &fileName_zv);
	ZEPHIR_CALL_METHOD(&spec, this_ptr, "getextraarguments", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(params) != IS_NULL;
	if (_0) {
		_0 = zephir_array_isset_value(&spec, &name_zv);
	}
	if (_0) {
		zephir_array_append(&arguments, params, PH_SEPARATE, "phalcon/Config/ConfigFactory.zep", 114);
	}
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &arguments);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adapter name aliases resolved by `load()` (file extensions that map
 * to a registered adapter)
 *
 * @return array<string, string>
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getAdapterAliases)
{

	zephir_create_array(return_value, 1, 0);
	add_assoc_stringl_ex(return_value, SL("yml"), SL("yaml"));
	return;
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Config\\Exception");
}

/**
 * Adapters accepting an extra constructor argument, with the config
 * option carrying it and its default value. Single source for the
 * parameter-forwarding knowledge used by `load()` and `newInstance()`.
 *
 * @return array<string, array>
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getExtraArguments)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null;

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 3, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_update_string(&_0, SL("option"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("grouped"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	add_assoc_stringl_ex(&_0, SL("option"), SL("mode"));
	add_assoc_long_ex(&_0, SL("default"), 1);
	zephir_array_update_string(return_value, SL("ini"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_array(&_0, 2, 0);
	add_assoc_stringl_ex(&_0, SL("option"), SL("callbacks"));
	zephir_array_update_string(&_0, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("yaml"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Config_ConfigFactory, getServices)
{

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
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, extension, oldConfig, _0$$3, _2$$3, _1$$4, _4$$5, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&extension);
	ZVAL_UNDEF(&oldConfig);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	if (Z_TYPE_P(config) == IS_STRING) {
		ZEPHIR_CPY_WRT(&oldConfig, config);
		ZVAL_LONG(&_0$$3, 4);
		ZEPHIR_CALL_FUNCTION(&extension, "pathinfo", NULL, 168, config, &_0$$3);
		zephir_check_call_status();
		if (1 == ZEPHIR_IS_EMPTY(&extension)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_config_exceptions_missingfileextension_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 361);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Config/ConfigFactory.zep", 188);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0);
		zephir_array_update_string(&_2$$3, SL("adapter"), &extension, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_2$$3, SL("filePath"), &oldConfig, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(config, &_2$$3);
	}
	_3 = Z_TYPE_P(config) == IS_OBJECT;
	if (_3) {
		_3 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4$$5, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_4$$5);
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_config_exceptions_confignotarrayorobject_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 362);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Config/ConfigFactory.zep", 202);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkconfigarray", NULL, 363, config);
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

	ZVAL_UNDEF(&config);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config_param);
	zephir_get_arrval(&config, config_param);
	if (1 != zephir_array_isset_value_string(&config, SL("filePath"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exceptions_missingconfigoption_ce, "filePath", "phalcon/Config/ConfigFactory.zep", 218);
		return;
	}
	if (1 != zephir_array_isset_value_string(&config, SL("adapter"))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exceptions_missingconfigoption_ce, "adapter", "phalcon/Config/ConfigFactory.zep", 222);
		return;
	}
	ZEPHIR_MM_RESTORE();
}


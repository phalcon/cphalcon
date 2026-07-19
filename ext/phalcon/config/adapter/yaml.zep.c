
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Reads YAML files and converts them to Phalcon\Config\Config objects.
 *
 * Given the following configuration file:
 *
 *```yaml
 * phalcon:
 *   baseuri:        /phalcon/
 *   controllersDir: !approot  /app/controllers/
 * models:
 *   metadata: memory
 *```
 *
 * You can read it as follows:
 *
 *```php
 * define(
 *     "APPROOT",
 *     dirname(__DIR__)
 * );
 *
 * use Phalcon\Config\Adapter\Yaml;
 *
 * $config = new Yaml(
 *     "path/config.yaml",
 *     [
 *         "!approot" => function($value) {
 *             return APPROOT . $value;
 *         },
 *     ]
 * );
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Yaml)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Yaml, phalcon, config_adapter_yaml, phalcon_config_config_ce, phalcon_config_adapter_yaml_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Yaml constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval callbacks;
	zval filePath_zv, *callbacks_param = NULL, yamlConfig, _0, _1, _2$$3, _3$$5, _4$$7, _5$$7;
	zend_string *filePath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_zv);
	ZVAL_UNDEF(&yamlConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&callbacks);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filePath)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(callbacks, callbacks_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		callbacks_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filePath_zv);
	ZVAL_STR_COPY(&filePath_zv, filePath);
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
	} else {
		zephir_get_arrval(&callbacks, callbacks_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "yaml");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpextensionloaded", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_config_exceptions_missingyamlextension_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 436);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Config/Adapter/Yaml.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EMPTY(&callbacks)) {
		ZEPHIR_CALL_METHOD(&yamlConfig, this_ptr, "phpyamlparsefile", NULL, 0, &filePath_zv);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_CALL_METHOD(&yamlConfig, this_ptr, "phpyamlparsefile", NULL, 0, &filePath_zv, &_3$$5, &callbacks);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&yamlConfig) == IS_NULL)) {
		ZEPHIR_INIT_NVAR(&yamlConfig);
		array_init(&yamlConfig);
	}
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&yamlConfig))) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, phalcon_config_exceptions_cannotloadconfigfile_ce);
		ZEPHIR_INIT_VAR(&_5$$7);
		zephir_basename(&_5$$7, &filePath_zv);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 431, &_5$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Config/Adapter/Yaml.zep", 84);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_yaml_ce, getThis(), "__construct", NULL, 0, &yamlConfig);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 437, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

/**
 * Parse a YAML stream from a file
 *
 * @param string $filename
 * @param int    $pos
 * @param array  $callbacks
 *
 * @return mixed
 *
 * @link https://php.net/manual/en/function.yaml-parse-file.php
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, phpYamlParseFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval callbacks;
	zend_long pos, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *pos_param = NULL, *callbacks_param = NULL, ndocs, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&ndocs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&callbacks);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(pos)
		ZEPHIR_Z_PARAM_ARRAY(callbacks, callbacks_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		pos_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		callbacks_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!pos_param) {
		pos = 0;
	} else {
		}
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
		array_init(&callbacks);
	} else {
		zephir_get_arrval(&callbacks, callbacks_param);
	}
	ZEPHIR_INIT_VAR(&ndocs);
	ZVAL_NULL(&ndocs);
	ZVAL_LONG(&_0, pos);
	ZEPHIR_MAKE_REF(&ndocs);
	ZEPHIR_RETURN_CALL_FUNCTION("yaml_parse_file", NULL, 438, &filename_zv, &_0, &ndocs, &callbacks);
	ZEPHIR_UNREF(&ndocs);
	zephir_check_call_status();
	RETURN_MM();
}


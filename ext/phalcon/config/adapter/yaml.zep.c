
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
#include "kernel/concat.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
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
 * Reads YAML files and converts them to Phalcon\Config objects.
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
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Yaml, phalcon, config_adapter_yaml, phalcon_config_ce, phalcon_config_adapter_yaml_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Yaml constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, ndocs;
	zval callbacks;
	zval *filePath_param = NULL, *callbacks_param = NULL, yamlConfig, _0, _1, _2$$5, _3$$5, _4$$6, _5$$6, _6$$6;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&yamlConfig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&callbacks);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filePath)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(callbacks)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &callbacks_param);
	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
	}
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(&callbacks);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&callbacks, callbacks_param);
	}


	ndocs = 0;
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "yaml");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 183, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Yaml extension not loaded", "phalcon/Config/Adapter/Yaml.zep", 64);
		return;
	}
	if (ZEPHIR_IS_EMPTY(&callbacks)) {
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", NULL, 184, &filePath);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_2$$5, 0);
		ZVAL_LONG(&_3$$5, ndocs);
		ZEPHIR_MAKE_REF(&_3$$5);
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", NULL, 184, &filePath, &_2$$5, &_3$$5, &callbacks);
		ZEPHIR_UNREF(&_3$$5);
		zephir_check_call_status();
	}
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&yamlConfig))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		object_init_ex(&_4$$6, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_basename(&_5$$6, &filePath);
		ZEPHIR_INIT_VAR(&_6$$6);
		ZEPHIR_CONCAT_SVS(&_6$$6, "Configuration file ", &_5$$6, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 8, &_6$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$6, "phalcon/Config/Adapter/Yaml.zep", 76);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_yaml_ce, getThis(), "__construct", &_7, 0, &yamlConfig);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}


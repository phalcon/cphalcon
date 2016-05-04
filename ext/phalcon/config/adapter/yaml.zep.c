
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


/**
 * Phalcon\Config\Adapter\Yaml
 *
 * Reads YAML files and converts them to Phalcon\Config objects.
 *
 * Given the following configuration file:
 *
 *<code>
 * phalcon:
 *   baseuri:        /phalcon/
 *   controllersDir: !approot  /app/controllers/
 * models:
 *   metadata: memory
 *</code>
 *
 * You can read it as follows:
 *
 *<code>
 * define('APPROOT', dirname(__DIR__));
 *
 * $config = new Phalcon\Config\Adapter\Yaml("path/config.yaml", [
 *     '!approot' => function($value) {
 *         return APPROOT . $value;
 *     }
 * ]);
 *
 * echo $config->phalcon->controllersDir;
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Yaml) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Yaml, phalcon, config_adapter_yaml, phalcon_config_ce, phalcon_config_adapter_yaml_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Config\Adapter\Yaml constructor
 *
 * @throws \Phalcon\Config\Exception
 */
PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct) {

	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, ndocs;
	zval *callbacks = NULL;
	zval *filePath_param = NULL, *callbacks_param = NULL, *yamlConfig = NULL, _0, *_1 = NULL, *_2$$4, *_3$$4, *_5$$6, *_6$$6, *_7$$6;
	zval *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &filePath_param, &callbacks_param);

	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	if (!callbacks_param) {
		ZEPHIR_INIT_VAR(callbacks);
		array_init(callbacks);
	} else {
	callbacks = callbacks_param;
	}


	ndocs = 0;
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "yaml", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 134, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Yaml extension not loaded", "phalcon/config/adapter/yaml.zep", 71);
		return;
	}
	if (!ZEPHIR_IS_STRING_IDENTICAL(callbacks, "")) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_LONG(_2$$4, 0);
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_LONG(_3$$4, ndocs);
		ZEPHIR_MAKE_REF(_3$$4);
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", &_4, 135, filePath, _2$$4, _3$$4, callbacks);
		ZEPHIR_UNREF(_3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&yamlConfig, "yaml_parse_file", &_4, 135, filePath);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(yamlConfig)) {
		ZEPHIR_INIT_VAR(_5$$6);
		object_init_ex(_5$$6, phalcon_config_exception_ce);
		ZEPHIR_INIT_VAR(_6$$6);
		zephir_basename(_6$$6, filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$6);
		ZEPHIR_CONCAT_SVS(_7$$6, "Configuration file ", _6$$6, " can't be loaded");
		ZEPHIR_CALL_METHOD(NULL, _5$$6, "__construct", NULL, 9, _7$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$6, "phalcon/config/adapter/yaml.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_yaml_ce, this_ptr, "__construct", &_8, 22, yamlConfig);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


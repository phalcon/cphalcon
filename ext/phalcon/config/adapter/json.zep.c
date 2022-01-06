
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/file.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Reads JSON files and converts them to Phalcon\Config\Config objects.
 *
 * Given the following configuration file:
 *
 *```json
 * {"phalcon":{"baseuri":"\/phalcon\/"},"models":{"metadata":"memory"}}
 *```
 *
 * You can read it as follows:
 *
 *```php
 * use Phalcon\Config\Adapter\Json;
 *
 * $config = new Json("path/config.json");
 *
 * echo $config->phalcon->baseuri;
 * echo $config->models->metadata;
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config\\Adapter, Json, phalcon, config_adapter_json, phalcon_config_config_ce, phalcon_config_adapter_json_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Config\Adapter\Json constructor
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *filePath_param = NULL, _1, _2, _3;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filePath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);
	if (UNEXPECTED(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(&filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(&filePath);
	}


	ZEPHIR_INIT_VAR(&_2);
	zephir_file_get_contents(&_2, &filePath);
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "decode", NULL, 208, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_config_adapter_json_ce, getThis(), "__construct", &_0, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo This will be removed when traits are introduced
 */
PHP_METHOD(Phalcon_Config_Adapter_Json, decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long depth, options, ZEPHIR_LAST_CALL_STATUS;
	zend_bool associative;
	zval *data_param = NULL, *associative_param = NULL, *depth_param = NULL, *options_param = NULL, decoded, _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(associative)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &data_param, &associative_param, &depth_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
	}
	if (!associative_param) {
		associative = 0;
	} else {
		associative = zephir_get_boolval(associative_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}
	if (!options_param) {
		options = 0;
	} else {
		options = zephir_get_intval(options_param);
	}


	ZVAL_BOOL(&_0, (associative ? 1 : 0));
	ZVAL_LONG(&_1, depth);
	ZVAL_LONG(&_2, options);
	ZEPHIR_INIT_VAR(&decoded);
	zephir_json_decode(&decoded, &data, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 209);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "json_last_error_msg", NULL, 210);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "json_decode error: ", &_5$$3);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 40, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Config/Adapter/Json.zep", 68);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&decoded);
}


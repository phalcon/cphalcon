
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Stores the parsed annotations in APCu. This adapter is suitable for production
 *
 *```php
 * use Phalcon\Annotations\Adapter\Apcu;
 *
 * $annotations = new Apcu();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Apcu)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Apcu, phalcon, annotations_adapter_apcu, phalcon_annotations_adapter_abstractadapter_ce, phalcon_annotations_adapter_apcu_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_annotations_adapter_apcu_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_annotations_adapter_apcu_ce, SL("ttl"), 172800, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param array options = [
 *     'prefix' => 'phalcon'
 *     'lifetime' => 3600
 * ]
 *
 * Phalcon\Annotations\Adapter\Apcu constructor
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, prefix, ttl;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&ttl);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_memory_observe(&prefix);
	if (zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	}
	zephir_memory_observe(&ttl);
	if (zephir_array_isset_string_fetch(&ttl, &options, SL("lifetime"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("ttl"), &ttl);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Reads parsed annotations from APCu
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, _0, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVV(&_2, "_PHAN", &_1, &key_zv);
	zephir_fast_strtolower(&_0, &_2);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 114, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Writes parsed annotations to APCu
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Apcu, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *data, data_sub, _0, _1, _2, _3;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OBJECT_OF_CLASS(data, phalcon_annotations_reflection_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVV(&_2, "_PHAN", &_1, &key_zv);
	zephir_fast_strtolower(&_0, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("ttl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_store", NULL, 115, &_0, data, &_3);
	zephir_check_call_status();
	RETURN_MM();
}


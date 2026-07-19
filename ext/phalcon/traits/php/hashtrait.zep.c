
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Hashing method wrappers
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_HashTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, HashTrait, phalcon, traits_php_hashtrait, phalcon_traits_php_hashtrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $algorithm
 * @param string $data
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash.php
 */
PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHash)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		binary_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash", NULL, 166, &algorithm_zv, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $knownString
 * @param string $userString
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.hash-equals.php
 */
PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHashEquals)
{
	zval knownString_zv, userString_zv;
	zend_string *knownString = NULL, *userString = NULL;

	ZVAL_UNDEF(&knownString_zv);
	ZVAL_UNDEF(&userString_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(knownString)
		Z_PARAM_STR(userString)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&knownString_zv, knownString);
	ZVAL_STR(&userString_zv, userString);
	RETURN_BOOL(zephir_hash_equals(&knownString_zv, &userString_zv));
}

/**
 * @param string $algorithm
 * @param string $data
 * @param string $key
 * @param bool   $binary
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.hash-hmac.php
 */
PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHashHmac)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool binary;
	zval algorithm_zv, data_zv, key_zv, *binary_param = NULL, _0;
	zend_string *algorithm = NULL, *data = NULL, *key = NULL;

	ZVAL_UNDEF(&algorithm_zv);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(algorithm)
		Z_PARAM_STR(data)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(binary)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		binary_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&algorithm_zv);
	ZVAL_STR_COPY(&algorithm_zv, algorithm);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!binary_param) {
		binary = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (binary ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac", NULL, 167, &algorithm_zv, &data_zv, &key_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}


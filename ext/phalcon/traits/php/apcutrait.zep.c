
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
#include "kernel/memory.h"
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
 * APCu based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_ApcuTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, ApcuTrait, phalcon, traits_php_apcutrait, phalcon_traits_php_apcutrait_method_entry);

	return SUCCESS;
}

/**
 * @param mixed $key
 * @param int   $step
 *
 * @return bool|int
 *
 * @link https://php.net/manual/en/function.apcu-dec.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuDec)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long step, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *step_param = NULL, _0;

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key, &step_param);
	if (!step_param) {
		step = 1;
	} else {
		}
	ZVAL_LONG(&_0, step);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_dec", NULL, 260, key, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $key
 *
 * @return bool|array
 *
 * @link https://php.net/manual/en/function.apcu-delete.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;

	ZVAL_UNDEF(&key_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &key);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_delete", NULL, 261, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $key
 *
 * @return bool|array
 *
 * @link https://php.net/manual/en/function.apcu-exists.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;

	ZVAL_UNDEF(&key_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &key);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 262, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $key
 *
 * @return mixed
 *
 * @link https://php.net/manual/en/function.apcu-fetch.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuFetch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;

	ZVAL_UNDEF(&key_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &key);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 263, key);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $key
 * @param int   $step
 *
 * @return bool|int
 *
 * @link https://php.net/manual/en/function.apcu-inc.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuInc)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long step, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *step_param = NULL, _0;

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &key, &step_param);
	if (!step_param) {
		step = 1;
	} else {
		}
	ZVAL_LONG(&_0, step);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_inc", NULL, 264, key, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $pattern
 *
 * @return \APCUIterator|bool
 *
 * @link https://php.net/manual/en/class.apcuiterator.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuIterator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv;
	zend_string *pattern = NULL;

	ZVAL_UNDEF(&pattern_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	object_init_ex(return_value, zephir_get_internal_ce(SL("apcuiterator")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &pattern_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed $key
 * @param mixed $payload
 * @param int   $ttl
 *
 * @return bool|array
 *
 * @link https://php.net/manual/en/function.apcu-store.php
 */
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuStore)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *payload, payload_sub, *ttl_param = NULL, _0;

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(payload)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(ttl)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &key, &payload, &ttl_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		}
	ZVAL_LONG(&_0, ttl);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_store", NULL, 265, key, payload, &_0);
	zephir_check_call_status();
	RETURN_MM();
}


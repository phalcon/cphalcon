
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * URL based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_UrlTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, UrlTrait, phalcon, traits_php_urltrait, phalcon_traits_php_urltrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $url
 * @param int    $component
 *
 * @return array|bool|int|string|null
 *
 * @link https://php.net/manual/en/function.parse-url.php
 */
PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpParseUrl)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long component, ZEPHIR_LAST_CALL_STATUS;
	zval url_zv, *component_param = NULL, _0;
	zend_string *url = NULL;

	ZVAL_UNDEF(&url_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(url)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(component)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		component_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&url_zv);
	ZVAL_STR_COPY(&url_zv, url);
	if (!component_param) {
		component = -1;
	} else {
		}
	ZVAL_LONG(&_0, component);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_url", NULL, 0, &url_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.rawurldecode.php
 */
PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpRawUrlDecode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurldecode", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.rawurlencode.php
 */
PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpRawUrlEncode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_FUNCTION("rawurlencode", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}


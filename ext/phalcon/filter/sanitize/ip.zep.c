
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
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
 * Phalcon\Filter\Sanitize\IP
 *
 * Sanitizes a value to an ip address or CIDR range
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Ip)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Ip, phalcon, filter_sanitize_ip, phalcon_filter_sanitize_ip_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $input
 * @param int $filter
 * @return false|string
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Ip, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long filter, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *filter_param = NULL, parts, ip, mask, maxMask, filtered, ipInput, _5, _6, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&maxMask);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&ipInput);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filter_param = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&input_zv, input);
	if (!filter_param) {
		filter = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&ipInput);
	zephir_fast_trim(&ipInput, &input_zv, NULL , ZEPHIR_TRIM_BOTH);
	if (zephir_memnstr_str(&ipInput, SL("/"), "phalcon/Filter/Sanitize/Ip.zep", 32)) {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("/"), &input_zv, 2 );
		zephir_memory_observe(&ip);
		zephir_array_fetch_long(&ip, &parts, 0, PH_NOISY, "phalcon/Filter/Sanitize/Ip.zep", 34);
		zephir_memory_observe(&mask);
		zephir_array_fetch_long(&mask, &parts, 1, PH_NOISY, "phalcon/Filter/Sanitize/Ip.zep", 35);
		ZVAL_LONG(&_0$$3, 275);
		ZVAL_LONG(&_1$$3, filter);
		ZEPHIR_CALL_FUNCTION(&filtered, "filter_var", NULL, 307, &ip, &_0$$3, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_CALL_FUNCTION(&_2$$3, "ctype_digit", NULL, 309, &mask);
		zephir_check_call_status();
		if (!zephir_is_true(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, ":");
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_strpos(&_4$$3, &filtered, &_3$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_4$$3)) {
			ZEPHIR_INIT_VAR(&maxMask);
			ZVAL_LONG(&maxMask, 128);
		} else {
			ZEPHIR_INIT_NVAR(&maxMask);
			ZVAL_LONG(&maxMask, 32);
		}
		if (ZEPHIR_GE_LONG(&maxMask, zephir_get_intval(&mask))) {
			ZEPHIR_CONCAT_VSV(return_value, &filtered, "/", &mask);
			RETURN_MM();
		}
		RETURN_MM_BOOL(0);
	}
	ZVAL_LONG(&_5, 275);
	ZVAL_LONG(&_6, filter);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 307, &ipInput, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();
}


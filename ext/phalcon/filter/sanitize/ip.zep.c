
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/array.h"
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
	zend_bool _2$$6, _3$$6, _6$$9, _7$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long filter, ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *filter_param = NULL, parts, ip, mask, protocol, filtered, _0$$5, _1$$5, _4$$8, _5$$8, _8$$12, _9$$12, _10$$13, _11$$13;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&mask);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &input_param, &filter_param);
	zephir_get_strval(&input, input_param);
	if (!filter_param) {
		filter = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&protocol, this_ptr, "getipaddressprotocolversion", NULL, 286, &input);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&protocol)) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_memnstr_str(&input, SL("/"), "phalcon/Filter/Sanitize/Ip.zep", 35)) {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("/"), &input, 2 );
		zephir_memory_observe(&ip);
		zephir_array_fetch_long(&ip, &parts, 0, PH_NOISY, "phalcon/Filter/Sanitize/Ip.zep", 37);
		zephir_memory_observe(&mask);
		zephir_array_fetch_long(&mask, &parts, 1, PH_NOISY, "phalcon/Filter/Sanitize/Ip.zep", 38);
		if (ZEPHIR_IS_LONG_IDENTICAL(&protocol, 4)) {
			ZVAL_LONG(&_0$$5, 275);
			ZVAL_LONG(&_1$$5, (1048576 | filter));
			ZEPHIR_CALL_FUNCTION(&filtered, "filter_var", NULL, 284, &ip, &_0$$5, &_1$$5);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&filtered)) {
				_2$$6 = zephir_is_numeric(&mask);
				if (_2$$6) {
					_2$$6 = ZEPHIR_GE_LONG(&mask, 0);
				}
				_3$$6 = _2$$6;
				if (_3$$6) {
					_3$$6 = ZEPHIR_LE_LONG(&mask, 32);
				}
				if (_3$$6) {
					ZEPHIR_CONCAT_VSV(return_value, &filtered, "/", &mask);
					RETURN_MM();
				}
			}
		}
		if (ZEPHIR_IS_LONG_IDENTICAL(&protocol, 6)) {
			ZVAL_LONG(&_4$$8, 275);
			ZVAL_LONG(&_5$$8, (2097152 | filter));
			ZEPHIR_CALL_FUNCTION(&filtered, "filter_var", NULL, 284, &ip, &_4$$8, &_5$$8);
			zephir_check_call_status();
			if (zephir_is_true(&filtered)) {
				_6$$9 = zephir_is_numeric(&mask);
				if (_6$$9) {
					_6$$9 = ZEPHIR_GE_LONG(&mask, 0);
				}
				_7$$9 = _6$$9;
				if (_7$$9) {
					_7$$9 = ZEPHIR_LE_LONG(&mask, 128);
				}
				if (_7$$9) {
					ZEPHIR_CONCAT_VSV(return_value, &filtered, "/", &mask);
					RETURN_MM();
				}
			}
		}
	} else {
		if (ZEPHIR_IS_LONG_IDENTICAL(&protocol, 4)) {
			ZVAL_LONG(&_8$$12, 275);
			ZVAL_LONG(&_9$$12, (1048576 | filter));
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 284, &input, &_8$$12, &_9$$12);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG_IDENTICAL(&protocol, 6)) {
			ZVAL_LONG(&_10$$13, 275);
			ZVAL_LONG(&_11$$13, (2097152 | filter));
			ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 284, &input, &_10$$13, &_11$$13);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * Return the IP address protocol version
 *
 * @param $ip
 * @return int|false
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Ip, getIpAddressProtocolVersion)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, parts, ip, _0, _1, _2, _3;
	zval input;

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&ip);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);
	ZEPHIR_CPY_WRT(&ip, &input);
	if (zephir_memnstr_str(&ip, SL("/"), "phalcon/Filter/Sanitize/Ip.zep", 85)) {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("/"), &ip, 2 );
		ZEPHIR_OBS_NVAR(&ip);
		zephir_array_fetch_long(&ip, &parts, 0, PH_NOISY, "phalcon/Filter/Sanitize/Ip.zep", 87);
	}
	ZVAL_LONG(&_0, 275);
	ZVAL_LONG(&_1, 1048576);
	ZEPHIR_CALL_FUNCTION(&_2, "filter_var", NULL, 284, &ip, &_0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_LONG(4);
	}
	ZVAL_LONG(&_0, 275);
	ZVAL_LONG(&_1, 2097152);
	ZEPHIR_CALL_FUNCTION(&_3, "filter_var", NULL, 284, &ip, &_0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_LONG(6);
	}
	RETURN_MM_BOOL(0);
}


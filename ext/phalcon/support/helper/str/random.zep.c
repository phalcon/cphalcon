
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/math.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Generates a random string based on the given type. Type is one of the
 * RANDOM_* constants
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Random)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Random, phalcon, support_helper_str_random, phalcon_support_helper_str_random_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_ALNUM"), 0);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_ALPHA"), 1);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_DISTINCT"), 5);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_HEXDEC"), 2);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_NOZERO"), 4);

	zephir_declare_class_constant_long(phalcon_support_helper_str_random_ce, SL("RANDOM_NUMERIC"), 3);

	return SUCCESS;
}

/**
 * @param int $type
 * @param int $length
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Random, __invoke)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, *length_param = NULL, end, pools, text, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16$$3, _17$$3, _18$$3;
	zend_long type, length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&pools);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type_param, &length_param);
	if (!type_param) {
		type = 0;
	} else {
		type = zephir_get_intval(type_param);
	}
	if (!length_param) {
		length = 8;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_INIT_VAR(&text);
	ZVAL_STRING(&text, "");
	ZEPHIR_INIT_VAR(&_0);
	_1 = type < 0;
	if (!(_1)) {
		_1 = type > 5;
	}
	if (_1) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, 0);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_LONG(&_0, type);
	}
	type = zephir_get_numberval(&_0);
	ZEPHIR_INIT_VAR(&pools);
	zephir_create_array(&pools, 6, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "a");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "z");
	ZEPHIR_CALL_FUNCTION(&_5, "range", NULL, 331, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "A");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Z");
	ZEPHIR_CALL_FUNCTION(&_6, "range", NULL, 331, &_3, &_4);
	zephir_check_call_status();
	zephir_fast_array_merge(&_2, &_5, &_6);
	zephir_array_update_long(&pools, 1, &_2, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 9);
	ZEPHIR_CALL_FUNCTION(&_9, "range", NULL, 331, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "a");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "f");
	ZEPHIR_CALL_FUNCTION(&_10, "range", NULL, 331, &_3, &_4);
	zephir_check_call_status();
	zephir_fast_array_merge(&_2, &_9, &_10);
	zephir_array_update_long(&pools, 2, &_2, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 9);
	ZEPHIR_CALL_FUNCTION(&_11, "range", NULL, 331, &_7, &_8);
	zephir_check_call_status();
	zephir_array_update_long(&pools, 3, &_11, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZVAL_LONG(&_7, 1);
	ZVAL_LONG(&_8, 9);
	ZEPHIR_CALL_FUNCTION(&_11, "range", NULL, 331, &_7, &_8);
	zephir_check_call_status();
	zephir_array_update_long(&pools, 4, &_11, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "2345679ACDEFHJKLMNPRSTUVWXYZ");
	ZEPHIR_CALL_FUNCTION(&_11, "str_split", NULL, 114, &_2);
	zephir_check_call_status();
	zephir_array_update_long(&pools, 5, &_11, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZVAL_LONG(&_7, 0);
	ZVAL_LONG(&_8, 9);
	ZEPHIR_CALL_FUNCTION(&_11, "range", NULL, 331, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "a");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "z");
	ZEPHIR_CALL_FUNCTION(&_12, "range", NULL, 331, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "A");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Z");
	ZEPHIR_CALL_FUNCTION(&_13, "range", NULL, 331, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_14, "array_merge", NULL, 348, &_11, &_12, &_13);
	zephir_check_call_status();
	zephir_array_update_long(&pools, 0, &_14, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_fetch_long(&_15, &pools, type, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Random.zep", 66);
	ZEPHIR_INIT_VAR(&end);
	ZVAL_LONG(&end, (zephir_fast_count_int(&_15) - 1));
	while (1) {
		if (!(zephir_fast_strlen_ev(&text) < length)) {
			break;
		}
		zephir_array_fetch_long(&_16$$3, &pools, type, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Random.zep", 69);
		ZVAL_LONG(&_18$$3, 0);
		zephir_array_fetch_long(&_17$$3, &_16$$3, zephir_mt_rand(zephir_get_intval(&_18$$3), zephir_get_intval(&end)), PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/Random.zep", 69);
		zephir_concat_self(&text, &_17$$3);
	}
	RETURN_CCTOR(&text);
}


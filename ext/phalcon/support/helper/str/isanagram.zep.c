
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Compare two strings and returns `true` if both strings are anagram,
 * `false` otherwise.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_IsAnagram)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, IsAnagram, phalcon, support_helper_str_isanagram, phalcon_support_helper_str_isanagram_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $first
 * @param string $second
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_IsAnagram, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *first_param = NULL, *second_param = NULL, _0, _1, _2;
	zval first, second;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&second);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(first)
		Z_PARAM_STR(second)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &first_param, &second_param);
	zephir_get_strval(&first, first_param);
	zephir_get_strval(&second, second_param);


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&_1, "count_chars", NULL, 305, &first, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "count_chars", NULL, 305, &second, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_1, &_2));
}


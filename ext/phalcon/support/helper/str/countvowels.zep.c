
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
#include "kernel/string.h"
#include "kernel/array.h"
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
 * Returns number of vowels in provided string. Uses a regular expression
 * to count the number of vowels (A, E, I, O, U) in a string.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_CountVowels)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, CountVowels, phalcon, support_helper_str_countvowels, phalcon_support_helper_str_countvowels_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 *
 * @return int
 */
PHP_METHOD(Phalcon_Support_Helper_Str_CountVowels, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *text_param = NULL, matches, _0, _1, _2, _3;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/[aeiouy]/i");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/[aeiouy]/i");
	zephir_preg_match(&_1, &_2, &text, &matches, 1, 0 , 0 );
	zephir_array_fetch_long(&_3, &matches, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Helper/Str/CountVowels.zep", 30);
	RETURN_MM_LONG(zephir_fast_count_int(&_3));
}


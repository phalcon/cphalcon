
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
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
 * Decapitalizes the first letter of the string and then adds it with rest
 * of the string. Omit the upperRest parameter to keep the rest of the
 * string intact, or set it to true to convert to uppercase.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Decapitalize)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, Decapitalize, phalcon, support_helper_str_decapitalize, phalcon_support_helper_str_abstractstr_ce, phalcon_support_helper_str_decapitalize_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param bool   $upperRest
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Decapitalize, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool upperRest;
	zval *text_param = NULL, *upperRest_param = NULL, *encoding_param = NULL, substr, suffix, _0, _1, _2, _3;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&substr);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(upperRest)
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &upperRest_param, &encoding_param);
	zephir_get_strval(&text, text_param);
	if (!upperRest_param) {
		upperRest = 0;
	} else {
		upperRest = zephir_get_boolval(upperRest_param);
	}
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
		zephir_get_strval(&encoding, encoding_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_CALL_FUNCTION(&substr, "mb_substr", NULL, 241, &text, &_0);
	zephir_check_call_status();
	if (upperRest) {
		ZEPHIR_CALL_METHOD(&suffix, this_ptr, "toupper", NULL, 0, &substr, &encoding);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&suffix, &substr);
	}
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_FUNCTION(&_3, "mb_substr", NULL, 241, &text, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "tolower", NULL, 0, &_3, &encoding);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_1, &suffix);
	RETURN_MM();
}


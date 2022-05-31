
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Capitalizes the first letter of each word
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Ucwords)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Ucwords, phalcon, support_helper_str_ucwords, phalcon_support_helper_str_ucwords_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $encoding
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Ucwords, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *encoding_param = NULL, _0;
	zval text, encoding;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &encoding_param);
	zephir_get_strval(&text, text_param);
	if (!encoding_param) {
		ZEPHIR_INIT_VAR(&encoding);
		ZVAL_STRING(&encoding, "UTF-8");
	} else {
		zephir_get_strval(&encoding, encoding_param);
	}


	ZVAL_LONG(&_0, 2);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text, &_0, &encoding);
	zephir_check_call_status();
	RETURN_MM();
}


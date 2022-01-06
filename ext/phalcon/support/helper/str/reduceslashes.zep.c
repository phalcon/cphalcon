
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
 * Reduces multiple slashes in a string to single slashes
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_ReduceSlashes)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, ReduceSlashes, phalcon, support_helper_str_reduceslashes, phalcon_support_helper_str_reduceslashes_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_ReduceSlashes, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, result, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	ZVAL_STRING(&_0, "#(?<!:)//+#");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_CALL_FUNCTION(&result, "preg_replace", NULL, 50, &_0, &_1, &text);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	if (Z_TYPE_P(&result) == IS_NULL) {
		ZVAL_STRING(&_0, "");
	} else {
		ZEPHIR_CPY_WRT(&_0, &result);
	}
	RETURN_CCTOR(&_0);
}


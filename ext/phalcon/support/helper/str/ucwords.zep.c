
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
	zval text_zv, encoding_zv, _0;
	zend_string *text = NULL, *encoding = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&encoding_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&text_zv, text);
	if (!encoding) {
		encoding = zend_string_init(ZEND_STRL("UTF-8"), 0);
		ZVAL_STR(&encoding_zv, encoding);
	} else {
		ZVAL_STR_COPY(&encoding_zv, encoding);
	}
	ZVAL_LONG(&_0, 2);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_case", NULL, 11, &text_zv, &_0, &encoding_zv);
	zephir_check_call_status();
	RETURN_MM();
}


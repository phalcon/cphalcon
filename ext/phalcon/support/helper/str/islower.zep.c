
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Returns `true` if the given string is in lower case, `false` otherwise.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_IsLower)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, IsLower, phalcon, support_helper_str_islower, phalcon_support_helper_str_abstractstr_ce, phalcon_support_helper_str_islower_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $encoding
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_IsLower, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, encoding_zv, _0;
	zend_string *text = NULL, *encoding = NULL;
	zval *this_ptr = getThis();

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
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!encoding) {
		encoding = zend_string_init(ZEND_STRL("UTF-8"), 0);
		zephir_memory_observe(&encoding_zv);
		ZVAL_STR(&encoding_zv, encoding);
	} else {
		zephir_memory_observe(&encoding_zv);
	ZVAL_STR_COPY(&encoding_zv, encoding);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "tolower", NULL, 0, &text_zv, &encoding_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&text_zv, &_0));
}


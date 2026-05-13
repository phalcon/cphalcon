
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Prefixes the text with the supplied prefix
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Prefix)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Prefix, phalcon, support_helper_str_prefix, phalcon_support_helper_str_prefix_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed  $text
 * @param string $prefix
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Prefix, __invoke)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *prefix = NULL;
	zval *text, text_sub, prefix_zv;

	ZVAL_UNDEF(&text_sub);
	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(text)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	text = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	zephir_cast_to_string(&_0, text);
	ZEPHIR_CONCAT_VV(return_value, &prefix_zv, &_0);
	RETURN_MM();
}


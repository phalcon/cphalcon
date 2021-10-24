
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
#include "kernel/string.h"
#include "kernel/memory.h"
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
 * Phalcon\Filter\Sanitize\Replace
 *
 * Sanitizes a value replacing parts of a string
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Replace)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Replace, phalcon, filter_sanitize_replace, phalcon_filter_sanitize_replace_method_entry, 0);

	return SUCCESS;
}

/**
 * @param mixed $input
 * @param mixed $source
 * @param mixed $target
 *
 * @return string|string[]
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Replace, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input, input_sub, *from, from_sub, *to, to_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&from_sub);
	ZVAL_UNDEF(&to_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(input)
		Z_PARAM_ZVAL(from)
		Z_PARAM_ZVAL(to)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &input, &from, &to);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_str_replace(&_0, from, to, input);
	RETURN_CCTOR(&_0);
}


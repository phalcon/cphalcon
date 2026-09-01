
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
 * Phalcon\Filter\Sanitize\Trim
 *
 * Sanitizes a value removing leading and trailing spaces
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Trim)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Trim, phalcon, filter_sanitize_trim, phalcon_filter_sanitize_trim_method_entry, 0);

	zend_class_implements(phalcon_filter_sanitize_trim_ce, 1, phalcon_contracts_filter_sanitizer_ce);
	return SUCCESS;
}

/**
 * @param string $input The text to sanitize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Trim, __invoke)
{
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&input_zv, input);
	zephir_fast_trim(return_value, &input_zv, NULL , ZEPHIR_TRIM_BOTH);
	return;
}


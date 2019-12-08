
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
#include "kernel/fcall.h"
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
 * Phalcon\Filter\Sanitize\Regex
 *
 * Sanitizes a value performing preg_replace
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Regex) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Regex, phalcon, filter_sanitize_regex, phalcon_filter_sanitize_regex_method_entry, 0);

	return SUCCESS;

}

/**
 * @var mixed input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Regex, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, *pattern, pattern_sub, *replace, replace_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&pattern_sub);
	ZVAL_UNDEF(&replace_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &input, &pattern, &replace);



	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", NULL, 47, pattern, replace, input);
	zephir_check_call_status();
	RETURN_MM();

}


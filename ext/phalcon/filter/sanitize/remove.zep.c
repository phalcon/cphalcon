
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\Remove
 *
 * Sanitizes a value removing parts of a string
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Remove) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, Remove, phalcon, filter_sanitize_remove, phalcon_filter_sanitize_remove_method_entry, 0);

	return SUCCESS;

}

/**
 * @var mixed input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_Remove, __invoke) {

	zval *input, input_sub, *replace, replace_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&replace_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &input, &replace);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_str_replace(&_1, replace, &_0, input TSRMLS_CC);
	RETURN_CCTOR(&_1);

}


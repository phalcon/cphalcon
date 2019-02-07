
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\Address
 *
 * Creates an element
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Element) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Element, phalcon, html_helper_element, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_element_method_entry, 0);

	return SUCCESS;

}

/**
 * @var string tag        The tag name
 * @var string text       The text for the anchor
 * @var array  attributes Any additional attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Element, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *text_param = NULL, *attributes_param = NULL;
	zval tag, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tag_param, &text_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(tag_param) != IS_STRING && Z_TYPE_P(tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tag' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tag_param) == IS_STRING)) {
		zephir_get_strval(&tag, tag_param);
	} else {
		ZEPHIR_INIT_VAR(&tag);
		ZVAL_EMPTY_STRING(&tag);
	}
	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderelement", NULL, 0, &tag, &text, &attributes);
	zephir_check_call_status();
	RETURN_MM();

}


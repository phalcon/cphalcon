
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Helper\Form
 *
 * Creates a form opening tag
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Form) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Form, phalcon, html_helper_form, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_form_method_entry, 0);

	return SUCCESS;

}

/**
 * @var array  attributes Any additional attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Form, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, overrides, _0, _1;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&overrides);
	zephir_create_array(&overrides, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&overrides, SL("method"), SL("post"));
	add_assoc_stringl_ex(&overrides, SL("enctype"), SL("multipart/form-data"));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "orderattributes", NULL, 0, &overrides, &attributes);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&overrides, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "renderattributes", NULL, 0, &overrides);
	zephir_check_call_status();
	zephir_fast_trim(&_1, &_0, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<form ", &_1, ">");
	RETURN_MM();

}


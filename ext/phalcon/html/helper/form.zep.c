
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
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Form
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Form) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Form, phalcon, html_helper_form, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_form_method_entry, 0);

	return SUCCESS;

}

/**
 * Produce a <form> tag.
 *
 * @param array $attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Form, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&overrides, 2, 0);
	add_assoc_stringl_ex(&overrides, SL("method"), SL("post"));
	add_assoc_stringl_ex(&overrides, SL("enctype"), SL("multipart/form-data"));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "orderattributes", NULL, 0, &overrides, &attributes);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&overrides, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "form");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderelement", NULL, 0, &_1, &overrides);
	zephir_check_call_status();
	RETURN_MM();

}


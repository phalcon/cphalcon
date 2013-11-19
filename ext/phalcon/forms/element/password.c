
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


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Forms\Element\Password
 *
 * Component INPUT[type=password] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Password) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Password, phalcon, forms_element_password, phalcon_forms_element_ce, phalcon_forms_element_password_method_entry, 0);

	zend_class_implements(phalcon_forms_element_password_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;

}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Password, render) {

	zval *attributes = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes || Z_TYPE_P(attributes) == IS_NULL) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "prepareattributes", attributes);
	zephir_call_static_p1(return_value, "Phalcon\\Tag", "passwordfield", _0);
	RETURN_MM();

}


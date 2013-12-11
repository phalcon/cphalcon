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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"

#include "forms/element/radio.h"
#include "forms/element.h"
#include "forms/elementinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Element\Radio
 *
 * input[type="radio"] for forms
 */
zend_class_entry *phalcon_forms_element_radio_ce;

PHP_METHOD(Phalcon_Forms_Element_Radio, render);

static const zend_function_entry phalcon_forms_element_radio_method_entry[] = {
	PHP_ME(Phalcon_Forms_Element_Radio, render, arginfo_phalcon_forms_elementinterface_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Forms\Element\Radio initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Radio) {

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Radio, forms_element_radio, phalcon_forms_element_ce, phalcon_forms_element_radio_method_entry, 0);

	zend_class_implements(phalcon_forms_element_radio_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Radio, render){

	zval *attributes = NULL, *widget_attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(widget_attributes);
	phalcon_call_method_p2_ex(widget_attributes, &widget_attributes, this_ptr, "prepareattributes", attributes, PHALCON_GLOBAL(z_true));
	phalcon_return_call_static_p1("phalcon\\tag", "radiofield", widget_attributes);
	RETURN_MM();
}

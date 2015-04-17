/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "forms/element/radio.h"
#include "forms/element.h"
#include "forms/elementinterface.h"
#include "forms/element/helpers.h"
#include "kernel/main.h"

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

	phalcon_forms_element_render_helper("radiofield", 1, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

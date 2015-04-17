
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
  +------------------------------------------------------------------------+
*/

#include "forms/element/numeric.h"
#include "forms/element.h"
#include "forms/elementinterface.h"
#include "forms/element/helpers.h"
#include "kernel/main.h"

/**
 * Phalcon\Forms\Element\Numeric
 *
 * Component INPUT[type=number] for forms
 */
zend_class_entry *phalcon_forms_element_numeric_ce;

PHP_METHOD(Phalcon_Forms_Element_Numeric, render);

static const zend_function_entry phalcon_forms_element_numeric_method_entry[] = {
	PHP_ME(Phalcon_Forms_Element_Numeric, render, arginfo_phalcon_forms_elementinterface_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Forms\Element\Numeric initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Numeric){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Numeric, forms_element_numeric, phalcon_forms_element_ce, phalcon_forms_element_numeric_method_entry, 0);

	zend_class_implements(phalcon_forms_element_numeric_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Numeric, render){

	phalcon_forms_element_render_helper("numericfield", 0, INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

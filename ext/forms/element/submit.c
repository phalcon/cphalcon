
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Element\Submit
 *
 * Component INPUT[type=submit] for forms
 */


/**
 * Phalcon\Forms\Element\Submit initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Submit){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Submit, forms_element_submit, "phalcon\\forms\\element", phalcon_forms_element_submit_method_entry, 0);

	zend_class_implements(phalcon_forms_element_submit_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Renders the element widget
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Submit, render){

	zval *attributes = NULL, *widget_attributes, *code;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(widget_attributes);
	phalcon_call_method_p1(widget_attributes, this_ptr, "prepareattributes", attributes);
	
	/** 
	 * Merged passed attributes with previously defined ones
	 */
	PHALCON_INIT_VAR(code);
	PHALCON_CALL_STATIC_PARAMS_1(code, "phalcon\\tag", "submitbutton", widget_attributes);
	RETURN_CCTOR(code);
}


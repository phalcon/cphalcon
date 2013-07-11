
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
 * Phalcon\Forms\Element\Check
 *
 * Component INPUT[type=check] for forms
 */


/**
 * Phalcon\Forms\Element\Check initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Check){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Check, forms_element_check, "phalcon\\forms\\element", phalcon_forms_element_check_method_entry, 0);

	return SUCCESS;
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Check, render){

	zval *attributes = NULL, *use_checked, *widget_attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(use_checked);
	ZVAL_BOOL(use_checked, 1);
	
	PHALCON_INIT_VAR(widget_attributes);
	phalcon_call_method_p2(widget_attributes, this_ptr, "prepareattributes", attributes, use_checked);
	PHALCON_CALL_STATIC_PARAMS_1(return_value, "phalcon\\tag", "checkfield", widget_attributes);
	RETURN_MM();
}


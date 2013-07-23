
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
 * Phalcon\Forms\Element\File
 *
 * Component INPUT[type=file] for forms
 */


/**
 * Phalcon\Forms\Element\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, File, forms_element_file, "phalcon\\forms\\element", phalcon_forms_element_file_method_entry, 0);

	zend_class_implements(phalcon_forms_element_file_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_File, render){

	zval *attributes = NULL, *widget_attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_INIT_VAR(widget_attributes);
	phalcon_call_method_p1(widget_attributes, this_ptr, "prepareattributes", attributes);
	PHALCON_CALL_STATIC_PARAMS_1(return_value, "phalcon\\tag", "filefield", widget_attributes);
	RETURN_MM();
}


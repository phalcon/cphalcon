
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

#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */


/**
 * Phalcon\Forms\Element\Select initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element_Select){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, forms_element_select, phalcon_forms_element_ce, phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("_optionsValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_forms_element_select_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string $name
 * @param object|array $options
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct){

	zval *name, *options = NULL, *attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &name, &options, &attributes);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	phalcon_update_property_this(this_ptr, SL("_optionsValues"), options TSRMLS_CC);
	phalcon_call_parent_p2_noret(this_ptr, phalcon_forms_element_select_ce, "__construct", name, attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the choice's options
 *
 * @param array|object $options
 * @return Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions){

	zval *options;

	phalcon_fetch_params(0, 1, 0, &options);
	
	phalcon_update_property_this(this_ptr, SL("_optionsValues"), options TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions){


	RETURN_MEMBER(this_ptr, "_optionsValues");
}

/**
 * Adds an option to the current options
 *
 * @param array $option
 * @return $this
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption){

	zval *option;

	phalcon_fetch_params(0, 1, 0, &option);
	
	phalcon_update_property_array_append(this_ptr, SL("_optionsValues"), option TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render){

	zval *attributes = NULL, *options, *widget_attributes;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property_this(&options, this_ptr, SL("_optionsValues"), PH_NOISY_CC);
	
	/** 
	 * Merged passed attributes with previously defined ones
	 */
	PHALCON_INIT_VAR(widget_attributes);
	phalcon_call_method_p1(widget_attributes, this_ptr, "prepareattributes", attributes);
	phalcon_call_static_p2(return_value, "phalcon\\tag\\select", "selectfield", widget_attributes, options);
	RETURN_MM();
}


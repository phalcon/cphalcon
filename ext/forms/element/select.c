
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, forms_element_select, "phalcon\\forms\\element", phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &name, &options, &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Forms\\Element\\Select", "__construct", name, attributes);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Adds an option to the current options
 *
 * @param array $option
 * @return $this;
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption){

	zval *option;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &option) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array_append(this_ptr, SL("_options"), option TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Renders the element widget
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render){

	zval *attributes = NULL, *options, *widget_attributes;
	zval *code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(widget_attributes);
	PHALCON_CALL_METHOD_PARAMS_1(widget_attributes, this_ptr, "prepareattributes", attributes);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CALL_STATIC_PARAMS_2(code, "phalcon\\tag\\select", "selectfield", widget_attributes, options);
	RETURN_CCTOR(code);
}


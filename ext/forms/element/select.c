
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
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT for forms
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
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct){

	zval *name, *options = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Forms_Element_Select, setOptions){

	zval *options;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Forms_Element_Select, addOption){

	zval *option;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &option) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_array_append(this_ptr, SL("_options"), option TSRMLS_CC);
	
}

/**
 * Renders the element widget
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render){

	zval *attributes = NULL, *name, *options, *widget_attributes = NULL;
	zval *code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_OBS_VAR(name);
	phalcon_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_INIT_VAR(widget_attributes);
		array_init(widget_attributes);
	} else {
		PHALCON_CPY_WRT(widget_attributes, attributes);
	}
	
	phalcon_array_update_long(&widget_attributes, 0, &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CALL_STATIC_PARAMS_2(code, "phalcon\\tag\\select", "selectfield", widget_attributes, options);
	
	RETURN_CCTOR(code);
}


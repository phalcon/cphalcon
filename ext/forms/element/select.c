
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

#include "forms/element/select.h"
#include "forms/element.h"
#include "forms/elementinterface.h"
#include "tag/select.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
zend_class_entry *phalcon_forms_element_select_ce;

PHP_METHOD(Phalcon_Forms_Element_Select, __construct);
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions);
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions);
PHP_METHOD(Phalcon_Forms_Element_Select, addOption);
PHP_METHOD(Phalcon_Forms_Element_Select, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_addoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_forms_element_select_method_entry[] = {
	PHP_ME(Phalcon_Forms_Element_Select, __construct, arginfo_phalcon_forms_element_select___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_Select, setOptions, arginfo_phalcon_forms_element_select_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, addOption, arginfo_phalcon_forms_element_select_addoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, render, arginfo_phalcon_forms_elementinterface_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	PHALCON_CALL_PARENT(NULL, phalcon_forms_element_select_ce, this_ptr, "__construct", name, attributes);
	
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

	zval **option, *values, *tmp;

	phalcon_fetch_params_ex(1, 0, &option);
	PHALCON_ENSURE_IS_ARRAY(option);

	values = phalcon_fetch_nproperty_this(getThis(), SL("_optionsValues"), PH_NOISY TSRMLS_CC);
	
	ALLOC_ZVAL(tmp);
	if (Z_TYPE_P(values) != IS_ARRAY) {
		MAKE_COPY_ZVAL(option, tmp);
	}
	else {
		add_function(tmp, *option, values TSRMLS_CC);
	}

	Z_SET_REFCOUNT_P(tmp, 0);
	phalcon_update_property_this(getThis(), SL("_optionsValues"), tmp TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Renders the element widget returning html
 *
 * @param array $attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render){

	zval *attributes = NULL, *options, *widget_attributes = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &attributes);
	
	if (!attributes) {
		attributes = PHALCON_GLOBAL(z_null);
	}
	
	options = phalcon_fetch_nproperty_this(this_ptr, SL("_optionsValues"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Merged passed attributes with previously defined ones
	 */
	PHALCON_CALL_METHOD(&widget_attributes, this_ptr, "prepareattributes", attributes);
	PHALCON_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", widget_attributes, options);
	RETURN_MM();
}


#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


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
/**
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_ce, phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("_optionsValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_forms_element_select_ce TSRMLS_CC, 1, phalcon_forms_elementinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string name
 * @param object|array options
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct) {

	zval *name_param = NULL, *options = NULL, *attributes = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &options, &attributes);

		zephir_get_strval(name, name_param);
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}
	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_optionsValues"), options TSRMLS_CC);
	zephir_call_parent_p2_noret(this_ptr, phalcon_forms_element_select_ce, "__construct", name, attributes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Set the choice's options
 *
 * @param array|object options
 * @return Phalcon\Forms\Element
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(this_ptr, SL("_optionsValues"), options TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions) {


	RETURN_MEMBER(this_ptr, "_optionsValues");

}

/**
 * Adds an option to the current options
 *
 * @param array option
 * @return this
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption) {

	zval *option;

	zephir_fetch_params(0, 1, 0, &option);



	zephir_update_property_array_append(this_ptr, SL("_optionsValues"), option TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Renders the element widget returning html
 *
 * @param array attributes
 * @return string
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render) {

	zval *attributes = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes);

	if (!attributes) {
		attributes = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, this_ptr, "prepareattributes", attributes);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_optionsValues"), PH_NOISY_CC);
	zephir_call_static_p2(return_value, "Phalcon\\Tag\\Select", "selectfield", _0, _1);
	RETURN_MM();

}


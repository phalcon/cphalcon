
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
#include "kernel/exception.h"

/**
 * Phalcon\Forms\Element
 *
 * This is a base class for elements of forms
 */


/**
 * Phalcon\Forms\Element initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Element){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Element, forms_element, phalcon_forms_element_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_forms_element_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_element_ce, SL("_validators"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_Forms_Element, __construct){

	zval *name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Forms_Element, setName){

	zval *name;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Forms_Element, getName){


	RETURN_MEMBER(this_ptr, "_name");
}

/**
 * Adds a group of validators
 *
 * @param Phalcon\Validation\ValidatorInterface[]
 */
PHP_METHOD(Phalcon_Forms_Element, addValidators){

	zval *validators;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &validators) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(validators) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an array");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Adds a validator to the element
 *
 * @param Phalcon\Validation\ValidatorInterface
 */
PHP_METHOD(Phalcon_Forms_Element, addValidator){

	zval *validator;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &validator) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The validators parameter must be an array");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the validators registered for the element
 *
 * @return Phalcon\Validation\ValidatorInterface[]
 */
PHP_METHOD(Phalcon_Forms_Element, getValidators){


	RETURN_MEMBER(this_ptr, "_validators");
}


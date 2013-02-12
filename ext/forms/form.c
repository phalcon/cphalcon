
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Forms\Form initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Form){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Form, forms_form, phalcon_forms_form_method_entry, 0);

	zend_declare_property_null(phalcon_forms_form_ce, SL("_entity"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_forms_form_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Forms\Form constructor
 */
PHP_METHOD(Phalcon_Forms_Form, __construct){

	zval *entity;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &entity) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(entity) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The base entity is not valid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_entity"), entity TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Forms_Form, isValid){


	
}

/**
 *
 */
PHP_METHOD(Phalcon_Forms_Form, add){

	zval *element, *name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &element) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(element) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The element is not valid");
		return;
	}
	
	PHALCON_INIT_VAR(name);
	PHALCON_CALL_METHOD(name, element, "getname");
	phalcon_update_property_array(this_ptr, SL("_elements"), name, element TSRMLS_CC);
	
	RETURN_CCTOR(element);
}

PHP_METHOD(Phalcon_Forms_Form, render){

	zval *name, *attributes = NULL, *elements, *exception_message;
	zval *element, *code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!attributes) {
		PHALCON_INIT_VAR(attributes);
	}
	
	PHALCON_OBS_VAR(elements);
	phalcon_read_property(&elements, this_ptr, SL("_elements"), PH_NOISY_CC);
	if (!phalcon_array_isset(elements, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Element with ID=", name, " is not part of the form");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(element);
	phalcon_array_fetch(&element, elements, name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CALL_METHOD_PARAMS_1(code, element, "render", attributes);
	
	RETURN_CCTOR(code);
}



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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\Forms\Manager
 *
 * Manages forms within the application. Allowing the developer to access them from
 * any part of the application
 */


/**
 * Phalcon\Forms\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Manager, forms_manager, phalcon_forms_manager_method_entry, 0);

	zend_declare_property_null(phalcon_forms_manager_ce, SL("_forms"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Creates a form registering it in the forms manager
 *
 * @param string $name
 * @param object $entity
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, create){

	zval *name = NULL, *entity = NULL, *form;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &name, &entity);
	
	if (!name) {
		name = PHALCON_GLOBAL(z_null);
	}
	
	if (!entity) {
		entity = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The form name must be string");
		return;
	}
	
	PHALCON_INIT_VAR(form);
	object_init_ex(form, phalcon_forms_form_ce);
	phalcon_call_method_p1_noret(form, "__construct", entity);
	
	phalcon_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	
	RETURN_CTOR(form);
}

/**
 * Returns a form by its name
 *
 * @param string $name
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, get){

	zval *name, *forms, *exception_message, *form;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(forms);
	phalcon_read_property_this(&forms, this_ptr, SL("_forms"), PH_NOISY_CC);
	if (!phalcon_array_isset(forms, name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "There is no form with name='", name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_forms_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(form);
	phalcon_array_fetch(&form, forms, name, PH_NOISY);
	
	RETURN_CCTOR(form);
}

/**
 * Checks if a form is registered in the forms manager
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Manager, has){

	zval *name, *forms;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_OBS_VAR(forms);
	phalcon_read_property_this(&forms, this_ptr, SL("_forms"), PH_NOISY_CC);
	if (!phalcon_array_isset(forms, name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Registers a form in the Forms Manager
 *
 * @param string $name
 * @param Phalcon\Forms\Form $form
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, set){

	zval *name, *form;

	phalcon_fetch_params(0, 2, 0, &name, &form);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The form name must be string");
		return;
	}
	if (Z_TYPE_P(form) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The form is not valid");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	
	RETURN_THISW();
}


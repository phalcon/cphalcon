
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

#include "forms/manager.h"
#include "forms/form.h"
#include "forms/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"

/**
 * Phalcon\Forms\Manager
 *
 * Manages forms within the application. Allowing the developer to access them from
 * any part of the application
 */
zend_class_entry *phalcon_forms_manager_ce;

PHP_METHOD(Phalcon_Forms_Manager, __construct);
PHP_METHOD(Phalcon_Forms_Manager, create);
PHP_METHOD(Phalcon_Forms_Manager, get);
PHP_METHOD(Phalcon_Forms_Manager, has);
PHP_METHOD(Phalcon_Forms_Manager, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_create, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, form)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_forms_manager_method_entry[] = {
	PHP_ME(Phalcon_Forms_Manager, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Manager, create, arginfo_phalcon_forms_manager_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, get, arginfo_phalcon_forms_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, has, arginfo_phalcon_forms_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, set, arginfo_phalcon_forms_manager_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

static zend_object_handlers phalcon_forms_manager_object_handlers;

static zval* phalcon_forms_manager_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *forms, **res, tmp;

	if (UNEXPECTED(!offset)) {
		return EG(uninitialized_zval_ptr);
	}

	forms = phalcon_fetch_nproperty_this(object, SL("_forms"), PH_NOISY TSRMLS_CC);
	if (UNEXPECTED(Z_TYPE_P(forms)) != IS_ARRAY) {
		return EG(uninitialized_zval_ptr);
	}

	if (type == BP_VAR_RW) {
		type = BP_VAR_R;
	}
	else if (type == BP_VAR_W) {
		type = BP_VAR_IS;
	}

	res = phalcon_hash_get(Z_ARRVAL_P(forms), offset, type);
	if (!res || res == &EG(uninitialized_zval_ptr)) {
		if (UNEXPECTED(Z_TYPE_P(offset) != IS_STRING)) {
			ZVAL_ZVAL(&tmp, offset, 1, 0);
			convert_to_string(&tmp);
			offset = &tmp;
		}

		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "There is no form with name='%s'", Z_STRVAL_P(offset));

		if (UNEXPECTED(offset == &tmp)) {
			zval_dtor(&tmp);
		}

		return NULL;
	}

	return *res;
}

/**
 * Phalcon\Forms\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Forms_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Forms, Manager, forms_manager, phalcon_forms_manager_method_entry, 0);

	zend_declare_property_null(phalcon_forms_manager_ce, SL("_forms"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_forms_manager_object_handlers                = *zend_get_std_object_handlers();
	phalcon_forms_manager_object_handlers.read_dimension = phalcon_forms_manager_read_dimension;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Forms_Manager, __construct)
{
	zval *z;

	PHALCON_ALLOC_GHOST_ZVAL(z);
	array_init(z);
	phalcon_update_property_this(getThis(), SL("_forms"), z TSRMLS_CC);

	Z_OBJ_HT_P(getThis()) = &phalcon_forms_manager_object_handlers;
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
	PHALCON_CALL_METHOD(NULL, form, "__construct", entity);
	
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

	zval **name, *forms, *form;

	phalcon_fetch_params_ex(1, 0, &name);
	PHALCON_ENSURE_IS_STRING(name);
	
	forms = phalcon_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset_fetch(&form, forms, *name)) {
		zend_throw_exception_ex(phalcon_forms_exception_ce, 0 TSRMLS_CC, "There is no form with name='%s'", Z_STRVAL_PP(name));
		return;
	}
	
	RETURN_ZVAL(form, 1, 0);
}

/**
 * Checks if a form is registered in the forms manager
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Manager, has){

	zval *name, *forms;

	phalcon_fetch_params(0, 1, 0, &name);
	
	forms = phalcon_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY TSRMLS_CC);
	RETURN_BOOL(phalcon_array_isset(forms, name));
}

/**
 * Registers a form in the Forms Manager
 *
 * @param string $name
 * @param Phalcon\Forms\Form $form
 * @return Phalcon\Forms\Manager
 */
PHP_METHOD(Phalcon_Forms_Manager, set){

	zval **name, **form;

	phalcon_fetch_params_ex(2, 0, &name, &form);
	PHALCON_ENSURE_IS_STRING(name);
	PHALCON_VERIFY_CLASS_EX(*form, phalcon_forms_form_ce, phalcon_forms_exception_ce, 0);
	
	phalcon_update_property_array(this_ptr, SL("_forms"), *name, *form TSRMLS_CC);
	RETURN_THISW();
}


#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Forms_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms, Manager, phalcon, forms_manager, phalcon_forms_manager_method_entry, 0);

	zend_declare_property_null(phalcon_forms_manager_ce, SL("_forms"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Creates a form registering it in the forms manager
 *
 * @param string name
 * @param object entity
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, create) {

	zval *name = NULL, *entity = NULL, *form;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name, &entity);

	if (!name) {
		ZEPHIR_CPY_WRT(name, ZEPHIR_GLOBAL(global_null));
	}
	if (!entity) {
		ZEPHIR_CPY_WRT(entity, ZEPHIR_GLOBAL(global_null));
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_forms_exception_ce, "The form name must be string");
		return;
	}
	ZEPHIR_INIT_VAR(form);
	object_init_ex(form, phalcon_forms_form_ce);
	zephir_call_method_p1_noret(form, "__construct", entity);
	zephir_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	RETURN_CCTOR(form);

}

/**
 * Returns a form by its name
 *
 * @param string name
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, get) {

	zval *name, *form, *forms, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_OBS_VAR(forms);
	zephir_read_property_this(&forms, this_ptr, SL("_forms"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(form);
	if (!(zephir_array_isset_fetch(&form, forms, name))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "There is no form with name='", name);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, _1, "'");
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(form);

}

/**
 * Checks if a form is registered in the forms manager
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Manager, has) {

	zval *name, *forms;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	ZEPHIR_OBS_VAR(forms);
	zephir_read_property_this(&forms, this_ptr, SL("_forms"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(forms, name));

}

/**
 * Registers a form in the Forms Manager
 *
 * @param string name
 * @param Phalcon\Forms\Form form
 * @return Phalcon\Forms\Form
 */
PHP_METHOD(Phalcon_Forms_Manager, set) {

	zval *name, *form;

	zephir_fetch_params(0, 2, 0, &name, &form);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The form name must be string");
		return;
	}
	if (Z_TYPE_P(form) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_forms_exception_ce, "The form is not valid");
		return;
	}
	zephir_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	RETURN_THISW();

}


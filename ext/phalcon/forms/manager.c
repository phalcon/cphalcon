
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
#include "kernel/operators.h"


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
 * Phalcon\Forms\Manager
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
		name = ZEPHIR_GLOBAL(global_null);
	}
	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(name) != IS_STRING)) {
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

	zval *name_param = NULL, *form, *forms, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	forms = zephir_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&form, forms, name, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "There is no form with name='", name, "'");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(form);

}

/**
 * Checks if a form is registered in the forms manager
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Forms_Manager, has) {

	zval *name_param = NULL, *forms;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	forms = zephir_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY_CC);
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

	zval *name_param = NULL, *form;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &form);

		zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	RETURN_THIS();

}


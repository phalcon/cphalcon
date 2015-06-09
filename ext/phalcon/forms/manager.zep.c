
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, *entity = NULL, *form;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name, &entity);

	if (!name) {
		name = ZEPHIR_GLOBAL(global_null);
	}
	if (!entity) {
		entity = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_forms_exception_ce, "The form name must be string", "phalcon/forms/manager.zep", 41);
		return;
	}
	ZEPHIR_INIT_VAR(form);
	object_init_ex(form, phalcon_forms_form_ce);
	ZEPHIR_CALL_METHOD(NULL, form, "__construct", NULL, 193, entity);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_forms"), name, form TSRMLS_CC);
	RETURN_CCTOR(form);

}

/**
 * Returns a form by its name
 */
PHP_METHOD(Phalcon_Forms_Manager, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *form, *_0, *_1;
	zval *name = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(form);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&form, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "There is no form with name='", name, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/forms/manager.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(form);

}

/**
 * Checks if a form is registered in the forms manager
 */
PHP_METHOD(Phalcon_Forms_Manager, has) {

	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_forms"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, name));

}

/**
 * Registers a form in the Forms Manager
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


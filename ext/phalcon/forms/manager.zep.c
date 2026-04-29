
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Forms Manager
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms, Manager, phalcon, forms_manager, phalcon_forms_manager_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_forms_manager_ce, SL("forms"), ZEND_ACC_PROTECTED);
	phalcon_forms_manager_ce->create_object = zephir_init_properties_Phalcon_Forms_Manager;

	return SUCCESS;
}

/**
 * Creates a form registering it in the forms manager
 *
 * @param object entity
 */
PHP_METHOD(Phalcon_Forms_Manager, create)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *entity = NULL, entity_sub, __$null, form;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&form);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(entity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		entity = ZEND_CALL_ARG(execute_data, 2);
	}
	ZVAL_STR_COPY(&name_zv, name);
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	ZEPHIR_INIT_VAR(&form);
	object_init_ex(&form, phalcon_forms_form_ce);
	ZEPHIR_CALL_METHOD(NULL, &form, "__construct", NULL, 324, entity);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("forms"), &name_zv, &form);
	RETURN_CCTOR(&form);
}

/**
 * Returns a form by its name
 */
PHP_METHOD(Phalcon_Forms_Manager, get)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, form, _0, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&form);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&form);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("forms"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&form, &_0, &name_zv, 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "There is no form with name='", &name_zv, "'");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 32, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/Manager.zep", 46);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&form);
}

/**
 * Checks if a form is registered in the forms manager
 */
PHP_METHOD(Phalcon_Forms_Manager, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("forms"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &name_zv));
}

/**
 * Registers a form in the Forms Manager
 */
PHP_METHOD(Phalcon_Forms_Manager, set)
{
	zval name_zv, *form, form_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&form_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJECT_OF_CLASS(form, phalcon_forms_form_ce)
	ZEND_PARSE_PARAMETERS_END();
	form = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("forms"), &name_zv, form);
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Forms_Manager(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("forms"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("forms"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}


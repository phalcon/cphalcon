
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * @phpstan-import-type ForwardTarget from Access
 * @phpstan-import-type AccessContext from Access
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AbstractAccess)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Access, AbstractAccess, phalcon, auth_access_abstractaccess, phalcon_auth_access_abstractaccess_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_auth_access_abstractaccess_ce, SL("exceptActions"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_auth_access_abstractaccess_ce, SL("onlyActions"), ZEND_ACC_PROTECTED);
	phalcon_auth_access_abstractaccess_ce->create_object = zephir_init_properties_Phalcon_Auth_Access_AbstractAccess;

	zend_class_implements(phalcon_auth_access_abstractaccess_ce, 1, phalcon_contracts_auth_access_access_ce);
	return SUCCESS;
}

/**
 * @phpstan-return list<string>
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getExceptActions)
{

	RETURN_MEMBER_TYPED(getThis(), "exceptActions", IS_ARRAY);
}

/**
 * @phpstan-return list<string>
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getOnlyActions)
{

	RETURN_MEMBER_TYPED(getThis(), "onlyActions", IS_ARRAY);
}

/**
 * @phpstan-param AccessContext $context
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, isAllowed)
{
	zend_bool _1$$3, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zend_string *actionName = NULL;
	zval *guard, guard_sub, actionName_zv, *context_param = NULL, __$true, allowed, _0, _4, _2$$3, _3$$3, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard_sub);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&allowed);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&context);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	guard = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		context_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	ZEPHIR_CALL_METHOD(&allowed, this_ptr, "allowedif", NULL, 0, guard);
	zephir_check_call_status();
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		_1$$3 = zephir_is_true(&allowed);
		if (!(_1$$3)) {
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "in_array", NULL, 79, &actionName_zv, &_2$$3, &__$true);
			zephir_check_call_status();
			_1$$3 = zephir_is_true(&_3$$3);
		}
		RETURN_MM_BOOL(_1$$3);
	}
	zephir_memory_observe(&_4);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_4))) {
		_5$$4 = zephir_is_true(&allowed);
		if (_5$$4) {
			zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_7$$4, "in_array", NULL, 79, &actionName_zv, &_6$$4, &__$true);
			zephir_check_call_status();
			_5$$4 = zephir_is_true(&_7$$4);
		}
		RETURN_MM_BOOL(_5$$4);
	}
	RETURN_CCTOR(&allowed);
}

/**
 * @phpstan-return ForwardTarget|null
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, redirectTo)
{

	RETURN_NULL();
}

/**
 * @param list<string> $exceptActions
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setExceptActions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *exceptActions_param = NULL;
	zval exceptActions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exceptActions);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(exceptActions, exceptActions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &exceptActions_param);
	if (!exceptActions_param) {
		ZEPHIR_INIT_VAR(&exceptActions);
		array_init(&exceptActions);
	} else {
		zephir_get_arrval(&exceptActions, exceptActions_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("exceptActions"), &exceptActions);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param list<string> $onlyActions
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setOnlyActions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *onlyActions_param = NULL;
	zval onlyActions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&onlyActions);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(onlyActions, onlyActions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &onlyActions_param);
	if (!onlyActions_param) {
		ZEPHIR_INIT_VAR(&onlyActions);
		array_init(&onlyActions);
	} else {
		zephir_get_arrval(&onlyActions, onlyActions_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("onlyActions"), &onlyActions);
	ZEPHIR_MM_RESTORE();
}

/**
 * Whether the gate's base condition holds for the given identity.
 */
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, allowedIf)
{
}

zend_object *zephir_init_properties_Phalcon_Auth_Access_AbstractAccess(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("onlyActions"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("exceptActions"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}


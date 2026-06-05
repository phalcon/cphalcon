
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


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
 * @phpstan-type AuthUserRow array{id?: int|string}&array<string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Config_MemoryAdapterConfig)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter\\Config, MemoryAdapterConfig, phalcon, auth_adapter_config_memoryadapterconfig, phalcon_auth_adapter_config_abstractadapterconfig_ce, phalcon_auth_adapter_config_memoryadapterconfig_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_auth_adapter_config_memoryadapterconfig_ce, SL("users"), ZEND_ACC_PROTECTED);
	phalcon_auth_adapter_config_memoryadapterconfig_ce->create_object = zephir_init_properties_Phalcon_Auth_Adapter_Config_MemoryAdapterConfig;

	return SUCCESS;
}

/**
 * @phpstan-param list<AuthUserRow> $users
 */
PHP_METHOD(Phalcon_Auth_Adapter_Config_MemoryAdapterConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *model = NULL;
	zval *users_param = NULL, model_zv;
	zval users;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&users);
	ZVAL_UNDEF(&model_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(users, users_param)
		Z_PARAM_STR_OR_NULL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 0) {
		users_param = ZEND_CALL_ARG(execute_data, 1);
	}
	if (!users_param) {
		ZEPHIR_INIT_VAR(&users);
		array_init(&users);
	} else {
		zephir_get_arrval(&users, users_param);
	}
	if (!model) {
		ZEPHIR_INIT_VAR(&model_zv);
	} else {
		zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("users"), &users);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_config_memoryadapterconfig_ce, getThis(), "__construct", NULL, 0, &model_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return list<AuthUserRow>
 */
PHP_METHOD(Phalcon_Auth_Adapter_Config_MemoryAdapterConfig, getUsers)
{

	RETURN_MEMBER_TYPED(getThis(), "users", IS_ARRAY);
}

zend_object *zephir_init_properties_Phalcon_Auth_Adapter_Config_MemoryAdapterConfig(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("users"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("users"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}


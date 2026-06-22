
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Config_ModelAdapterConfig)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter\\Config, ModelAdapterConfig, phalcon, auth_adapter_config_modeladapterconfig, phalcon_auth_adapter_config_abstractadapterconfig_ce, phalcon_auth_adapter_config_modeladapterconfig_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_auth_adapter_config_modeladapterconfig_ce, SL("idColumn"), "id", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Adapter_Config_ModelAdapterConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, idColumn_zv, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4;
	zend_string *model = NULL, *idColumn = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&idColumn_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(model)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(idColumn)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	if (!idColumn) {
		idColumn = zend_string_init(ZEND_STRL("id"), 0);
		zephir_memory_observe(&idColumn_zv);
		ZVAL_STR(&idColumn_zv, idColumn);
	} else {
		zephir_memory_observe(&idColumn_zv);
	ZVAL_STR_COPY(&idColumn_zv, idColumn);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&model_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Model adapter");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "model");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, " class name");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 320, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Adapter/Config/ModelAdapterConfig.zep", 36);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&idColumn_zv, "")) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "Model adapter");
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "idColumn");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 320, &_5$$4, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Auth/Adapter/Config/ModelAdapterConfig.zep", 43);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("idColumn"), &idColumn_zv);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_config_modeladapterconfig_ce, getThis(), "__construct", NULL, 0, &model_zv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_ModelAdapterConfig, getIdColumn)
{

	RETURN_MEMBER_TYPED(getThis(), "idColumn", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_ModelAdapterConfig, getModel)
{

	RETURN_MEMBER_TYPED(getThis(), "model", IS_STRING);
}


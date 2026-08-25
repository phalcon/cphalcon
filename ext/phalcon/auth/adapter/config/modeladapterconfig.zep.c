
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

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "id", sizeof("id") - 1);
		zephir_declare_typed_property(phalcon_auth_adapter_config_modeladapterconfig_ce, SL("idColumn"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Adapter_Config_ModelAdapterConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval model_zv, idColumn_zv, _0, _1, _2;
	zend_string *model = NULL, *idColumn = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&idColumn_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("idColumn", 8, 1);
	}

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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Model adapter");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "model");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " class name");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce, "assert", NULL, 0, &model_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Model adapter");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "idColumn");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce, "assert", NULL, 0, &idColumn_zv, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 434, &idColumn_zv);
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


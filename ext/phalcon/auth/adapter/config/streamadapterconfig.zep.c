
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
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Config_StreamAdapterConfig)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter\\Config, StreamAdapterConfig, phalcon, auth_adapter_config_streamadapterconfig, phalcon_auth_adapter_config_streamadapterconfig_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_adapter_config_streamadapterconfig_ce, SL("file"), ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_auth_adapter_config_streamadapterconfig_ce, SL("model"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_adapter_config_streamadapterconfig_ce, 1, phalcon_contracts_auth_adapter_adapterconfig_ce);
	return SUCCESS;
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Adapter_Config_StreamAdapterConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, model_zv, _0$$3, _1$$3, _2$$3, _3$$3;
	zend_string *file = NULL, *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&model_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!model) {
		ZEPHIR_INIT_VAR(&model_zv);
	} else {
		zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&file_zv, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_configrequiresnonemptyvalue_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Stream adapter");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "file");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, " path");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 326, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Adapter/Config/StreamAdapterConfig.zep", 40);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &file_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &model_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_StreamAdapterConfig, getFile)
{

	RETURN_MEMBER_TYPED(getThis(), "file", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_StreamAdapterConfig, getModel)
{

	RETURN_MEMBER(getThis(), "model");
}


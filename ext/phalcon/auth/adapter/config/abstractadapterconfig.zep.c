
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
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Config_AbstractAdapterConfig)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Adapter\\Config, AbstractAdapterConfig, phalcon, auth_adapter_config_abstractadapterconfig, phalcon_auth_adapter_config_abstractadapterconfig_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_auth_adapter_config_abstractadapterconfig_ce, SL("model"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_adapter_config_abstractadapterconfig_ce, 1, phalcon_contracts_auth_adapter_adapterconfig_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_AbstractAdapterConfig, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval model_zv;
	zend_string *model = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!model) {
		ZEPHIR_INIT_VAR(&model_zv);
	} else {
		zephir_memory_observe(&model_zv);
	ZVAL_STR_COPY(&model_zv, model);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &model_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_AbstractAdapterConfig, getModel)
{

	RETURN_MEMBER(getThis(), "model");
}


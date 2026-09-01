
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Shared model-name state and accessor for auth adapter configurations.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Config_Traits_ModelConfigTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Auth\\Adapter\\Config\\Traits, ModelConfigTrait, phalcon, auth_adapter_config_traits_modelconfigtrait, phalcon_auth_adapter_config_traits_modelconfigtrait_method_entry);

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_auth_adapter_config_traits_modelconfigtrait_ce, SL("model"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Config_Traits_ModelConfigTrait, getModel)
{

	RETURN_MEMBER(getThis(), "model");
}


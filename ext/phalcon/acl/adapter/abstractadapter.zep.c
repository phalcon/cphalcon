
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
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Functionality common to all adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, AbstractAdapter, phalcon, acl_adapter_abstractadapter, phalcon_events_abstracteventsaware_ce, phalcon_acl_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Access Granted
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_abstractadapter_ce, SL("accessGranted"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Active access which the list is checking if some role can access it
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_acl_adapter_abstractadapter_ce, SL("activeAccess"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * Component which the list is checking if some role can access it
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_acl_adapter_abstractadapter_ce, SL("activeComponent"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * Role which the list is checking if it's allowed to certain
	 * component/access
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_acl_adapter_abstractadapter_ce, SL("activeRole"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * Default access
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_abstractadapter_ce, SL("defaultAccess"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_acl_adapter_abstractadapter_ce, 1, phalcon_acl_adapter_adapterinterface_ce);
	zend_class_implements(phalcon_acl_adapter_abstractadapter_ce, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;
}

/**
 * Returns the access which the list is checking if a role can access it
 */
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveAccess)
{

	RETURN_MEMBER(getThis(), "activeAccess");
}

/**
 * Returns the component which the list is checking if some role can access
 * it
 */
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveComponent)
{

	RETURN_MEMBER(getThis(), "activeComponent");
}

/**
 * Returns the role which the list is checking if it's allowed to certain
 * component/access
 */
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getActiveRole)
{

	RETURN_MEMBER(getThis(), "activeRole");
}

/**
 * Returns the default action
 */
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, getDefaultAction)
{

	RETURN_MEMBER_TYPED(getThis(), "defaultAccess", IS_LONG);
}

/**
 * Sets the default access level
 * (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter_AbstractAdapter, setDefaultAction)
{
	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("defaultAccess", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(defaultAccess)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 135, &_0);
}



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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Acl\Adapter
 *
 * Adapter for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Adapter, phalcon, acl_adapter, phalcon_acl_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Active access which the list is checking if some role can access it
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("activeAccess"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access Granted
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("accessGranted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Role which the list is checking if it's allowed to certain component/access
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("activeRole"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Component which the list is checking if some role can access it
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("activeComponent"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default access
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("defaultAccess"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Events manager
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_adapter_ce TSRMLS_CC, 1, phalcon_acl_adapterinterface_ce);
	zend_class_implements(phalcon_acl_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Active access which the list is checking if some role can access it
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeAccess");

}

/**
 * Role which the list is checking if it's allowed to certain component/access
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeRole");

}

/**
 * Component which the list is checking if some role can access it
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveComponent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeComponent");

}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultAccess");

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "eventsManager");

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("defaultAccess"), &_0);

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("eventsManager"), eventsManager);

}


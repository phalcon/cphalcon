
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
 * Phalcon\Acl\Adapter
 *
 * Adapter for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Adapter, phalcon, acl_adapter, phalcon_acl_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Events manager
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default access
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("_defaultAccess"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access Granted
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("_accessGranted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Role which the list is checking if it's allowed to certain resource/access
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeRole"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Resource which the list is checking if some role can access it
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeResource"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Active access which the list is checking if some role can access it
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeAccess"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_adapter_ce TSRMLS_CC, 1, phalcon_acl_adapterinterface_ce);
	zend_class_implements(phalcon_acl_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Role which the list is checking if it's allowed to certain resource/access
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_activeRole");

}

/**
 * Resource which the list is checking if some role can access it
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveResource) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_activeResource");

}

/**
 * Active access which the list is checking if some role can access it
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_activeAccess");

}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager) {

	zval *eventsManager, eventsManager_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_zval(this_ptr, SL("_eventsManager"), eventsManager);

}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 */
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	int defaultAccess;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("_defaultAccess"), &_0);

}

/**
 * Returns the default ACL access level
 */
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_defaultAccess");

}


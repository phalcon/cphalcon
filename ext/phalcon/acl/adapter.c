
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Acl\Adapter
 *
 * Adapter for Phalcon\Acl adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Acl, Adapter, phalcon, acl_adapter, phalcon_acl_adapter_method_entry, 0);

/**
 * Events manager
 * "@var mixed
 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_eventsManager"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Default access
 * "@var bool
 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("_defaultAccess"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Access Granted
 * "@var bool
 */
	zend_declare_property_bool(phalcon_acl_adapter_ce, SL("_accessGranted"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Events manager
 * "@var mixed
 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeRole"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Active resource
 * "@var mixed
 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeResource"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Active Access
 * "@var mixed
 */
	zend_declare_property_null(phalcon_acl_adapter_ce, SL("_activeAccess"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 *
 * @param int defaultAccess
 */
PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction) {

	zval *defaultAccess_param = NULL, *_0;
	int defaultAccess;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultAccess_param);

		defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("_defaultAccess"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default ACL access level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction) {


	RETURN_MEMBER(this_ptr, "_defaultAccess");

}

/**
 * Returns the role which the list is checking if it's allowed to certain resource/access
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole) {


	RETURN_MEMBER(this_ptr, "_activeRole");

}

/**
 * Returns the resource which the list is checking if some role can access it
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveResource) {


	RETURN_MEMBER(this_ptr, "_activeResource");

}

/**
 * Returns the access which the list is checking if some role can access it
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess) {


	RETURN_MEMBER(this_ptr, "_activeAccess");

}


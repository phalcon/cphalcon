
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Dispatcher\Firewall\AdapterInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher\Firewall adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Firewall_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Firewall, AdapterInterface, phalcon, firewall_adapterinterface, phalcon_firewall_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the default ACL access level
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, getDefaultAccess);

/**
 * Gets role callback to fetch role name
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, getRoleCallback);

/**
 * Gets always resolving role option
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, isAlwaysResolvingRole);

/**
 * Sets always resolving role option
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, setAlwaysResolvingRole);

/**
 * Sets cache backend
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, setCache);

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, setDefaultAccess);

/**
 * Sets role callback to fetch role name
 */
ZEPHIR_DOC_METHOD(Phalcon_Firewall_AdapterInterface, setRoleCallback);


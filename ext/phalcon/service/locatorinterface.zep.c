
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
 * Phalcon\Service\LocatorInterface
 *
 * Interface for the Locator
 */
ZEPHIR_INIT_CLASS(Phalcon_Service_LocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Service, LocatorInterface, phalcon, service_locatorinterface, phalcon_service_locatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Get a helper. If it is not in the mapper array, create a new object,
 * set it and then return it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Service_LocatorInterface, get);

/**
 * Checks if a helper exists in the map array
 */
ZEPHIR_DOC_METHOD(Phalcon_Service_LocatorInterface, has);

/**
 * Set a new helper to the mapper array
 */
ZEPHIR_DOC_METHOD(Phalcon_Service_LocatorInterface, set);


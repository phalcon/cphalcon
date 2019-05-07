
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
 * Phalcon\Service\LocatorFactoryInterface
 *
 * Interface for a Locator Factory
 */
ZEPHIR_INIT_CLASS(Phalcon_Service_LocatorFactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Service, LocatorFactoryInterface, phalcon, service_locatorfactoryinterface, phalcon_service_locatorfactoryinterface_method_entry);

	return SUCCESS;

}

/**
 * New instance of the locator
 */
ZEPHIR_DOC_METHOD(Phalcon_Service_LocatorFactoryInterface, newInstance);


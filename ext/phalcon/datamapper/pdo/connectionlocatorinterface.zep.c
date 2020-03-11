
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Locates PDO connections for default, read, and write databases.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\DataMapper\\Pdo, ConnectionLocatorInterface, phalcon, datamapper_pdo_connectionlocatorinterface, phalcon_datamapper_pdo_connectionlocatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Returns the default connection object.
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getMaster);

/**
 * Returns a read connection by name; if no name is given, picks a
 * random connection; if no read connections are present, returns the
 * default connection.
 *
 * @param string $name
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getRead);

/**
 * Returns a write connection by name; if no name is given, picks a
 * random connection; if no write connections are present, returns the
 * default connection.
 *
 * @param string $name
 *
 * @return ConnectionInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getWrite);

/**
 * Sets the default connection registry entry.
 *
 * @param ConnectionInterface $callable
 *
 * @return ConnectionLocatorInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setMaster);

/**
 * Sets a read connection registry entry by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return ConnectionLocatorInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setRead);

/**
 * Sets a write connection registry entry by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return ConnectionLocatorInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setWrite);



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
 */
/**
 * Interface for Phalcon\Logger adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Storage\\Adapter, AdapterInterface, phalcon, storage_adapter_adapterinterface, phalcon_storage_adapter_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Flushes/clears the cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, clear);
/**
 * Decrements a stored number
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, decrement);
/**
 * Deletes data from the adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, delete);
/**
 * Reads data from the adapter
 *
 * @param string key
 * @param mixed|null defaultValue
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, get);
/**
 * Returns the already connected adapter or connects to the backend
 * server(s)
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, getAdapter);
/**
 * Returns all the keys stored
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, getKeys);
/**
 * Returns the prefix for the keys
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, getPrefix);
/**
 * Checks if an element exists in the cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, has);
/**
 * Increments a stored number
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, increment);
/**
 * Stores data in the adapter
 *
 * @param string key
 * @param mixed value
 * @param \DateInterval|int|null ttl
 */
ZEPHIR_DOC_METHOD(Phalcon_Storage_Adapter_AdapterInterface, set);

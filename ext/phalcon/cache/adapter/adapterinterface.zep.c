
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
 * Interface for Phalcon\Cache adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cache\\Adapter, AdapterInterface, phalcon, cache_adapter_adapterinterface, NULL);

	zend_class_implements(phalcon_cache_adapter_adapterinterface_ce, 1, phalcon_storage_adapter_adapterinterface_ce);
	return SUCCESS;
}


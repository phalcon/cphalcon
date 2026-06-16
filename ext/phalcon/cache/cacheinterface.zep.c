
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Cache\Cache
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Cache\Cache} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cache, CacheInterface, phalcon, cache_cacheinterface, NULL);

	zend_class_implements(phalcon_cache_cacheinterface_ce, 1, phalcon_contracts_cache_cache_ce);
	return SUCCESS;
}


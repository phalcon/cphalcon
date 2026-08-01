
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

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
 * RedisCluster adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Adapter_RedisCluster)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Adapter, RedisCluster, phalcon, cache_adapter_rediscluster, phalcon_storage_adapter_rediscluster_ce, NULL, 0);

	/**
	 * EventType prefix.
	 */
	zend_declare_property_string(phalcon_cache_adapter_rediscluster_ce, SL("eventType"), "cache", ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_cache_adapter_rediscluster_ce, 1, phalcon_cache_adapter_adapterinterface_ce);
	return SUCCESS;
}


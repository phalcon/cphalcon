
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
 * Central registry of the array shapes used across the Storage namespace.
 *
 * @phpstan-type storage_keys array<array-key, string>
 * @phpstan-type storage_options array<string, mixed>
 * @phpstan-type storage_serializer_data array<array-key, mixed>
 * @phpstan-type storage_services array<string, class-string>
 * @phpstan-type storage_adapter_options array{
 *     defaultSerializer?: string,
 *     lifetime?: int,
 *     prefix?: string,
 *     serializer?: SerializerInterface|null,
 *     stripPrefix?: bool,
 * }
 * @phpstan-type storage_libmemcached_client array<int, mixed>
 * @phpstan-type storage_libmemcached_sasl array{
 *     pass?: string,
 *     user?: string,
 * }
 * @phpstan-type storage_libmemcached_servers array<array-key, array<array-key, mixed>>
 * @phpstan-type storage_libmemcached_options array{
 *     client?: storage_libmemcached_client,
 *     defaultSerializer?: string,
 *     lifetime?: int,
 *     persistentId?: string,
 *     prefix?: string,
 *     saslAuthData?: storage_libmemcached_sasl,
 *     serializer?: SerializerInterface|null,
 *     servers?: storage_libmemcached_servers,
 *     stripPrefix?: bool,
 * }
 * @phpstan-type storage_libmemcached_settings array{
 *     client?: storage_libmemcached_client,
 *     persistentId?: string,
 *     saslAuthData?: storage_libmemcached_sasl,
 *     servers?: storage_libmemcached_servers,
 * }
 * @phpstan-type storage_memory_data array<string, mixed>
 * @phpstan-type storage_redis_ssl array<string, mixed>
 * @phpstan-type storage_redis_context array{
 *     auth?: array{0: string|false|null, 1?: string},
 *     stream?: storage_redis_ssl,
 * }
 * @phpstan-type storage_redis_options array{
 *     auth?: array<array-key, string>|string,
 *     connectTimeout?: float|int,
 *     defaultSerializer?: string,
 *     host?: string,
 *     index?: int,
 *     lifetime?: int,
 *     persistent?: bool,
 *     persistentId?: string,
 *     port?: int,
 *     prefix?: string,
 *     readTimeout?: float|int,
 *     retryInterval?: int,
 *     serializer?: SerializerInterface|null,
 *     socket?: string,
 *     ssl?: storage_redis_ssl,
 *     stripPrefix?: bool,
 *     timeout?: float|int,
 * }
 * @phpstan-type storage_redis_settings array{
 *     auth: array<array-key, string>|string,
 *     connectTimeout: float|int,
 *     host: string,
 *     index: int,
 *     persistent: bool,
 *     persistentId: string,
 *     port: int,
 *     readTimeout: float|int,
 *     retryInterval: int,
 *     socket: string,
 *     ssl: storage_redis_ssl,
 *     timeout: float|int,
 * }
 * @phpstan-type storage_rediscluster_context array<string, mixed>
 * @phpstan-type storage_rediscluster_options array{
 *     auth?: array<array-key, string>|string,
 *     context?: storage_rediscluster_context|null,
 *     defaultSerializer?: string,
 *     hosts?: array<array-key, string>,
 *     lifetime?: int,
 *     name?: string|null,
 *     persistent?: bool,
 *     prefix?: string,
 *     readTimeout?: float|int,
 *     serializer?: SerializerInterface|null,
 *     stripPrefix?: bool,
 *     timeout?: float|int,
 * }
 * @phpstan-type storage_rediscluster_settings array{
 *     auth: array<array-key, string>|string,
 *     context: storage_rediscluster_context|null,
 *     hosts: array<array-key, string>,
 *     name: string|null,
 *     persistent: bool,
 *     readTimeout: float|int,
 *     timeout: float|int,
 * }
 * @phpstan-type storage_stream_options array{
 *     defaultSerializer?: string,
 *     lifetime?: int,
 *     prefix?: string,
 *     serializer?: SerializerInterface|null,
 *     storageDir?: string,
 *     stripPrefix?: bool,
 * }
 * @phpstan-type storage_stream_payload array{
 *     content?: mixed,
 *     created?: int,
 *     ttl?: int|string,
 * }
 * @phpstan-type storage_weak_list array<string, WeakReference<object>>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Storage_StorageTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Storage, StorageTypes, phalcon, contracts_storage_storagetypes, NULL);

	return SUCCESS;
}


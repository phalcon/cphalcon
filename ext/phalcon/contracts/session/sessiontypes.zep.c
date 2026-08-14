
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
 * Central registry of the array shapes used across the Session namespace.
 *
 * @phpstan-type session_bag_data array<array-key, mixed>
 * @phpstan-type session_files list<string>
 * @phpstan-type session_options array<string, mixed>
 * @phpstan-type session_libmemcached_options array{
 *     defaultSerializer?: string,
 *     lifetime?: int,
 *     prefix?: string,
 *     serializer?: SerializerInterface|null,
 *     servers?: array<array-key, array<array-key, mixed>>,
 *     stripPrefix?: bool,
 * }
 * @phpstan-type session_redis_options array{
 *     auth?: array<array-key, string>|string,
 *     defaultSerializer?: string,
 *     host?: string,
 *     index?: int,
 *     lifetime?: int,
 *     lockExpiry?: int,
 *     lockingEnabled?: bool,
 *     lockRetries?: int,
 *     lockWaitTime?: int,
 *     persistent?: bool,
 *     port?: int,
 *     prefix?: string,
 *     serializer?: SerializerInterface|null,
 *     socket?: string,
 *     stripPrefix?: bool,
 * }
 * @phpstan-type session_stream_options array{
 *     prefix?: string,
 *     savePath?: string,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Session_SessionTypes)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Session, SessionTypes, phalcon, contracts_session_sessiontypes, NULL);

	return SUCCESS;
}


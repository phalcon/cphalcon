
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Exceptions\Exception;
use Phalcon\Storage\Adapter\Redis as StorageRedis;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;

/**
 * Connects to a Redis server (ext-redis) and builds a RedisContext. The
 * connection (connect/pconnect, auth, database select) is delegated to
 * Phalcon\Storage\Adapter\Redis so the queue reuses the framework's hardened
 * connection handling instead of re-implementing it.
 *
 * Options:
 *   - host:         server host (default 127.0.0.1).
 *   - port:         server port (default 6379).
 *   - timeout:      connection timeout in seconds (default 0).
 *   - persistent:   use a persistent connection (default false).
 *   - persistentId: identifier for the persistent connection.
 *   - auth:         password, or [user, password] for ACL auth.
 *   - index:        database index to SELECT (default 0).
 *   - prefix:       key prefix for every queue (default "phalcon_queue:").
 *   - pollInterval: milliseconds between subscription poll passes (default 200).
 */
class RedisConnectionFactory implements ConnectionFactoryInterface
{
    /**
     * @var array
     */
    protected options = [];

    public function __construct(array options = [])
    {
        let this->options = options;
    }

    public function createContext() -> <ContextInterface>
    {
        var options, adapter, redis, prefix, pollInterval, e;

        let options      = this->options,
            prefix       = isset options["prefix"] ? options["prefix"] : "phalcon_queue:",
            pollInterval = isset options["pollInterval"] ? (int) options["pollInterval"] : 200;

        /**
         * Disable the cache adapter's own key prefix and serializer so the
         * queue keeps full control of its keys and message payloads; otherwise
         * keys would be double-prefixed and payloads double-encoded. The
         * adapter also performs authentication and database selection, so none
         * of that is repeated here.
         */
        let adapter = new StorageRedis(
            new SerializerFactory(),
            array_merge(
                options,
                [
                    "prefix"            : "",
                    "defaultSerializer" : "none"
                ]
            )
        );

        /**
         * Surface connect/auth/select failures as a queue exception so every
         * adapter honours the QueueThrowable contract.
         */
        try {
            let redis = adapter->getAdapter();
        } catch StorageException, e {
            throw new Exception(e->getMessage(), (int) e->getCode(), e);
        }

        return new RedisContext(redis, prefix, pollInterval);
    }
}

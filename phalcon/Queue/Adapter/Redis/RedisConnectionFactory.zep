
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Redis;

use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Queue\Exceptions\Exception;

/**
 * Connects to a Redis server (ext-redis) and builds a RedisContext.
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
        var options, redis, host, port, timeout, persistent, persistentId,
            auth, index, prefix, pollInterval, parameter, result;

        let options      = this->options,
            host         = isset options["host"] ? options["host"] : "127.0.0.1",
            port         = isset options["port"] ? (int) options["port"] : 6379,
            timeout      = isset options["timeout"] ? (double) options["timeout"] : 0.0,
            persistent   = isset options["persistent"] ? (bool) options["persistent"] : false,
            persistentId = isset options["persistentId"] ? options["persistentId"] : "",
            auth         = isset options["auth"] ? options["auth"] : "",
            index        = isset options["index"] ? (int) options["index"] : 0,
            prefix       = isset options["prefix"] ? options["prefix"] : "phalcon_queue:",
            pollInterval = isset options["pollInterval"] ? (int) options["pollInterval"] : 200;

        let redis = new \Redis();

        if persistent {
            let parameter = !empty persistentId ? persistentId : "persistentId" . index,
                result    = redis->pconnect(host, port, timeout, parameter);
        } else {
            let result = redis->connect(host, port, timeout);
        }

        if !result {
            throw new Exception(
                sprintf("Could not connect to the Redis server [%s:%s]", host, port)
            );
        }

        if !empty auth && true !== redis->auth(auth) {
            throw new Exception("Failed to authenticate with the Redis server");
        }

        if index > 0 && true !== redis->select(index) {
            throw new Exception("Failed to select the Redis database index");
        }

        return new RedisContext(redis, prefix, pollInterval);
    }
}

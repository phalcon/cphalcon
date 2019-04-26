
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Helper\Arr;
use Phalcon\Storage\Adapter\AbstractAdapter;
use Phalcon\Storage\Exception;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
 * Phalcon\Storage\Adapter\Redis
 *
 * Redis adapter
 */
class Redis extends AbstractAdapter
{
    /**
     * @var array
     */
    protected options = [];

    /**
     * Constructor
     */
    public function __construct(array! options = [])
    {
        /**
         * Lets set some defaults and options here
         */
        let options["host"]       = Arr::get(options, "host", "127.0.0.1"),
            options["port"]       = Arr::get(options, "port", 6379),
            options["index"]      = Arr::get(options, "index", 0),
            options["persistent"] = Arr::get(options, "persistent", false),
            options["auth"]       = Arr::get(options, "auth", ""),
            options["socket"]     = Arr::get(options, "socket", ""),
            this->prefix          = "ph-reds-",
            this->options         = options;

        parent::__construct(options);
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->flushDB();
    }

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->decrBy(key, value);
    }

    /**
     * Reads data from the adapter
     */
    public function delete(string! key) -> bool
    {
        var connection;

        let connection = this->getAdapter();

        return (bool) connection->delete(key);
    }

    /**
     * Reads data from the adapter
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        var connection, content;

        let connection = this->getAdapter(),
            content    = connection->get(key);

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     */
    public function getAdapter() -> var
    {
        var auth, connection, host, index, options, persistent, port,
            result, socket;

        if null === this->adapter {
            let options    = this->options,
                connection = new \Redis(),
                auth       = options["auth"],
                host       = options["host"],
                index      = options["index"],
                persistent = options["persistent"],
                port       = options["port"],
                socket     = options["socket"];

            if !empty socket {
                if persistent {
                    let result = connection->pconnect(socket);
                } else {
                    let result = connection->connect(socket);
                }
            } else {
                if persistent {
                    let result = connection->pconnect(host, port, this->lifetime);
                } else {
                    let result = connection->connect(host, port, this->lifetime);
                }
            }

            if !result {
                throw new Exception(
                    "Could not connect to the Redisd server [" . host . ":" . port . "]"
                );
            }

            if !empty auth && !connection->auth(auth) {
                throw new Exception("Failed to authenticate with the Redisd server");
            }

            if index > 0 && !connection->select(index) {
                throw new Exception("Redis server selected database failed");
            }

            connection->setOption(\Redis::OPT_PREFIX, this->prefix);

            this->setSerializer(connection);
            let this->adapter = connection;
        }

        return this->adapter;
    }

    /**
     * Stores data in the adapter
     */
    public function getKeys() -> array
    {
        var connection;

        let connection = this->getAdapter();

        return connection->getKeys("*");
    }

    /**
     * Checks if an element exists in the cache
     */
    public function has(string! key) -> bool
    {
        var connection;

        let connection = this->getAdapter();

        return (bool) connection->exists(key);
    }

    /**
     * Increments a stored number
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->incrBy(key, value);
    }

    /**
     * Stores data in the adapter
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var connection, content, lifetime;

        let connection = this->getAdapter(),
            content    = this->getSerializedData(value),
            lifetime   = this->getTtl(ttl);

        return connection->set(key, content, lifetime);
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     */
    private function setSerializer(<\Memcached> connection)
    {
        var serializer;
        string className;
        array map;

        let map = [
            "none" : \Redis::SERIALIZER_NONE,
            "php"  : \Redis::SERIALIZER_PHP
        ];

        let serializer = strtolower(this->defaultSerializer);

        if isset map[serializer] {
            let this->defaultSerializer = "";
            connection->setOption(\Redis::OPT_SERIALIZER, map[serializer]);
        } else {
            let className = "Phalcon\\Storage\\Serializer\\" . this->defaultSerializer;
            let this->serializer = new {className}();
        }
    }
}

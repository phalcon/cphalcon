
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Helper\Arr;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Storage\Serializer\SerializerInterface;

/**
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
     *
     * @param array options = [
     *     'host' => '127.0.0.1',
     *     'port' => 6379,
     *     'index' => 0,
     *     'persistent' => false,
     *     'auth' => '',
     *     'socket' => '',
     *     'connectionTimeout' => 0,
     *     'retryInterval' => null,
     *     'readTimeout' => 0,
     *     'defaultSerializer' => 'Php',
     *     'lifetime' => 3600,
     *     'serializer' => null,
     *     'prefix' => ''
     * ]
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
    {
        /**
         * Lets set some defaults and options here
         */
        let options["host"]              = Arr::get(options, "host", "127.0.0.1", "string"),
            options["port"]              = Arr::get(options, "port", 6379, "int"),
            options["index"]             = Arr::get(options, "index", 0, "int"),
            options["persistent"]        = Arr::get(options, "persistent", false, "bool"),
            options["auth"]              = Arr::get(options, "auth", "", "string"),
            options["socket"]            = Arr::get(options, "socket", "", "string"),
            options["connectionTimeout"] = Arr::get(options, "connectionTimeout", 0, "int"),
            options["retryInterval"]     = Arr::get(options, "retryInterval", null, "int"),
            options["readTimeout"]       = Arr::get(options, "readTimeout", 0, "int"),
            this->prefix                 = "ph-reds-",
            this->options                = options;

        parent::__construct(factory, options);
    }

    /**
     * Flushes/clears the cache
     *
     * @return bool
     * @throws Exception
     */
    public function clear() -> bool
    {
        return this->getAdapter()->flushDB();
    }

    /**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws Exception
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        return this->getAdapter()->decrBy(key, value);
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     *
     * @return bool
     * @throws Exception
     */
    public function delete(string! key) -> bool
    {
        return (bool) this->getAdapter()->del(key);
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     * @param mixed|null defaultValue
     *
     * @return mixed
     * @throws Exception
     */
    public function get(string! key, var defaultValue = null) -> var
    {

        if this->has(key) == false {
            return defaultValue;
        }

        return this->getUnserializedData(this->getAdapter()->get(key));
    }

    /**
     * Returns the already connected adapter or connects to the Redis
     * server(s)
     *
     * @return mixed|\Redis
     * @throws Exception
     */
    public function getAdapter() -> var
    {
        var auth, connection, connectionTimeout, host, index, options,
            port, readTimeout, reserved, result, retryInterval, persistent,
            persistentid;

        if null === this->adapter {
            let options           = this->options,
                connection        = new \Redis(),
                auth              = options["auth"],
                index             = options["index"],
                persistent        = options["persistent"],
                host              = options["host"],
                port              = options["port"],
                connectionTimeout = options["connectionTimeout"],
                retryInterval     = options["retryInterval"],
                readTimeout       = options["readTimeout"],
                // The documentation does not say what this is for :/
                reserved          = null;

            if !persistent {
                let result = connection->connect(
                    host,
                    port,
                    connectionTimeout,
                    reserved,
                    retryInterval,
                    readTimeout
                );
            } else {
                let persistentid = "persistentid_" . index;
                let result = connection->pconnect(
                    host,
                    port,
                    connectionTimeout,
                    persistentid,
                    retryInterval,
                    readTimeout
                );
            }

            if !result {
                throw new Exception(
                    "Could not connect to the Redisd server [" . host . ":" . port . "]"
                );
            }

            if !empty auth && !connection->auth(auth) {
                throw new Exception("Failed to authenticate with the Redis server");
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
     * Gets the keys from the adapter. Accepts an optional prefix which will
     * filter the keys returned
     *
     * @return array
     * @throws Exception
     */
    public function getKeys(string! prefix = "") -> array
    {
        return this->getFilteredKeys(
            this->getAdapter()->keys("*"),
            prefix
        );
    }

    /**
     * Checks if an element exists in the cache
     *
     * @param string $key
     *
     * @return bool
     * @throws Exception
     */
    public function has(string! key) -> bool
    {
        return (bool) this->getAdapter()->exists(key);
    }

    /**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return bool|int
     * @throws Exception
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        return this->getAdapter()->incrBy(key, value);
    }

    /**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param \DateInterval|int|null ttl
     *
     * @return bool
     * @throws Exception
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        return this->getAdapter()->set(
            key,
            this->getSerializedData(value),
            this->getTtl(ttl)
        );
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @param \Redis $connection
     */
    private function setSerializer(<\Redis> connection)
    {
        var serializer;
        array map;

        let map = [
            "none" : \Redis::SERIALIZER_NONE,
            "php"  : \Redis::SERIALIZER_PHP
        ];

        /**
         * In case IGBINARY or MSGPACK are not defined for previous versions
         * of Redis
         */
        if defined("\\Redis::SERIALIZER_IGBINARY") {
            let map["igbinary"] = constant("\\Redis::SERIALIZER_IGBINARY");
        }

        if defined("\\Redis::SERIALIZER_MSGPACK") {
            let map["msgpack"]  = constant("\\Redis::SERIALIZER_MSGPACK");
        }

        let serializer = strtolower(this->defaultSerializer);

        if isset map[serializer] {
            let this->defaultSerializer = "";
            connection->setOption(\Redis::OPT_SERIALIZER, map[serializer]);
        } else {
            this->initSerializer();
        }
    }
}

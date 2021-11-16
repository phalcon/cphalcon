
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use DateInterval;
use Exception as BaseException;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;

/**
 * Redis adapter
 *
 * @property array $options
 */
class Redis extends AbstractAdapter
{
    /**
     * @var string
     */
    protected prefix = "ph-reds-";

    /**
     * Redis constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options
     *
     * @throws SupportException
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
    {
        /**
         * Lets set some defaults and options here
         */
        let options["host"]           = this->getArrVal(options, "host", "127.0.0.1"),
            options["port"]           = this->getArrVal(options, "port", 6379, "int"),
            options["index"]          = this->getArrVal(options, "index", 0),
            options["timeout"]        = this->getArrVal(options, "timeout", 0),
            options["persistent"]     = this->getArrVal(options, "persistent", false, "bool"),
            options["persistentId"]   = this->getArrVal(options, "persistentId", "", "string"),
            options["auth"]           = this->getArrVal(options, "auth", ""),
            options["socket"]         = this->getArrVal(options, "socket", ""),
            options["connectTimeout"] = this->getArrVal(options, "connectTimeout", 0),
            options["retryInterval"]  = this->getArrVal(options, "retryInterval", 0),
            options["readTimeout"]    = this->getArrVal(options, "readTimeout", 0);

        parent::__construct(factory, options);
    }

    /**
     * Flushes/clears the cache
     *
     * @return bool
     * @throws StorageException
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
     * @throws StorageException
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
     * @throws StorageException
     */
    public function delete(string! key) -> bool
    {
        return (bool) this->getAdapter()->del(key);
    }

    /**
     * Reads data from the adapter
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed|null
     * @throws StorageException
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        return this->getUnserializedData(
            this->getAdapter()->get(key),
            defaultValue
        );
    }

    /**
     * Returns the already connected adapter or connects to the Redis
     * server(s)
     *
     * @return mixed|\Redis
     * @throws StorageException
     */
    public function getAdapter() -> var
    {
        var connection;

        if (null === this->adapter) {
            let connection = new \Redis();

            this
                ->checkConnect(connection)
                ->checkAuth(connection)
                ->checkIndex(connection)
            ;

            connection->setOption(\Redis::OPT_PREFIX, this->prefix);

            this->setSerializer(connection);
            let this->adapter = connection;
        }

        return this->adapter;
    }

    /**
     * Stores data in the adapter
     *
     * @param string $prefix
     *
     * @return array
     * @throws StorageException
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
     * @throws StorageException
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
     * @return bool|false|int
     * @throws StorageException
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        return this->getAdapter()->incrBy(key, value);
    }

    /**
     * Stores data in the adapter
     *
     * @param string                 $key
     * @param mixed                  $value
     * @param \DateInterval|int|null $ttl
     *
     * @return bool
     * @throws BaseException
     */
    public function set(string! key, var value, var ttl = null) -> bool
    {
        var result;

        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        let result = this->getAdapter()
                         ->set(
                             key,
                             this->getSerializedData(value),
                             this->getTtl(ttl)
                         )
        ;

        return typeof result === "bool" ? result : false;
    }

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return bool
     */
    public function setForever(string! key, var value) -> bool
    {
        var result;

        let result = this->getAdapter()
                         ->set(key, this->getSerializedData(value));

        return typeof result === "bool" ? result : false;
    }

    /**
     * @param \Redis $connection
     *
     * @return Redis
     * @throws StorageException
     */
    private function checkAuth(<\Redis> connection) -> <Redis>
    {
        var auth, error;

        let auth = this->options["auth"];

        try {
            let error = (true !== empty(auth) && true !== connection->auth(auth));
        } catch \Exception {
            let error = true;
        }

        if error {
            throw new StorageException(
                "Failed to authenticate with the Redis server"
            );
        }

        return this;
    }

    /**
     * @param \Redis $connection
     *
     * @return Redis
     * @throws StorageException
     */
    private function checkConnect(<\Redis> connection) -> <Redis>
    {
        var host, method, options, parameter, persistentId, port, retryInterval,
            readTimeout, result, timeout;

        let options       = this->options,
            host          = options["host"],
            port          = options["port"],
            timeout       = options["timeout"],
            retryInterval = options["retryInterval"],
            readTimeout   = options["readTimeout"];

        if true !== options["persistent"] {
            let method    = "connect",
                parameter = null;
        } else {
            let method       = "pconnect",
                persistentId = this->options["persistentId"],
                parameter    = !empty(persistentId) ? persistentId : "persistentId" . options["index"];
        }

        let result = connection->{method}(
            host,
            port,
            timeout,
            parameter,
            retryInterval,
            readTimeout
        );

        if !result {
            throw new StorageException(
                sprintf(
                    "Could not connect to the Redisd server [%s:%s]",
                    host,
                    port
                )
            );
        }

        return this;
    }

    /**
     * @param \Redis $connection
     *
     * @return Redis
     * @throws StorageException
     */
    private function checkIndex(<\Redis> connection) -> <Redis>
    {
        var index;

        let index = this->options["index"];

        if (index > 0 && true !== connection->select(index)) {
            throw new StorageException(
                "Redis server selected database failed"
            );
        }

        return this;
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @param \Redis $connection
     */
    private function setSerializer(<\Redis> connection) -> void
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
        if (defined("\\Redis::SERIALIZER_IGBINARY")) {
            let map["igbinary"] = constant("\\Redis::SERIALIZER_IGBINARY");
        }

        if (defined("\\Redis::SERIALIZER_MSGPACK")) {
            let map["msgpack"] = constant("\\Redis::SERIALIZER_MSGPACK");
        }

        if (defined("\\Redis::SERIALIZER_JSON")) {
            let map["json"] = constant("\\Redis::SERIALIZER_JSON");
        }

        let serializer = strtolower(this->defaultSerializer);

        if (true === isset(map[serializer])) {
            let this->defaultSerializer = "";
            connection->setOption(\Redis::OPT_SERIALIZER, map[serializer]);
        }

        this->initSerializer();
    }
}

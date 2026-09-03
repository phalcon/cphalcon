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
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\Exceptions\AuthenticationFailed;
use Phalcon\Storage\Exceptions\ConnectionFailed;
use Phalcon\Storage\Exceptions\DatabaseSelectionFailed;
use Phalcon\Storage\SerializerFactory;
use Redis as RedisService;
use RedisException;

/**
 * Redis adapter
 *
 * Capabilities:
 * - Counters: native atomic (incrBy()/decrBy()).
 * - getKeys(): non-blocking SCAN iteration.
 * - Serializers: Phalcon-side, or backend-native via OPT_SERIALIZER. Native
 *   serializers change the bytes at rest and are not interchangeable with
 *   Phalcon-side serializers.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_options from StorageTypes
 * @phpstan-import-type storage_redis_context from StorageTypes
 * @phpstan-import-type storage_redis_options from StorageTypes
 * @phpstan-import-type storage_redis_settings from StorageTypes
 *
 * @phpstan-property RedisService|null $adapter
 * @phpstan-property storage_redis_settings $options
 */
class Redis extends AbstractAdapter
{
    protected string prefix = "ph-reds-";

    /**
     * Redis constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options = [
     *     "host"           => "127.0.0.1",
     *     "port"           => 6379,
     *     "index"          => 0,
     *     "timeout"        => 0,
     *     "persistent"     => false,
     *     "persistentId"   => "",
     *     "auth"           => "",
     *     "socket"         => "",
     *     "connectTimeout" => 0,
     *     "retryInterval"  => 0,
     *     "readTimeout"    => 0,
     *     "ssl"            => [],
     * ]
     *
     * @phpstan-param storage_redis_options $options
     */
    public function __construct(
        <SerializerFactory> factory,
        array options = []
    ) {
        var localOptions;

        let localOptions = this->getDefaultOptions(options);

        parent::__construct(factory, localOptions);

        this->initSerializer();
    }

    /**
     * Flushes/clears the cache
     *
     * @return bool
     * @throws StorageException
     */
    public function clear() -> bool
    {
        var adapter, keys, key;
        array strippedKeys = [];
        int prefixLength;

        let keys = this->getKeys();

        if empty keys {
            return true;
        }

        let prefixLength = (int) strlen(this->prefix);

        for key in keys {
            let strippedKeys[] = substr(key, prefixLength);
        }

        /** @var RedisService $adapter */
        let adapter = this->getAdapter();

        return false !== adapter->del(strippedKeys);
    }

    /**
     * Returns the already connected adapter or connects to the Redis
     * server(s)
     *
     * The return type is deliberately left wide: RedisCluster extends this
     * adapter and hands back a `RedisCluster` client, which is not a `Redis`.
     * Callers inside this class narrow it to `RedisService` locally.
     *
     * @return mixed|RedisService
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
     * Returns all the keys stored
     *
     * SCAN replaces the blocking KEYS command. SCAN_NOPREFIX keeps the prefix
     * handling explicit: the physical prefix is matched and returned unchanged,
     * so getFilteredKeys() sees exactly what KEYS produced.
     *
     * @phpstan-return storage_keys
     */
    public function getKeys( string prefix = "") -> array
    {
        var adapter, cursor, keys, pattern, result, scanKeys;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter(),
            keys    = [],
            cursor  = "0",
            pattern = this->prefix . "*";

        /**
         * SCAN replaces the blocking KEYS command. It is issued through
         * rawCommand() so the cursor travels in the reply ([cursor, [keys]])
         * instead of through a by-reference argument, which Zephir cannot pass
         * to a method. rawCommand() does not apply OPT_PREFIX, so the physical
         * prefix is matched and returned unchanged and getFilteredKeys() sees
         * exactly what KEYS produced.
         */
        loop {
            let result = adapter->rawCommand(
                "scan",
                cursor,
                "MATCH",
                pattern,
                "COUNT",
                100
            );

            if (typeof result !== "array") {
                break;
            }

            if (!fetch cursor, result[0]) {
                break;
            }

            if fetch scanKeys, result[1] && typeof scanKeys === "array" {
                let keys = array_merge(keys, scanKeys);
            }

            if (cursor === "0" || cursor === 0) {
                break;
            }
        }

        /** @var storage_keys $keys */
        return this->getFilteredKeys(keys, prefix);
    }

    /**
     * Stores data in the adapter forever. The key needs to manually deleted
     * from the adapter.
     *
     * @throws StorageException
     * @throws RedisException
     */
    public function setForever( string key, var data) -> bool
    {
        var adapter, result;

        let key = this->getKeyWithoutPrefix(key);

        /** @var RedisService $adapter */
        let adapter = this->getAdapter(),
            result  = adapter->set(key, this->getSerializedData(data));

        return typeof result === "bool" ? result : false;
    }

    /**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @throws RedisException
     * @throws StorageException
     */
    protected function doDecrement( string key, int value = 1) -> false | int
    {
        var adapter;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter();

        return adapter->decrBy(key, value);
    }

    /**
     * Deletes data from the adapter
     *
     * @throws RedisException
     * @throws StorageException
     */
    protected function doDelete( string key) -> bool
    {
        var adapter;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter();

        return (bool) adapter->unlink(key);
    }

    /**
     * Deletes multiple keys from Redis using a single unlink call
     *
     * @phpstan-param storage_keys $keys
     *
     * @throws RedisException
     * @throws StorageException
     */
    protected function doDeleteMultiple(array keys) -> bool
    {
        var adapter, result;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter(),
            result  = adapter->unlink(keys);

        // unlink returns the number of keys deleted; all must be deleted
        return typeof result === "integer" && result === count(keys);
    }

    /**
     * Checks if an element exists in the cache
     *
     * @throws RedisException
     * @throws StorageException
     */
    protected function doHas( string key) -> bool
    {
        var adapter;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter();

        return (bool) adapter->exists(key);
    }

    /**
     * Increments a stored number
     *
     * @throws RedisException
     * @throws StorageException
     */
    protected function doIncrement( string key, int value = 1) -> false | int
    {
        var adapter;

        /** @var RedisService $adapter */
        let adapter = this->getAdapter();

        return adapter->incrBy(key, value);
    }

    /**
     * Stores data in the adapter. If the TTL is `null` (default) or not defined
     * then the default TTL will be used, as set in this adapter. If the TTL
     * is `0` or a negative number, a `delete()` will be issued, since this
     * item has expired. If you need to set this key forever, you should use
     * the `setForever()` method.
     *
     * @param string                $key
     * @param mixed                 $value
     * @param DateInterval|int|null $ttl
     *
     * @return bool
     * @throws BaseException
     */
    protected function doSet( string key, var value, var ttl = null) -> bool
    {
        var adapter, result;

        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        /** @var RedisService $adapter */
        let adapter = this->getAdapter(),
            result  = adapter->set(
                key,
                this->getSerializedData(value),
                this->getTtl(ttl)
            )
        ;

        return result;
    }

    /**
     * The parameter is the raw, user supplied options array; `RedisCluster`
     * overrides this method with its own set of keys, so the two signatures
     * have to agree on the wider type.
     *
     * @phpstan-param storage_options $options
     *
     * @phpstan-return storage_options
     */
    protected function getDefaultOptions(array options) -> array
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
            options["auth"]           = this->getArrVal(options, "auth", []),
            options["socket"]         = this->getArrVal(options, "socket", ""),
            options["connectTimeout"] = this->getArrVal(options, "connectTimeout", 0),
            options["retryInterval"]  = this->getArrVal(options, "retryInterval", 0),
            options["readTimeout"]    = this->getArrVal(options, "readTimeout", 0),
            options["ssl"]            = this->getArrVal(options, "ssl", []);

        return options;
    }

    /**
     * @param RedisService $connection
     *
     * @throws AuthenticationFailed
     */
    private function checkAuth(<RedisService> connection) -> <static>
    {
        var auth, error;

        let auth = this->options["auth"];

        try {
            let error = (true !== empty(auth) && true !== connection->auth(auth));
        } catch BaseException {
            let error = true;
        }

        if error {
            throw new AuthenticationFailed();
        }

        return this;
    }

    /**
     * @throws ConnectionFailed
     */
    private function checkConnect(<RedisService> connection) -> <static>
    {
        var auth, connectionOptions, ex, host, method, options, parameter,
            persistentId, port, retryInterval, readTimeout, result, ssl, timeout;

        let options       = this->options,
            host          = options["host"],
            port          = options["port"],
            timeout       = options["timeout"],
            retryInterval = options["retryInterval"],
            readTimeout   = options["readTimeout"],
            auth          = options["auth"],
            ssl           = options["ssl"];

        let connectionOptions = [];
        if (true !== empty(auth)) {
            let connectionOptions["auth"] = auth;
        }
        if (true !== empty(ssl)) {
            let connectionOptions["stream"] = ssl;
        }

        if true !== options["persistent"] {
            let method    = "connect",
                parameter = null;
        } else {
            let method       = "pconnect",
                persistentId = this->options["persistentId"],
                parameter    = !empty(persistentId) ? persistentId : "persistentId" . options["index"];
        }

        /** @var storage_redis_context $connectionOptions */
        try {
            let result = connection->{method}(
                host,
                port,
                timeout,
                parameter,
                retryInterval,
                readTimeout,
                connectionOptions
            );
        } catch \Exception, ex {
            throw new ConnectionFailed(ex->getMessage());
        }

        if !result {
            throw new ConnectionFailed(
                sprintf(
                    "Could not connect to the Redis server [%s:%s]",
                    host,
                    port
                )
            );
        }

        return this;
    }

    /**
     * @throws DatabaseSelectionFailed
     */
    private function checkIndex(<RedisService> connection) -> <static>
    {
        var index;

        let index = this->options["index"];

        if (index > 0 && true !== connection->select(index)) {
            throw new DatabaseSelectionFailed();
        }

        return this;
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @throws BaseException
     */
    private function setSerializer(<RedisService> connection) -> void
    {
        var serializer;
        array map;

        let map = [
            "redis_none" : RedisService::SERIALIZER_NONE,
            "redis_php"  : RedisService::SERIALIZER_PHP
        ];

        /**
         * In case IGBINARY or MSGPACK are not defined for previous versions
         * of Redis
         */
        if (defined("\\Redis::SERIALIZER_IGBINARY")) {
            let map["redis_igbinary"] = constant("\\Redis::SERIALIZER_IGBINARY");
        }

        if (defined("\\Redis::SERIALIZER_MSGPACK")) {
            let map["redis_msgpack"] = constant("\\Redis::SERIALIZER_MSGPACK");
        }

        if (defined("\\Redis::SERIALIZER_JSON")) {
            let map["redis_json"] = constant("\\Redis::SERIALIZER_JSON");
        }

        let serializer = strtolower(this->defaultSerializer);

        if (true === isset(map[serializer])) {
            let this->defaultSerializer = "";
            connection->setOption(RedisService::OPT_SERIALIZER, map[serializer]);
        }

        this->initSerializer();
    }
}

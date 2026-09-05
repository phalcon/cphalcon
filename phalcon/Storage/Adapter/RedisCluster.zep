
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Storage\Exceptions\ClusterConnectionFailed;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;
use Redis as RedisConsts;
use RedisCluster as RedisService;
use Throwable;

/**
 * RedisCluster adapter
 *
 * Capabilities (in addition to Redis):
 * - Counters: native atomic (incrBy()/decrBy()).
 * - getKeys(): blocking KEYS across all master nodes (per-node SCAN is left to
 *   the redesign); clear() flushes every master.
 * - Serializers: Phalcon-side, or backend-native via OPT_SERIALIZER.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_options from StorageTypes
 * @phpstan-import-type storage_rediscluster_options from StorageTypes
 * @phpstan-import-type storage_rediscluster_settings from StorageTypes
 *
 * @phpstan-property RedisService|null $adapter
 * @phpstan-property storage_rediscluster_settings $options
 */
class RedisCluster extends Redis
{
    protected string prefix = "ph-redc-";

    /**
     * You can create and connect to a cluster either by passing it one or more
     * 'seed' nodes, or by defining these in redis.ini as a 'named' cluster.
     *
     * If you are connecting with the cluster by offering a name, that is
     * configured in redis.ini:
     *
     *      ```
     *      # In redis.ini
     *      redis.clusters.seeds = "mycluster[]=localhost:7000&test[]=localhost:7001"
     *      redis.clusters.timeout = "mycluster=5"
     *      redis.clusters.read_timeout = "mycluster=10"
     *      redis.clusters.auth = "mycluster=password"
     *      ```
     * you can use `$options = ["name" => "mycluster"]`.
     *
     * If you don't have cluster seeds configured in your redis.ini,
     * you should pass hosts as an array,
     * eg. `$options = ["hosts" => ["a-host:7000", "b-host:7001"]]`.
     *
     * You can provide authentication data offering a string `user=password`
     * or array `["user" => "name", "password" => "secret"]`.
     *
     * The `timeout` is the amount of time library will wait when connecting
     * or writing to the cluster. `readTimeout` is the amount of time library
     * will wait for a result from the cluster.
     *
     * The `context` is an array of values used for ssl/tls stream context
     * options eg `["verify_peer" => 0, "local_cert" => "file:///path/to/cert.pem"]`
     *
     * @param array             $options = [
     *     "name"        => null,
     *     "hosts"       => ["127.0.0.1:6379"],
     *     "timeout"     => 0,
     *     "readTimeout" => 0,
     *     "persistent"  => false,
     *     "auth"        => "",
     *     "context"     => null,
     * ]
     *
     * @phpstan-param storage_rediscluster_options $options
     *
     * @throws SupportException
     */
    public function __construct(<SerializerFactory> factory,  array options = [])
    {
        parent::__construct(factory, options);
    }

    /**
     * Flushes/clears the cache
     *
     * @return bool
     * @throws ClusterConnectionFailed|SupportException
     */
    public function clear() -> bool
    {
        var adapter, master;

        let adapter = this->getAdapter();

        for master in adapter->_masters() {
            adapter->flushAll(master);
        }

        return true;
    }

    /**
     * Returns the already connected adapter or connects to the Redis
     * server(s)
     *
     * @return RedisService
     * @throws ClusterConnectionFailed|SupportException
     */
    public function getAdapter() -> var
    {
        var connection, ex, options;

        if (null === this->adapter) {
            let options = this->options;

            try {
                let connection = new RedisService(
                    options["name"],
                    options["hosts"],
                    options["timeout"],
                    options["readTimeout"],
                    options["persistent"],
                    options["auth"],
                    options["context"]
                );
            } catch Throwable, ex {
                throw new ClusterConnectionFailed(
                    "Could not connect to the Redis Cluster server due to: "
                    . ex->getMessage(),
                    0,
                    ex
                );
            }

            connection->setOption(RedisConsts::OPT_PREFIX, this->prefix);

            this->setSerializer(connection);
            let this->adapter = connection;
        }

        return this->adapter;
    }

    /**
     * Returns all the keys stored
     *
     * RedisCluster::scan() iterates one node at a time, so the blocking KEYS
     * command is retained here (phpredis routes it across the masters). The
     * per-node SCAN migration is left to the storage redesign.
     *
     * @phpstan-return storage_keys
     *
     * @throws ClusterConnectionFailed|SupportException
     */
    public function getKeys(string prefix = "") -> array
    {
        var keys;

        /** @var storage_keys $keys */
        let keys = this->getAdapter()->keys("*");

        return this->getFilteredKeys(keys, prefix);
    }

    /**
     * @phpstan-param storage_options $options
     *
     * @phpstan-return storage_options
     */
    protected function getDefaultOptions(array options) -> array
    {
        /**
         * Lets set some defaults and options here
         */
        let options["name"]        = this->getArrVal(options, "name", null),
            options["hosts"]       = this->getArrVal(options, "hosts", "127.0.0.1:6379"),
            options["timeout"]     = this->getArrVal(options, "timeout", 0),
            options["readTimeout"] = this->getArrVal(options, "readTimeout", 0),
            options["persistent"]  = this->getArrVal(options, "persistent", false, "bool"),
            options["auth"]        = this->getArrVal(options, "auth", ""),
            options["context"]     = this->getArrVal(options, "context", null);

        return $options;
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @throws SupportException
     */
    private function setSerializer(<RedisService> connection) -> void
    {
        var serializer;
        array map;

        let map = [
            "redis_none" : \Redis::SERIALIZER_NONE,
            "redis_php"  : \Redis::SERIALIZER_PHP
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
            connection->setOption(\Redis::OPT_SERIALIZER, map[serializer]);
        }

        this->initSerializer();
    }
}


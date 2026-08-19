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
use Memcached;
use Phalcon\Contracts\Storage\StorageTypes;
use Phalcon\Storage\Exception as StorageException;
use Phalcon\Storage\Exceptions\ConnectionFailed;
use Phalcon\Storage\Exceptions\InvalidConfiguration;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;

/**
 * Libmemcached adapter
 *
 * Capabilities:
 * - Counters: native atomic (Memcached::increment()/decrement()).
 * - getKeys(): Memcached::getAllKeys(), which is server-dependent and may be
 *   incomplete or unavailable on modern memcached builds.
 * - Serializers: Phalcon-side plus libmemcached's own options.
 *
 * @phpstan-import-type storage_keys from StorageTypes
 * @phpstan-import-type storage_libmemcached_client from StorageTypes
 * @phpstan-import-type storage_libmemcached_options from StorageTypes
 * @phpstan-import-type storage_libmemcached_sasl from StorageTypes
 * @phpstan-import-type storage_libmemcached_servers from StorageTypes
 * @phpstan-import-type storage_libmemcached_settings from StorageTypes
 *
 * @phpstan-property Memcached|null $adapter
 * @phpstan-property storage_libmemcached_settings $options
 */
class Libmemcached extends AbstractAdapter
{
    protected string prefix = "ph-memc-";

    /**
     * Libmemcached constructor.
     *
     * @phpstan-param storage_libmemcached_options $options
     */
    public function __construct(<SerializerFactory> factory, array options = [])
    {
        if !isset options["servers"] {
            let options["servers"] = [
                0 : [
                    "host"   : "127.0.0.1",
                    "port"   : 11211,
                    "weight" : 1
                ]
            ];
        }

        parent::__construct(factory, options);

        this->initSerializer();
    }

    /**
     * Flushes/clears the cache
     *
     * @throws StorageException
     */
    public function clear() -> bool
    {
        return this->getAdapter()->flush();
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return Memcached
     * @throws StorageException
     */
    public function getAdapter() -> var
    {
        var client, connection, failover, options, persistentId, sasl,
            saslUser, saslPass, serverList, servers;

        if !this->adapter {
            let options      = this->options,
                persistentId = this->getArrVal(options, "persistentId", "ph-mcid-"),
                sasl         = this->getArrVal(options, "saslAuthData", []),
                connection   = new \Memcached(persistentId),
                serverList   = connection->getServerList();

            connection->setOption(\Memcached::OPT_PREFIX_KEY, this->prefix);

            if (empty(serverList)) {
                let servers  = this->getArrVal(options, "servers", []),
                    client   = this->getArrVal(options, "client", []),
                    saslUser = this->getArrVal(sasl, "user", ""),
                    saslPass = this->getArrVal(sasl, "pass", ""),
                    failover = [
                        \Memcached::OPT_CONNECT_TIMEOUT       : 50,
                        \Memcached::OPT_DISTRIBUTION          : \Memcached::DISTRIBUTION_CONSISTENT,
                        \Memcached::OPT_SERVER_FAILURE_LIMIT  : 2,
                        \Memcached::OPT_REMOVE_FAILED_SERVERS : true,
                        \Memcached::OPT_RETRY_TIMEOUT         : 1
                    ],
                    client   = array_replace(failover, client);

                this
                    ->setOptions(connection, client)
                    ->setServers(connection, servers)
                    ->setSasl(connection, saslUser, saslPass)
                ;
            }

            this->setSerializer(connection);

            let this->adapter = connection;
        }

        return this->adapter;
    }

    /**
     * Stores data in the adapter
     *
     * @phpstan-return storage_keys
     *
     * @throws StorageException
     */
    public function getKeys( string prefix = "") -> array
    {
        var keys;

        /** @var storage_keys|false $keys */
        let keys = this->getAdapter()->getAllKeys();

        return this->getFilteredKeys(keys, prefix);
    }

    /**
     * Stores data in the adapter forever. The key needs to be manually deleted
     * from the adapter.
     *
     * @throws StorageException
     */
    public function setForever(string key, var data) -> bool
    {
        let key = this->getKeyWithoutPrefix(key);

        return this->getAdapter()
                   ->set(key, this->getSerializedData(data), 0);
    }

    /**
     * Decrements a stored number
     *
     * @throws StorageException
     */
    protected function doDecrement( string key, int value = 1) -> false | int
    {
        return this->getAdapter()->decrement(key, value);
    }

    /**
     * Deletes data from the adapter
     *
     * @throws StorageException
     */
    protected function doDelete( string key) -> bool
    {
        return this->getAdapter()->delete(key, 0);
    }

    /**
     * Deletes multiple keys from Memcached using a single deleteMulti call
     *
     * @phpstan-param storage_keys $keys
     *
     * @throws StorageException
     */
    protected function doDeleteMultiple(array keys) -> bool
    {
        var result, value;

        if empty keys {
            return true;
        }

        let result = this->getAdapter()->deleteMulti(keys);

        // deleteMulti returns [key => true] on success, [key => result_code] on failure
        // all values must be true for a complete success
        if typeof result !== "array" {
            return false;
        }

        for value in result {
            if value !== true {
                return false;
            }
        }

        return true;
    }

    /**
     * Checks if an element exists in the cache
     *
     * @throws StorageException
     */
    protected function doHas( string key) -> bool
    {
        var connection, code;

        let connection = this->getAdapter();
        connection->get(key);
        let code = connection->getResultCode();

        return \Memcached::RES_NOTFOUND !== code;
    }

    /**
     * Increments a stored number
     *
     * @throws StorageException
     */
    protected function doIncrement( string key, int value = 1) -> false | int
    {
        return this->getAdapter()->increment(key, value);
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
     * @throws StorageException
     */
    protected function doSet(string key, var value, var ttl = null) -> bool
    {
        if (typeof ttl === "integer" && ttl < 1) {
            return this->delete(key);
        }

        return this->getAdapter()
                   ->set(
                       key,
                       this->getSerializedData(value),
                       this->getTtl(ttl)
                   )
        ;
    }

    /**
     * @phpstan-param storage_libmemcached_client $client
     *
     * @throws InvalidConfiguration
     */
    private function setOptions(<\Memcached> connection, array client) -> <static>
    {
        if (true !== connection->setOptions(client)) {
            throw new InvalidConfiguration(
                "Cannot set Memcached client options"
            );
        }

        return this;
    }

    private function setSasl(
        <\Memcached> connection,
        string saslUser,
        string saslPass
    ) -> <static> {
        if (true !== empty(saslUser)) {
            connection->setSaslAuthData(saslUser, saslPass);
        }

        return this;
    }

    /**
     * Checks the serializer. If it is a supported one it is set, otherwise
     * the custom one is set.
     *
     * @throws SupportException
     */
    private function setSerializer(<\Memcached> connection) -> void
    {
        var serializer;
        array map;

        let map = [
            "memcached_igbinary" : \Memcached::SERIALIZER_IGBINARY,
            "memcached_json"     : \Memcached::SERIALIZER_JSON,
            "memcached_php"      : \Memcached::SERIALIZER_PHP
        ];

        let serializer = strtolower(this->defaultSerializer);

        if (isset(map[serializer])) {
            let this->defaultSerializer = "";
            connection->setOption(\Memcached::OPT_SERIALIZER, map[serializer]);
        }

        this->initSerializer();
    }

    /**
     * @phpstan-param storage_libmemcached_servers $servers
     *
     * @throws ConnectionFailed
     */
    private function setServers(<\Memcached> connection, array servers) -> <static>
    {
        if (true !== connection->addServers(servers)) {
            throw new ConnectionFailed(
                "Cannot connect to the Memcached server(s)"
            );
        }

        return this;
    }
}

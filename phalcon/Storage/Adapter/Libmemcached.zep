
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
 * Libmemcached adapter
 */
class Libmemcached extends AbstractAdapter
{
    /**
     * @var array
     */
    protected options = [];

    /**
     * Libmemcached constructor.
     *
     * @param array options = [
     *     'servers' => [
     *         [
     *             'host' => '127.0.0.1',
     *             'port' => 11211,
     *             'weight' => 1
     *         ]
     *     ],
     *     'defaultSerializer' => 'Php',
     *     'lifetime' => 3600,
     *     'serializer' => null,
     *     'prefix' => ''
     * ]
     */
    public function __construct(<SerializerFactory> factory, array! options = [])
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

        let this->prefix  = "ph-memc-",
            this->options = options;

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
        return this->getAdapter()->flush();
    }

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        return this->getAdapter()->decrement(key, value);
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
        return this->getAdapter()->delete(key, 0);
    }

    /**
     * Reads data from the adapter
     *
     * @param string $key
     * @param null   $defaultValue
     *
     * @return mixed
     * @throws Exception
     */
    public function get(string! key, var defaultValue = null) -> var
    {
        return this->getUnserializedData(
            this->getAdapter()->get(key),
            defaultValue
        );
    }

    /**
     * Returns the already connected adapter or connects to the Memcached
     * server(s)
     *
     * @return \Memcached
     * @throws Exception
     */
    public function getAdapter() -> var
    {
        var client, connection, failover, options, persistentId,
            sasl, saslPass, saslUser, servers, serverList;

        if null === this->adapter {
            let options      = this->options,
                persistentId = Arr::get(options, "persistentId", "ph-mcid-"),
                sasl         = Arr::get(options, "saslAuthData", []),
                connection   = new \Memcached(persistentId),
                serverList   = connection->getServerList();

            connection->setOption(\Memcached::OPT_PREFIX_KEY, this->prefix);

            if count(serverList) < 1 {
                let servers  = Arr::get(options, "servers", []),
                    client   = Arr::get(options, "client", []),
                    saslUser = Arr::get(sasl, "user", ""),
                    saslPass = Arr::get(sasl, "pass", ""),
                    failover = [
                        \Memcached::OPT_CONNECT_TIMEOUT       : 10,
                        \Memcached::OPT_DISTRIBUTION          : \Memcached::DISTRIBUTION_CONSISTENT,
                        \Memcached::OPT_SERVER_FAILURE_LIMIT  : 2,
                        \Memcached::OPT_REMOVE_FAILED_SERVERS : true,
                        \Memcached::OPT_RETRY_TIMEOUT         : 1
                    ],
                    client   = array_merge(failover, client);

                if !connection->setOptions(client) {
                    throw new Exception("Cannot set Memcached client options");
                }

                if !connection->addServers(servers) {
                    throw new Exception("Cannot connect to the Memcached server(s)");
                }

                if !empty saslUser {
                    connection->setSaslAuthData(saslUser, saslPass);
                }
            }

            this->setSerializer(connection);

            let this->adapter = connection;
        }

        return this->adapter;
    }

    /**
     * Stores data in the adapter
     *
     * @return array
     */
    public function getKeys(string! prefix = "") -> array
    {
        return this->getFilteredKeys(
            this->getAdapter()->getAllKeys(),
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
        var connection, result;

        let connection = this->getAdapter(),
            result     = connection->get(key);

        return \Memcached::RES_NOTFOUND !== connection->getResultCode();
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
        return this->getAdapter()->increment(key, value);
    }

    /**
     * Stores data in the adapter
     *
     * @param string $key
     * @param mixed  $value
     * @param null   $ttl
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
     * @param \Memcached $connection
     */
    private function setSerializer(<\Memcached> connection)
    {
        var serializer;
        array map;

        let map = [
            "php"      : \Memcached::SERIALIZER_PHP,
            "json"     : \Memcached::SERIALIZER_JSON,
            "igbinary" : \Memcached::SERIALIZER_IGBINARY
        ];

        let serializer = mb_strtolower(this->defaultSerializer);

        if isset map[serializer] {
            let this->defaultSerializer = "";
            connection->setOption(\Memcached::OPT_SERIALIZER, map[serializer]);
        } else {
            this->initSerializer();
        }
    }
}

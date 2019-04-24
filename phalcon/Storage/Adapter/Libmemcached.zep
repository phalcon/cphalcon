
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
 * Phalcon\Storage\Adapter\Libmemcached
 *
 * Libmemcached adapter
 */
class Libmemcached extends AbstractAdapter
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
        if !isset options["servers"] {
            let options["servers"] = [
                0: [
                    "host"   : "127.0.0.1",
                    "port"   : 11211,
                    "weight" : 1
                ]
            ];
        }

        let this->prefix  = "ph-memc-",
            this->options = options;

        parent::__construct(options);
    }

    /**
     * Flushes/clears the cache
     */
    public function clear() -> bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->flush();
    }

    /**
     * Decrements a stored number
     */
    public function decrement(string! key, int value = 1) -> int | bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->decrement(key, value);
    }

    /**
     * Reads data from the adapter
     */
    public function delete(string! key) -> bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->delete(key, 0);
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
        var client, connection, options, persistentId, servers, serverList;

        if null === this->adapter {
            let options      = this->options,
                persistentId = Arr::get(options, "persistentId", "ph-mcid-"),
                connection   = new \Memcached(persistentId),
                serverList   = connection->getServerList();

            connection->setOption(\Memcached::OPT_PREFIX_KEY, this->prefix);

            if count(serverList) < 1 {
                let servers = Arr::get(options, "servers", []),
                    client  = Arr::get(options, "client", []);

                if !connection->setOptions(client) {
                    throw new Exception("Cannot set Memcached client options");
                }

                if !connection->addServers(servers) {
                    throw new Exception("Cannot connect to the Memcached server(s)");
                }
            }

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

        return connection->getAllKeys();
    }

    /**
     * Checks if an element exists in the cache
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
     */
    public function increment(string! key, int value = 1) -> int | bool
    {
        var connection;

        let connection = this->getAdapter();

        return connection->increment(key, value);
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
            "php"      : \Memcached::SERIALIZER_PHP,
            "json"     : \Memcached::SERIALIZER_JSON,
            "igbinary" : \Memcached::SERIALIZER_IGBINARY
        ];

        let serializer = strtolower(this->defaultSerializer);

        if isset map[serializer] {
            let this->defaultSerializer = "";
            connection->setOption(\Memcached::OPT_SERIALIZER, map[serializer]);
        } else {
            let className = "Phalcon\\Storage\\Serializer\\" . this->defaultSerializer;
            let this->serializer = new {className}();
        }
    }
}

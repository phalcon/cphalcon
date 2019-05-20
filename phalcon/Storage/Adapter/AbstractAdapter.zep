
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Adapter;

use DateInterval;
use Phalcon\Helper\Arr;
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Exception;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Storage\Serializer\SerializerInterface;

abstract class AbstractAdapter implements AdapterInterface
{
    /**
     * @var mixed
     */
    protected adapter;

    /**
     * Name of the default serializer class
     *
     * @var string
     */
    protected defaultSerializer = "Php" { get, set };

    /**
     * Name of the default TTL (time to live)
     *
     * @var int
     */
    protected lifetime = 3600;

    /**
     * @var string
     */
    protected prefix = "" { get };

    /**
     * Serializer
     *
     * @var <SerializerInterface>
     */
    protected serializer;

    /**
     * Serializer Factory
     *
     * @var <SerializerFactory>
     */
    protected serializerFactory;

    /**
     * Sets parameters based on options
     */
    protected function __construct(<SerializerFactory> factory = null, array! options) -> void
    {
        /**
         * Lets set some defaults and options here
         */
        let this->defaultSerializer = Arr::get(options, "defaultSerializer", "Php"),
            this->lifetime          = Arr::get(options, "lifetime", 3600),
            this->serializer        = Arr::get(options, "serializer", null),
            this->serializerFactory = factory;

        if isset options["prefix"] {
            let this->prefix = options["prefix"];
        }
    }

    /**
     * Flushes/clears the cache
     */
    abstract public function clear() -> bool;

    /**
     * Decrements a stored number
     */
    abstract public function decrement(string! key, int value = 1) -> int | bool;

    /**
     * Deletes data from the adapter
     */
    abstract public function delete(string! key) -> bool;

    /**
     * Reads data from the adapter
     */
    abstract public function get(string! key) -> var;

    /**
     * Returns the adapter - connects to the storage if not connected
     */
    abstract public function getAdapter() -> var;

    /**
     * Returns all the keys stored
     */
    abstract public function getKeys() -> array;

    /**
     * Checks if an element exists in the cache
     */
    abstract public function has(string! key) -> bool;

    /**
     * Increments a stored number
     */
    abstract public function increment(string! key, int value = 1) -> int | bool;

    /**
     * Stores data in the adapter
     */
    abstract public function set(string! key, var value, var ttl = null) -> bool;

    /**
     * Returns the key requested, prefixed
     */
    protected function getPrefixedKey(var key) -> string
    {
        let key = (string) key;

        return this->prefix . key;
    }

    /**
     * Returns serialized data
     */
    protected function getSerializedData(var content) -> var
    {
        if this->defaultSerializer !== "" {
            this->serializer->setData(content);
            let content = this->serializer->serialize();
        }

        return content;
    }

    /**
     * Calculates the TTL for a cache item
     *
     * @param DateInterval|int|null $ttl
     *
     * @return int
     * @throws Exception
     */
    protected function getTtl(var ttl) -> int
    {
        var dateTime;

        if ttl === null {
            return this->lifetime;
        }

        if typeof ttl === "object" && ttl instanceof \DateInterval {
            let dateTime = new \DateTime("@0");
            return dateTime->add(ttl)->getTimestamp();
        }

        return (int) ttl;
    }

    /**
     * Returns unserialized data
     */
    protected function getUnserializedData(var content, var defaultValue = null) -> var
    {
        if !content {
            return defaultValue;
        }

        if this->defaultSerializer !== "" {
            this->serializer->unserialize(content);
            let content = this->serializer->getData();
        }

        return content;
    }

    /**
     * Initializes the serializer
     */
    protected function initSerializer() -> void
    {
        string className;

        if unlikely null === this->serializerFactory {
            throw new Exception("A valid serializer is required");
        }

        let className        = strtolower(this->defaultSerializer),
            this->serializer = this->serializerFactory->newInstance(className);
    }
}

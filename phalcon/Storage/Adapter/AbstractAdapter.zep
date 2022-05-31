
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
use DateTime;
use Exception;
use Phalcon\Storage\Serializer\SerializerInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Support\Exception as SupportException;

/**
 * Class AbstractAdapter
 *
 * @package Phalcon\Storage\Adapter
 *
 * @property mixed               $adapter
 * @property string              $defaultSerializer
 * @property int                 $lifetime
 * @property array               $options
 * @property string              $prefix
 * @property SerializerInterface $serializer
 * @property SerializerFactory   $serializerFactory
 */
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
    protected defaultSerializer = "php" { get };

    /**
     * Name of the default TTL (time to live)
     *
     * @var int
     */
    protected lifetime = 3600;

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var string
     */
    protected prefix = "ph-memo-";

    /**
     * Serializer
     *
     * @var SerializerInterface|null
     */
    protected serializer;

    /**
     * Serializer Factory
     *
     * @var SerializerFactory
     */
    protected serializerFactory;

    /**
     * AbstractAdapter constructor.
     *
     * @param SerializerFactory $factory
     * @param array             $options
     */
    protected function __construct(
        <SerializerFactory> factory,
        array options = []
    ) {
        /**
         * Lets set some defaults and options here
         */
        let this->serializerFactory = factory,
            this->defaultSerializer = mb_strtolower(
                this->getArrVal(options, "defaultSerializer", "php")
            ),
            this->lifetime   = this->getArrVal(options, "lifetime", 3600),
            this->serializer = this->getArrVal(options, "serializer", null);

        if isset options["prefix"] {
            let this->prefix = options["prefix"];
        }

        unset options["defaultSerializer"];
        unset options["lifetime"];
        unset options["serializer"];
        unset options["prefix"];

        let this->options = options;
    }

    /**
     * Flushes/clears the cache
     *
     * @return bool
     */
    abstract public function clear() -> bool;

    /**
     * Decrements a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return int | bool
     */
    abstract public function decrement(string! key, int value = 1) -> int | bool;

    /**
     * Deletes data from the adapter
     *
     * @param string $key
     *
     * @return bool
     */
    abstract public function delete(string! key) -> bool;

    /**
     * Reads data from the adapter
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed
     */
    public function get(string key, defaultValue = null) -> var
    {
        var content;

        if (true !== this->has(key)) {
            return defaultValue;
        }

        let content  = this->doGet(key);

        return this->getUnserializedData(content, defaultValue);
    }

    /**
     * Returns the adapter - connects to the storage if not connected
     *
     * @return mixed
     */
    public function getAdapter() -> var
    {
        return this->adapter;
    }

    /**
     * Returns all the keys stored
     *
     * @param string $prefix
     *
     * @return array
     */
    abstract public function getKeys(string prefix = "") -> array;

    /**
     * Returns the prefix
     *
     * @return string
     */
    public function getPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Checks if an element exists in the cache
     *
     * @param string $key
     *
     * @return bool
     */
    abstract public function has(string! key) -> bool;

    /**
     * Increments a stored number
     *
     * @param string $key
     * @param int    $value
     *
     * @return int | bool
     */
    abstract public function increment(string! key, int value = 1) -> int | bool;

    /**
     * Stores data in the adapter
     *
     * @param string                $key
     * @param mixed                 $value
     * @param DateInterval|int|null $ttl
     *
     * @return bool
     */
    abstract public function set(string key, var value, var ttl = null) -> bool;

    /**
     * @param string $serializer
     */
    public function setDefaultSerializer(string serializer) -> void
    {
        let this->defaultSerializer = mb_strtolower(serializer);
    }

    /**
     * @param string $key
     *
     * @return mixed
     */
    protected function doGet(string key)
    {
        return this->getAdapter()->get(key);
    }

    /**
     * Filters the keys array based on global and passed prefix
     *
     * @param mixed  $keys
     * @param string $prefix
     *
     * @return array
     */
    protected function getFilteredKeys(var keys, string! prefix) -> array
    {
        var key, pattern;
        array results;

        let results = [],
            pattern = this->prefix . prefix,
            keys    = !keys ? [] : keys;

        for key in keys {
            if starts_with(key, pattern) {
                let results[] = key;
            }
        }

        return results;
    }

    /**
     * Returns the key requested, prefixed
     *
     * @param string $key
     *
     * @return string
     */
    protected function getPrefixedKey(var key) -> string
    {
        let key = (string) key;

        return this->prefix . key;
    }

    /**
     * Returns serialized data
     *
     * @param mixed $content
     *
     * @return mixed
     */
    protected function getSerializedData(var content) -> var
    {
        if (null !== this->serializer) {
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

        if typeof ttl === "object" && ttl instanceof DateInterval {
            let dateTime = new DateTime("@0");
            return dateTime->add(ttl)->getTimestamp();
        }

        return (int) ttl;
    }

    /**
     * Returns unserialized data
     *
     * @param mixed      $content
     * @param mixed|null $defaultValue
     *
     * @return mixed
     */
    protected function getUnserializedData(var content, var defaultValue = null) -> var
    {
        if (null !== this->serializer) {
            this->serializer->unserialize(content);

            if unlikely true !== this->serializer->isSuccess() {
                return defaultValue;
            }

            let content = this->serializer->getData();
        }

        return content;
    }

    /**
     * Initializes the serializer
     *
     * @throws SupportException
     */
    protected function initSerializer() -> void
    {
        var className;

        if (
            true !== empty(this->defaultSerializer) &&
            typeof this->serializer !== "object"
        ) {
            let className        = this->defaultSerializer,
                this->serializer = this->serializerFactory->newInstance(className);
        }
    }

    /**
     * @todo Remove this when we get traits
     */
    protected function getArrVal(
        array! collection,
        var index,
        var defaultValue = null,
        string! cast = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        if unlikely cast {
            settype(value, cast);
        }

        return value;
    }
}

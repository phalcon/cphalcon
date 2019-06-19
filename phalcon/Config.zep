
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Config\Exception;

/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of,
 * configuration data within applications. It provides a nested object property
 * based user interface for accessing this configuration data within application
 * code.
 *
 *<code>
 * $config = new \Phalcon\Config(
 *     [
 *         "database" => [
 *             "adapter"  => "Mysql",
 *             "host"     => "localhost",
 *             "username" => "scott",
 *             "password" => "cheetah",
 *             "dbname"   => "test_db",
 *         ],
 *         "phalcon" => [
 *             "controllersDir" => "../app/controllers/",
 *             "modelsDir"      => "../app/models/",
 *             "viewsDir"       => "../app/views/",
 *         ],
 *     ]
 * );
 *</code>
 */
class Config extends \ArrayObject
{
    const DEFAULT_PATH_DELIMITER = ".";

    /**
     * @var string
     */
    protected pathDelimiter;

    /**
     * Phalcon\Config constructor
     */
    public function __construct(array! arrayConfig = null) -> void
    {
        this->setFlags(\ArrayObject::ARRAY_AS_PROPS);

        if typeof arrayConfig !== "null" {
            this->fromArray(arrayConfig);
        }
    }

    /**
     * Gets an attribute from the configuration, if the attribute isn't defined
     * returns null. If the value is exactly null or is not defined the default
     * value will be used instead
     *
     *<code>
     * echo $config->get("controllersDir", "../app/controllers/");
     *</code>
     */
    public function get(var index, var defaultValue = null) -> var
    {
        let index = (string) index;

        if !this->offsetExists(index) {
            return defaultValue;
        }

        return this->offsetGet(index);
    }

    /**
     * Gets the default path delimiter
     */
    public function getPathDelimiter() -> string
    {
        var delimiter;

        let delimiter = this->pathDelimiter;

        if !delimiter {
            let delimiter = self::DEFAULT_PATH_DELIMITER;
        }

        return delimiter;
    }

    /**
     * Merges a configuration into the current one
     *
     *<code>
     * $appConfig = new \Phalcon\Config(
     *     [
     *         "database" => [
     *             "host" => "localhost",
     *         ],
     *     ]
     * );
     *
     * $globalConfig->merge($appConfig);
     *</code>
     */
    public function merge(var configParam) -> <Config>
    {
        var config, result, source, target;

        switch typeof configParam {
            case "array":
                let config = new Config(configParam);
                break;
            case "object":
                let config = configParam;
                break;
            default:
                throw new Exception("Invalid data type for merge.");
        }

        let source = this->toArray(),
            target = config->toArray(),
            result = this->internalMerge(source, target);

        this->reset();
        this->fromArray(result);

        return this;
    }

    /**
     * Sets an attribute using the array-syntax
     *
     *<code>
     * $config["database"] = [
     *     "type" => "Sqlite",
     * ];
     *</code>
     */
    public function offsetSet(var index, var value) -> void
    {
        var data;

        if typeof value === "array" {
            let data = new Config(value);
        } else {
            let data = value;
        }

        let index = (string) index;

        parent::offsetSet(index, data);
    }

    /**
     * Returns a value from current config using a dot separated path.
     *
     *<code>
     * echo $config->path("unknown.path", "default", ".");
     *</code>
     */
    public function path(string! path, var defaultValue = null, var delimiter = null) -> var
    {
        var key, keys, config;

        if this->offsetExists(path) {
            return this->offsetGet(path);
        }

        if empty delimiter {
            let delimiter = this->getPathDelimiter();
        }

        let config = this,
            keys   = explode(delimiter, path);

        while !empty keys {
            let key = array_shift(keys);

            if !config->offsetExists(key) {
                break;
            }

            if empty keys {
                return config->offsetGet(key);
            }

            let config = config->offsetGet(key);

            if empty config {
                break;
            }
        }

        return defaultValue;
    }

    /**
     * Unsets all the values in object.
     */
    public function reset() -> void
    {
        this->exchangeArray([]);
    }

    /**
     * Sets the default path delimiter
     */
    public function setPathDelimiter(string! delimiter = null) -> <Config>
    {
        let this->pathDelimiter = delimiter;

        return this;
    }

    /**
     * Converts recursively the object to an array
     *
     *<code>
     * print_r(
     *     $config->toArray()
     * );
     *</code>
     */
    public function toArray() -> array
    {
        var key, value, arrayCopy;
        array arrayConfig;

        let arrayConfig = [],
            arrayCopy   = this->getArrayCopy();

        for key, value in arrayCopy {
            if typeof value === "object" && method_exists(value, "toArray") {
                let value = value->toArray();
            }

            let arrayConfig[key] = value;
        }

        return arrayConfig;
    }

    /**
     * Populates the internal collection
     */
    protected function fromArray(array arrayConfig) -> void
    {
        var key, value;

        for key, value in arrayConfig {
            this->offsetSet(key, value);
        }
    }

    /**
     * Performs a merge recursively
     */
    final private function internalMerge(array source, array target) -> array
    {
        var key, value;

        for key, value in target {
            if typeof value === "array" && isset source[key] && typeof source[key] === "array" {
                let source[key] = this->internalMerge(source[key], value);
            } elseif typeof key === "integer" {
                let source[] = value;
            } else {
                let source[key] = value;
            }
        }

        return source;
    }
}

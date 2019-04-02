
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
class Config implements \ArrayAccess, \Countable
{
    const DEFAULT_PATH_DELIMITER = ".";

    protected static pathDelimiter;

    /**
     * Phalcon\Config constructor
     */
    public function __construct(array! arrayConfig = null) -> void
    {
        var key, value;

        for key, value in arrayConfig {
            this->offsetSet(key, value);
        }
    }

    /**
     * Restores the state of a Phalcon\Config object
     */
    public static function __set_state(array! data) -> <Config>
    {
        return new self(data);
    }

    /**
     * Returns the count of properties set in the config
     *
     *<code>
     * print count($config);
     *</code>
     *
     * or
     *
     *<code>
     * print $config->count();
     *</code>
     */
    public function count() -> int
    {
        return count(get_object_vars(this));
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
        let index = strval(index);

        if isset this->{index} {
            return this->{index};
        }

        return defaultValue;
    }

    /**
     * Gets the default path delimiter
     */
    public static function getPathDelimiter() -> string
    {
        var delimiter;

        let delimiter = self::pathDelimiter;
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
        var config;

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

        return this->internalMerge(config);
    }

    /**
     * Gets an attribute using the array-syntax
     *
     *<code>
     * print_r(
     *     $config["database"]
     * );
     *</code>
     */
    public function offsetGet(var index) -> var
    {
        let index = strval(index);

        return this->{index};
    }


    /**
     * Allows to check whether an attribute is defined using the array-syntax
     *
     *<code>
     * var_dump(
     *     isset($config["database"])
     * );
     *</code>
     */
    public function offsetExists(var index) -> bool
    {
        let index = strval(index);

        return isset this->{index};
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
        let index = strval(index);

        if typeof value === "array" {
            let this->{index} = new self(value);
        } else {
            let this->{index} = value;
        }
    }

    /**
     * Unsets an attribute using the array-syntax
     *
     *<code>
     * unset($config["database"]);
     *</code>
     */
    public function offsetUnset(var index) -> void
    {
        let index = strval(index);

        unset this->{index};
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

        if isset this->{path} {
            return this->{path};
        }

        if empty delimiter {
            let delimiter = self::getPathDelimiter();
        }

        let config = this,
            keys = explode(delimiter, path);

        while !empty keys {
            let key = array_shift(keys);

            if !isset config->{key} {
                break;
            }

            if empty keys {
                return config->{key};
            }

            let config = config->{key};

            if empty config {
                break;
            }
        }

        return defaultValue;
    }

    /**
     * Sets the default path delimiter
     */
    public static function setPathDelimiter(string! delimiter = null) -> void
    {
        let self::pathDelimiter = delimiter;
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
        var key, value, arrayConfig;

        let arrayConfig = [];

        for key, value in get_object_vars(this) {
            if typeof value === "object" && method_exists(value, "toArray") {
                let value = value->toArray();
            }

            let arrayConfig[key] = value;
        }

        return arrayConfig;
    }

    /**
     * Helper method for merge configs (forwarding nested config instance)
     */
    final protected function internalMerge(<Config> config, <Config> instance = null) -> <Config>
    {
        var key, value, number, localObject, property;

        if typeof instance !== "object" {
            let instance = this;
        }

        let number = instance->count();

        for key, value in get_object_vars(config) {

            let property = strval(key);
            if fetch localObject, instance->{property} {
                if typeof localObject === "object" && typeof value === "object" {
                    if localObject instanceof Config && value instanceof Config {
                        this->internalMerge(value, localObject);
                        continue;
                    }
                }
            }

            if is_numeric(key) {
                let key = strval(key);
                while instance->offsetExists(key) {
                    /**
                     * Increment the number afterwards, because "number" starts
                     * at one not zero.
                     */
                    let key = strval(number);
                    let number++;
                }
             }
            let instance->{key} = value;
        }

        return instance;
    }
}


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Support\Collection;
use Phalcon\Config\ConfigInterface;
use Phalcon\Config\Exception;

/**
 * `Phalcon\Config` is designed to simplify the access to, and the use of,
 * configuration data within applications. It provides a nested object property
 * based user interface for accessing this configuration data within application
 * code.
 *
 *```php
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
 *```
 */
class Config extends Collection implements ConfigInterface
{
    const DEFAULT_PATH_DELIMITER = ".";

    /**
     * @var string|null
     */
    protected pathDelimiter = null;

    /**
     * Gets the default path delimiter
     *
     * @return string
     */
    public function getPathDelimiter() -> string
    {
        if unlikely !this->pathDelimiter {
            let this->pathDelimiter = self::DEFAULT_PATH_DELIMITER;
        }

        return this->pathDelimiter;
    }

    /**
     * Merges a configuration into the current one
     *
     *```php
     * $appConfig = new \Phalcon\Config(
     *     [
     *         "database" => [
     *             "host" => "localhost",
     *         ],
     *     ]
     * );
     *
     * $globalConfig->merge($appConfig);
     *```
     */
    public function merge(var toMerge) -> <ConfigInterface>
    {
        var config, result, source, target;

        if typeof toMerge === "array" {
            let config = new Config(toMerge);
        } elseif typeof toMerge === "object" && toMerge instanceof ConfigInterface {
            let config = toMerge;
        } else {
            throw new Exception("Invalid data type for merge.");
        }

        let source = this->toArray(),
            target = config->toArray(),
            result = this->internalMerge(source, target);

        this->clear();
        this->init(result);

        return this;
    }

    /**
     * Returns a value from current config using a dot separated path.
     *
     *```php
     * echo $config->path("unknown.path", "default", ".");
     *```
     */
    public function path(string path, defaultValue = null, var delimiter = null) -> var | null
    {
        var config, key, keys;

        if this->has(path) {
            return this->get(path);
        }

        if likely empty(delimiter) {
            let delimiter = this->getPathDelimiter();
        }

        let config = clone this,
            keys   = explode(delimiter, path);

        while (!empty(keys)) {
            let key = array_shift(keys);

            if !config->has(key) {
                break;
            }

            if empty(keys) {
                return config->get(key);
            }

            let config = config->get(key);
            if empty(config) {
                break;
            }
        }

        return defaultValue;
    }

    /**
     * Sets the default path delimiter
     */
    public function setPathDelimiter(string delimiter = null) -> <ConfigInterface>
    {
        let this->pathDelimiter = delimiter;

        return this;
    }

    /**
     * Converts recursively the object to an array
     *
     *```php
     * print_r(
     *     $config->toArray()
     * );
     *```
     */
    public function toArray() -> array
    {
        var data, key, value;
        array results;

        let results = [],
            data    = parent::toArray();

        for key, value in data {
            if typeof value === "object" && method_exists(value, "toArray") {
                let value = value->toArray();
            }

            let results[key] = value;
        }

        return results;
    }

    /**
     * Performs a merge recursively
     */
    final protected function internalMerge(array source, array target) -> array
    {
        var key, value;

        for key, value in target {
            if typeof value === "array" && isset source[key]  && typeof source[key] === "array" {
                let source[key] = this->internalMerge(source[key], value);
            } elseif typeof key === "int" {
                let source[] = value;
            } else {
                let source[key] = value;
            }
        }

        return source;
    }

    /**
     * Sets the collection data
     */
    protected function setData(var element, var value) -> void
    {
        var data, key;

        let element = (string) element,
            key     = (this->insensitive) ? mb_strtolower(element) : element;

        let this->lowerKeys[key] = element;

        if typeof value === "array" {
            let data = new Config(value);
        } else {
            let data = value;
        }

        let this->data[element]  = data;
    }
}


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config;

use Phalcon\Support\Collection;

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
 *
 * @property string $pathDelimiter
 */
class Config extends Collection implements ConfigInterface
{
    const DEFAULT_PATH_DELIMITER = ".";

    /**
     * @var string
     */
    protected pathDelimiter = self::DEFAULT_PATH_DELIMITER;

    /**
     * Gets the default path delimiter
     *
     * @return string
     */
    public function getPathDelimiter() -> string
    {
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
     *
     * @param array|ConfigInterface $toMerge
     *
     * @return ConfigInterface
     * @throws Exception
     */
    public function merge(var toMerge) -> <ConfigInterface>
    {
        var result, source;

        let source = this->toArray();

        this->clear();

        if typeof toMerge === "array" {
            let result = this->internalMerge(source, toMerge);

            this->init(result);

            return this;
        }

        if typeof toMerge === "object" && toMerge instanceof ConfigInterface {
            let result = this->internalMerge(source, toMerge->toArray());

            this->init(result);

            return this;
        }

        throw new Exception("Invalid data type for merge.");
    }

    /**
     * Returns a value from current config using a dot separated path.
     *
     *```php
     * echo $config->path("unknown.path", "default", ".");
     *```
     *
     * @param string      $path
     * @param mixed|null  $defaultValue
     * @param string|null $delimiter
     *
     * @return mixed
     */
    public function path(
        string path,
        var defaultValue = null,
        string delimiter = null
    ) -> var {
        var config, key, keys, pathDelimiter;

        if (true === this->has(path)) {
            return this->get(path);
        }

        let pathDelimiter = delimiter;
        if (true === empty(pathDelimiter)) {
            let pathDelimiter = this->pathDelimiter;
        }

        let config = clone this,
            keys   = explode(pathDelimiter, path);

        while (true !== empty(keys)) {
            let key = array_shift(keys);

            if (true !== config->has(key)) {
                break;
            }

            if (true === empty(keys)) {
                return config->get(key);
            }

            let config = config->get(key);

            if (true === empty(config)) {
                break;
            }
        }

        return defaultValue;
    }

    /**
     * Sets the default path delimiter
     *
     * @param string|null $delimiter
     *
     * @return ConfigInterface
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
     *
     * @return array
     */
    public function toArray() -> array
    {
        var data, key, value;
        array results;

        let results = [],
            data    = parent::toArray();

        for key, value in data {
            if (
                typeof value === "object" &&
                true === method_exists(value, "toArray")
            ) {
                let value = value->toArray();
            }

            let results[key] = value;
        }

        return results;
    }

    /**
     * Performs a merge recursively
     *
     * @param array $source
     * @param array $target
     *
     * @return array
     */
    final protected function internalMerge(array source, array target) -> array
    {
        var key, value;

        for key, value in target {
            if (
                typeof value === "array" &&
                true === isset(source[key]) &&
                typeof source[key] === "array"
            ) {
                let source[key] = this->internalMerge(source[key], value);

                continue;
            }

            let source[key] = value;
        }

        return source;
    }

    /**
     * Sets the collection data
     *
     * @param mixed $element
     * @param mixed $value
     */
    protected function setData(var element, var value) -> void
    {
        var data, key;
        let data    = this->data,
            element = (string) element,
            key     = (this->insensitive) ? mb_strtolower(element) : element;

        let this->lowerKeys[key] = element;

        if typeof value === "array" {
            let data[element] = new Config(value);
        } else {
            let data[element] = value;
        }

        let this->data = data;
    }
}

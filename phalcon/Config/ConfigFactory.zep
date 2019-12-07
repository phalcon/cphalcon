
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config;

use Phalcon\Config;
use Phalcon\Config\Adapter\Grouped;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Factory\Exception as FactoryException;
use Phalcon\Helper\Arr;

/**
 * Loads Config Adapter class using 'adapter' option, if no extension is
 * provided it will be added to filePath
 *
 *```php
 * use Phalcon\Config\ConfigFactory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 *
 * $config = (new ConfigFactory())->load($options);
 *```
 */
class ConfigFactory extends AbstractFactory
{
    /**
     * ConfigFactory constructor.
     */
    public function __construct(array services = [])
    {
        this->init(services);
    }

    /**
     * Load a config to create a new instance
     */
    public function load(config) -> object
    {
        var adapter, extension, first, oldConfig, second;

        if typeof config === "string" {
            let oldConfig = config,
                extension = pathinfo(config, PATHINFO_EXTENSION);

            if unlikely empty(extension) {
                throw new Exception(
                    "You need to provide the extension in the file path"
                );
            }

            let config = [
                "adapter"  : extension,
                "filePath" : oldConfig
            ];
        }

        if typeof config === "object" && config instanceof Config {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config object"
            );
        }

        if unlikely !isset config["filePath"] {
            throw new Exception(
                "You must provide 'filePath' option in factory config parameter."
            );
        }

        if unlikely !isset config["adapter"] {
            throw new Exception(
                "You must provide 'adapter' option in factory config parameter."
            );
        }

        let adapter = strtolower(config["adapter"]),
            first   = config["filePath"],
            second  = null;

        if !strpos(first, ".") {
            let first = first . "." . lcfirst(adapter);
        }

        if "ini" === adapter {
            let second = Arr::get(config, "mode", 1);
        } elseif "yaml" === adapter {
            let second = Arr::get(config, "callbacks", []);
        }

        return this->newInstance(adapter, first, second);
    }

    /**
     * Returns a new Config instance
     */
    public function newInstance(string name, string fileName, var params = null) -> object
    {
        var definition, options;

        this->checkService(name);

        let definition = this->mapper[name],
            options    = [],
            options[]  = fileName;

        if "json" !== name && "php" !== name {
            let options[] = params;
        }

        return create_instance_params(definition, options);
    }

    /**
     * Returns the adapters for the factory
     */
    protected function getAdapters() -> array
    {
        return [
            "grouped" : "Phalcon\\Config\\Adapter\\Grouped",
            "ini"     : "Phalcon\\Config\\Adapter\\Ini",
            "json"    : "Phalcon\\Config\\Adapter\\Json",
            "php"     : "Phalcon\\Config\\Adapter\\Php",
            "yaml"    : "Phalcon\\Config\\Adapter\\Yaml"
        ];
    }
}

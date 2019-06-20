
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Config;

use Phalcon\Config\Adapter\Grouped;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\Exception;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Factory\Exception as FactoryException;
use Phalcon\Helper\Arr;

/**
 * Loads Config Adapter class using 'adapter' option, if no extension is
 * provided it will be added to filePath
 *
 *<code>
 * use Phalcon\Config\ConfigFactory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 *
 * $config = (new ConfigFactory())->load($options);
 *</code>
 */
class ConfigFactory extends AbstractFactory
{
    /**
     * ConfigFactory constructor.
     *
     * @param array services
     */
    public function __construct(array services = [])
    {
        this->init(services);
    }

    /**
     * Load a config to create a new instance
     *
     * @param $config
     *
     * @return object
     * @throws Exception
     * @throws FactoryException
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
                "Config must be array or Phalcon\\Config\\Config object"
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
     * @param string $name
     * @param string $fileName
     * @param null   $params
     *
     * @return object
     * @throws FactoryException
     */
    public function newInstance(string name, string fileName, var params = null) -> object
    {
        var definition;

        this->checkService(name);

        if !isset this->services[name] {
            let definition = this->mapper[name];

            if "json" === name || "php" === name {
                let this->services[name] = new {definition}(fileName);
            } else {
                let this->services[name] = new {definition}(fileName, params);
            }
        }

        return this->services[name];
    }

    /**
     * Returns the adapters for the factory
     */
    protected function getAdapters() -> array
    {
        return [
            "grouped" : "\\Phalcon\\Config\\Adapter\\Grouped",
            "ini"     : "\\Phalcon\\Config\\Adapter\\Ini",
            "json"    : "\\Phalcon\\Config\\Adapter\\Json",
            "php"     : "\\Phalcon\\Config\\Adapter\\Php",
            "yaml"    : "\\Phalcon\\Config\\Adapter\\Yaml"
        ];
    }
}

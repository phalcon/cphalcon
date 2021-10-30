
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Config;

use Phalcon\Config\Config;
use Phalcon\Config\ConfigInterface;
use Phalcon\Factory\AbstractFactory;
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
     *
     * @param string|array|\Phalcon\Config\Config config = [
     *                                    'adapter'   => 'ini',
     *                                    'filePath'  => 'config.ini',
     *                                    'mode'      => null,
     *                                    'callbacks' => null
     *                                    ]
     *
     * @return ConfigInterface
     * @throws Exception
     */
    public function load(config) -> <ConfigInterface>
    {
        var adapter, configArray, filePath, param;

        let configArray = this->parseConfig(config),
            adapter     = strtolower(configArray["adapter"]),
            filePath    = configArray["filePath"];

        if true === empty(pathinfo(filePath, PATHINFO_EXTENSION)) {
            let filePath .= "." . lcfirst(adapter);
        }

        switch (adapter) {
            case "ini":
                let param = INI_SCANNER_RAW;
                if isset configArray["mode"] {
                    let param = configArray["mode"];
                }
                return this->newInstance(adapter, filePath, param);

            case "yaml":
                let param = null;
                if isset configArray["callbacks"] {
                    let param = configArray["callbacks"];
                }
                return this->newInstance(adapter, filePath, param);
        }

        return this->newInstance(adapter, filePath);
    }

    /**
     * Returns a new Config instance
     *
     * @param string     $name
     * @param string     $fileName
     * @param mixed|null $params
     *
     * @return ConfigInterface
     * @throws Exception
     */
    public function newInstance(
        string name,
        string fileName,
        params = null
    ) -> <ConfigInterface> {
        var definition;
        array arguments;

        let definition = this->getService(name),
            arguments  = [fileName];

        switch (name) {
            case "grouped":
            case "ini":
            case "yaml":
                if null !== params {
                    let arguments[] = params;
                }
                break;
        }

        return create_instance_params(definition, arguments);
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Config\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "grouped" : "Phalcon\\Config\\Adapter\\Grouped",
            "ini"     : "Phalcon\\Config\\Adapter\\Ini",
            "json"    : "Phalcon\\Config\\Adapter\\Json",
            "php"     : "Phalcon\\Config\\Adapter\\Php",
            "yaml"    : "Phalcon\\Config\\Adapter\\Yaml"
        ];
    }

    /**
     * @param mixed $config
     *
     * @return array
     * @throws Exception
     */
    protected function parseConfig(var config) -> array
    {
        var extension, oldConfig;

        if typeof config === "string" {
            let oldConfig = config,
                extension = pathinfo(config, PATHINFO_EXTENSION);

            if true  == empty(extension) {
                throw new Exception(
                    "You need to provide the extension in the file path"
                );
            }

            let config = [
                "adapter"  : extension,
                "filePath" : oldConfig
            ];
        }

        if typeof config === "object" && config instanceof ConfigInterface {
            let config = config->toArray();
        }

        if typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config\\Config object"
            );
        }

        this->checkConfigArray(config);

        return config;
    }

    /**
     * @param array $config
     *
     * @throws Exception
     */
    private function checkConfigArray(array config) -> void
    {
        if true !== isset(config["filePath"]) {
            throw new Exception(
                "You must provide 'filePath' option in factory config parameter."
            );
        }

        if true !== isset(config["adapter"]) {
            throw new Exception(
                "You must provide 'adapter' option in factory config parameter."
            );
        }
    }
}

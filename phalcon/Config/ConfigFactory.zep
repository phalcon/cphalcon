
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
use Phalcon\Config\Exceptions\ConfigNotArrayOrObject;
use Phalcon\Config\Exceptions\MissingConfigOption;
use Phalcon\Config\Exceptions\MissingFileExtension;
use Phalcon\Factory\AbstractFactory;

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
        var adapter, aliases, configArray, filePath, param, spec;

        let configArray = this->parseConfig(config),
            adapter     = strtolower(configArray["adapter"]),
            filePath    = configArray["filePath"];

        if true === empty(pathinfo(filePath, PATHINFO_EXTENSION)) {
            let filePath .= "." . adapter;
        }

        let aliases = this->getAdapterAliases();

        if isset aliases[adapter] {
            let adapter = aliases[adapter];
        }

        let spec = this->getExtraArguments();

        if isset spec[adapter] && null !== spec[adapter]["option"] {
            let param = spec[adapter]["default"];

            if isset configArray[spec[adapter]["option"]] {
                let param = configArray[spec[adapter]["option"]];
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
        var definition, spec;
        array arguments;

        let definition = this->getService(name),
            arguments  = [fileName],
            spec       = this->getExtraArguments();

        if null !== params && isset spec[name] {
            let arguments[] = params;
        }

        return create_instance_params(definition, arguments);
    }

    /**
     * Adapter name aliases resolved by `load()` (file extensions that map
     * to a registered adapter)
     *
     * @return array<string, string>
     */
    protected function getAdapterAliases() -> array
    {
        return [
            "yml" : "yaml"
        ];
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Config\\Exception";
    }

    /**
     * Adapters accepting an extra constructor argument, with the config
     * option carrying it and its default value. Single source for the
     * parameter-forwarding knowledge used by `load()` and `newInstance()`.
     *
     * @return array<string, array>
     */
    protected function getExtraArguments() -> array
    {
        return [
            "grouped" : ["option" : null,        "default" : null],
            "ini"     : ["option" : "mode",      "default" : INI_SCANNER_RAW],
            "yaml"    : ["option" : "callbacks", "default" : null]
        ];
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
                throw new MissingFileExtension();
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
            throw new ConfigNotArrayOrObject();
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
            throw new MissingConfigOption("filePath");
        }

        if true !== isset(config["adapter"]) {
            throw new MissingConfigOption("adapter");
        }
    }
}

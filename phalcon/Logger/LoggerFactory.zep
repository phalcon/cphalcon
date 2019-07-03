
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Phalcon\Config\Config;
use Phalcon\Helper\Arr;
use Phalcon\Logger\Logger;
use Phalcon\Logger\AdapterFactory;

/**
 * PhalconNG\Logger\LoggerFactory
 *
 * Logger factory
 */
class LoggerFactory
{
    /**
     * @var AdapterFactory
     */
    private adapterFactory;

    public function __construct(<AdapterFactory> factory)
    {
        let this->adapterFactory = factory;
    }

    /**
     * Factory to create an instace from a Config object
     */
    public function load(var config) -> var
    {
        var adapter, adapterClass, adapterFileName, adapterOptions,
            adapters, name, options;
        array data;

        if typeof config == "object" && config instanceof Config {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config object"
            );
        }

        if unlikely !isset config["name"] {
            throw new Exception(
                "You must provide 'name' option in factory config parameter."
            );
        }

        let name     = config["name"],
            options  = Arr::get(config, "options", []),
            adapters = Arr::get(config, "adapters", []),
            data     = [];

        for adapter in adapters {
            let adapterClass    = Arr::get(adapter, "adapter"),
                adapterFileName = Arr::get(adapter, "name"),
                adapterOptions  = Arr::get(adapter, "options", []);

            let data[] = this->adapterFactory->newInstance(
                adapterClass,
                adapterFileName,
                adapterOptions
            );
        }

        return this->newInstance(name, data);
    }

    /**
     * Returns a Logger object
     *
     * @param string $name
     * @param array  $adapters
     *
     * @return Logger
     */
    public function newInstance(string! name, array! adapters = []) -> <Logger>
    {
        return new Logger(name, adapters);
    }
}

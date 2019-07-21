
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

use Phalcon\Config;
use Phalcon\Factory\Exception;

class AbstractFactory
{
    /**
     * @var array
     */
    protected mapper = [];

    /**
     * @var array
     */
    protected services = [];

    /**
     * Checks if a service exists and throws an exception
     */
    protected function checkService(string! name) -> void
    {
        if unlikely !isset this->mapper[name] {
            throw new Exception("Service " . name . " is not registered");
        }
    }

    /**
     * Checks the config if it is a valid object
     */
    protected function checkConfig(var config) -> array
    {
        if typeof config == "object" && config instanceof Config {
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw new Exception(
                "Config must be array or Phalcon\\Config object"
            );
        }

        if unlikely !isset config["adapter"] {
            throw new Exception(
                "You must provide 'adapter' option in factory config parameter."
            );
        }

        return config;
    }

    /**
     * Returns the adapters for the factory
     */
    abstract protected function getAdapters() -> array;

    /**
     * AdapterFactory constructor.
     */
    protected function init(array! services = []) -> void
    {
        var adapters, name, service;

        let adapters = this->getAdapters(),
            adapters = array_merge(adapters, services);

        for name, service in adapters {
            let this->mapper[name] = service;
            unset(this->services[name]);
        }
    }
}

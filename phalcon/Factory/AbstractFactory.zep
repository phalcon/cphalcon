
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

use Phalcon\Config\ConfigInterface;

abstract class AbstractFactory extends AbstractConfigFactory
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
     * Returns the adapters for the factory
     *
     * @return string[]
     */
    abstract protected function getServices() -> array;

    /**
     * Checks if a service exists and throws an exception
     */
    protected function getService(string! name) -> var
    {
        if unlikely !isset this->mapper[name] {
            throw this->getException("Service " . name . " is not registered");
        }

        return this->mapper[name];
    }

    /**
     * AdapterFactory constructor.
     */
    protected function init(array! services = []) -> void
    {
        var adapters, name, service;

        let adapters = this->getServices(),
            adapters = array_merge(adapters, services);

        for name, service in adapters {
            let this->mapper[name] = service;
            unset(this->services[name]);
        }
    }
}

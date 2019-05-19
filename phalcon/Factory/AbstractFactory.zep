
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

class AbstractFactory
{
    /**
     * @var array
     */
    protected mapper   = [];

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
     * Returns the adapters for the factory
     */
    abstract protected function getAdapters() -> array;

    /**
     * AdapterFactory constructor.
     */
    protected function init(array! services = [])
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

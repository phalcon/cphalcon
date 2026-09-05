
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

use Exception as BaseException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Factory\FactoryTypes;

/**
 * @phpstan-import-type factory_instances from FactoryTypes
 * @phpstan-import-type factory_services from FactoryTypes
 */
abstract class AbstractFactory extends AbstractConfigFactory
{
    /**
     * @phpstan-var factory_services
     */
    protected array mapper = [];

    /**
     * @phpstan-var factory_instances
     */
    protected array services = [];

    /**
     * Checks if a service exists and throws an exception
     */
    protected function getService(string name) -> var
    {
        if unlikely !isset this->mapper[name] {
            throw this->getException("Service " . name . " is not registered");
        }

        return this->mapper[name];
    }

    /**
     * Returns the adapters for the factory
     *
     * @phpstan-return factory_services
     */
    abstract protected function getServices() -> array;

    /**
     * Initialize services/add new services
     *
     * @phpstan-param factory_services $services
     */
    protected function init(array services = []) -> void
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

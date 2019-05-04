
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Service;

/**
 * Phalcon\Service\AbstractLocator
 *
 * Lazy loads, stores and exposes objects
 */
class AbstractLocator
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
     * Key value pairs with name as the key and a callable as the value for
     * the service object
     */
    public function __construct(array! mapper = []) -> void
    {
        this->init(mapper);
    }

    /**
     * Get a service. If it is not in the mapper array, create a new object,
     * set it and then return it.
     */
    public function get(string! name, array! options = []) -> object
    {
        var definition, instance;

        if unlikely !isset this->mapper[name] {
            throw new Exception(
                "The service " . name . " has not been found in the locator"
            );
        }

        if !isset(this->services[name]) {
            let definition           = this->mapper[name],
                instance             = new \ReflectionClass(definition),
                this->services[name] = instance->newInstanceArgs(options);
        }

        return this->services[name];
    }

    /**
     * Checks if a service exists in the map array
     */
    public function has(string! name) -> bool
    {
        return isset this->mapper[name];
    }

    /**
     * Set a new service to the mapper array
     */
    public function set(string! name, callable service) -> void
    {
        let this->mapper[name] = service;

        unset this->services[name];
    }

    /**
     * Loads the objects in the internal mapper array
     */
    protected function init(array! mapper) -> void
    {
        var name, service;

        for name, service in mapper {
            this->set(name, service);
        }
    }
}

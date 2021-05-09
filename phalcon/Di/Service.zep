
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Closure;
use Phalcon\Di\Exception\ServiceResolutionException;
use Phalcon\Di\Service\Builder;

/**
 * Represents individually a service in the services container
 *
 *```php
 * $service = new \Phalcon\Di\Service(
 *     "request",
 *     \Phalcon\Http\Request::class
 * );
 *
 * $request = service->resolve();
 *```
 */
class Service implements ServiceInterface
{
    /**
     * @var mixed
     */
    protected definition;

    /**
     * @var bool
     */
    protected resolved = false;

    /**
     * @var bool
     */
    protected shared = false;

    /**
     * @var mixed|null
     */
    protected sharedInstance = null;

    /**
     * Phalcon\Di\Service
     */
    final public function __construct(var definition, bool shared = false)
    {
        let this->definition = definition,
            this->shared = shared;
    }

    /**
     * Returns the service definition
     */
    public function getDefinition() -> var
    {
        return this->definition;
    }

    /**
     * Returns a parameter in a specific position
     *
     * @return array
     */
    public function getParameter(int position)
    {
        var definition, arguments, parameter;

        let definition = this->definition;

        if unlikely typeof definition != "array" {
            throw new Exception(
                "Definition must be an array to obtain its parameters"
            );
        }

        /**
         * Update the parameter
         */
        if fetch arguments, definition["arguments"] {
            if fetch parameter, arguments[position] {
                return parameter;
            }
        }

        return null;
    }

    /**
     * Returns true if the service was resolved
     */
    public function isResolved() -> bool
    {
        return this->resolved;
    }

    /**
     * Check whether the service is shared or not
     */
    public function isShared() -> bool
    {
        return this->shared;
    }

    /**
     * Resolves the service
     *
     * @param array parameters
     */
    public function resolve(parameters = null, <DiInterface> container = null) -> var
    {
        bool found;
        var shared, definition, sharedInstance, instance, builder;

        let shared = this->shared;

        /**
         * Check if the service is shared
         */
        if shared {
            let sharedInstance = this->sharedInstance;
            if sharedInstance !== null {
                return sharedInstance;
            }
        }

        let found = true,
            instance = null;

        let definition = this->definition;
        if typeof definition == "string" {
            /**
             * String definitions can be class names without implicit parameters
             */
            if container !== null {
                let instance = container->get(definition, parameters);
            } elseif class_exists(definition) {
                if typeof parameters == "array" && count(parameters) {
                    let instance = create_instance_params(
                        definition,
                        parameters
                    );
                } else {
                    let instance = create_instance(definition);
                }
            } else {
                let found = false;
            }
        } else {

            /**
             * Object definitions can be a Closure or an already resolved
             * instance
             */
            if typeof definition == "object" {
                if definition instanceof Closure {

                    /**
                     * Bounds the closure to the current DI
                     */
                    if typeof container == "object" {
                        let definition = Closure::bind(definition, container);
                    }

                    if typeof parameters == "array" {
                        let instance = call_user_func_array(
                            definition,
                            parameters
                        );
                    } else {
                        let instance = call_user_func(definition);
                    }
                } else {
                    let instance = definition;
                }
            } else {
                /**
                 * Array definitions require a 'className' parameter
                 */
                if typeof definition == "array" {
                    let builder = new Builder(),
                        instance = builder->build(
                            container,
                            definition,
                            parameters
                        );
                } else {
                    let found = false;
                }
            }
        }

        /**
         * If the service can't be built, we must throw an exception
         */
        if unlikely found === false {
            throw new ServiceResolutionException();
        }

        /**
         * Update the shared instance if the service is shared
         */
        if shared {
            let this->sharedInstance = instance;
        }

        let this->resolved = true;

        return instance;
    }

    /**
     * Set the service definition
     */
    public function setDefinition(var definition) -> void
    {
        let this->definition = definition;
    }

    /**
     * Changes a parameter in the definition without resolve the service
     */
    public function setParameter(int position, array! parameter) -> <ServiceInterface>
    {
        var definition, arguments;

        let definition = this->definition;

        if unlikely typeof definition != "array" {
            throw new Exception(
                "Definition must be an array to update its parameters"
            );
        }

        /**
         * Update the parameter
         */
        if fetch arguments, definition["arguments"] {
            let arguments[position] = parameter;
        } else {
            let arguments = [position: parameter];
        }

        /**
         * Re-update the arguments
         */
        let definition["arguments"] = arguments;

        /**
         * Re-update the definition
         */
        let this->definition = definition;

        return this;
    }

    /**
     * Sets if the service is shared or not
     */
    public function setShared(bool shared) -> void
    {
        let this->shared = shared;
    }

    /**
     * Sets/Resets the shared instance related to the service
     */
    public function setSharedInstance(var sharedInstance) -> void
    {
        let this->sharedInstance = sharedInstance;
    }
}

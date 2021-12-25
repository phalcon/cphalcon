
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Service;

use Phalcon\Di\DiInterface;
use Phalcon\Di\Exception;

/**
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
class Builder
{
    /**
     * Builds a service using a complex service definition
     *
     * @param array parameters
     * @return mixed
     */
    public function build(<DiInterface> container, array! definition, parameters = null)
    {
        var className, arguments, paramCalls, methodPosition, method,
            methodName, methodCall, instance, propertyPosition, property,
            propertyName, propertyValue;

        /**
         * The class name is required
         */
        if unlikely !fetch className, definition["className"] {
            throw new Exception(
                "Invalid service definition. Missing 'className' parameter"
            );
        }

        if typeof parameters == "array" {

            /**
             * Build the instance overriding the definition constructor
             * parameters
             */
            if count(parameters) {
                let instance = create_instance_params(className, parameters);
            } else {
                let instance = create_instance(className);
            }

        } else {

            /**
             * Check if the argument has constructor arguments
             */
            if fetch arguments, definition["arguments"] {

                /**
                 * Create the instance based on the parameters
                 */
                let instance = create_instance_params(
                    className,
                    this->buildParameters(container, arguments)
                );

            } else {
                let instance = create_instance(className);
            }
        }

        /**
         * The definition has calls?
         */
        if fetch paramCalls, definition["calls"] {
            if unlikely typeof instance != "object" {
                throw new Exception(
                    "The definition has setter injection parameters but the constructor didn't return an instance"
                );
            }

            if unlikely typeof paramCalls != "array" {
                throw new Exception(
                    "Setter injection parameters must be an array"
                );
            }

            /**
             * The method call has parameters
             */
            for methodPosition, method in paramCalls {

                /**
                 * The call parameter must be an array of arrays
                 */
                if unlikely typeof method != "array" {
                    throw new Exception(
                        "Method call must be an array on position " . methodPosition
                    );
                }

                /**
                 * A param 'method' is required
                 */
                if unlikely !fetch methodName, method["method"] {
                    throw new Exception(
                        "The method name is required on position " . methodPosition
                    );
                }

                /**
                 * Create the method call
                 */
                let methodCall = [instance, methodName];

                if fetch arguments, method["arguments"] {
                    if unlikely typeof arguments != "array" {
                        throw new Exception(
                            "Call arguments must be an array on position " .
                            (string) methodPosition
                        );
                    }

                    if count(arguments) {
                        /**
                         * Call the method on the instance
                         */
                        call_user_func_array(
                            methodCall,
                            this->buildParameters(container, arguments)
                        );

                        /**
                         * Go to next method call
                         */
                        continue;
                    }
                }

                /**
                 * Call the method on the instance without arguments
                 */
                call_user_func(methodCall);
            }
        }

        /**
         * The definition has properties?
         */
        if fetch paramCalls, definition["properties"] {

            if unlikely typeof instance != "object" {
                throw new Exception(
                    "The definition has properties injection parameters but the constructor didn't return an instance"
                );
            }

            if unlikely typeof paramCalls != "array" {
                throw new Exception(
                    "Setter injection parameters must be an array"
                );
            }

            /**
             * The method call has parameters
             */
            for propertyPosition, property in paramCalls {

                /**
                 * The call parameter must be an array of arrays
                 */
                if unlikely typeof property != "array" {
                    throw new Exception(
                        "Property must be an array on position " . propertyPosition
                    );
                }

                /**
                 * A param 'name' is required
                 */
                if unlikely !fetch propertyName, property["name"] {
                    throw new Exception(
                        "The property name is required on position " . propertyPosition
                    );
                }

                /**
                 * A param 'value' is required
                 */
                if unlikely !fetch propertyValue, property["value"] {
                    throw new Exception(
                        "The property value is required on position " . propertyPosition
                    );
                }

                /**
                 * Update the public property
                 */
                let instance->{propertyName} = this->buildParameter(
                    container,
                    propertyPosition,
                    propertyValue
                );
            }
        }

        return instance;
    }

    /**
     * Resolves a constructor/call parameter
     *
     * @return mixed
     */
    private function buildParameter(<DiInterface> container, int position, array! argument)
    {
        var type, name, value, instanceArguments;

        /**
         * All the arguments must have a type
         */
        if unlikely !fetch type, argument["type"] {
            throw new Exception(
                "Argument at position " . position . " must have a type"
            );
        }

        switch type {

            /**
             * If the argument type is 'service', we obtain the service from the
             * DI
             */
            case "service":
                if unlikely !fetch name, argument["name"] {
                    throw new Exception(
                        "Service 'name' is required in parameter on position " . position
                    );
                }

                if unlikely typeof container != "object" {
                    throw new Exception(
                        "The dependency injector container is not valid"
                    );
                }

                return container->get(name);

            /**
             * If the argument type is 'parameter', we assign the value as it is
             */
            case "parameter":
                if unlikely !fetch value, argument["value"] {
                    throw new Exception(
                        "Service 'value' is required in parameter on position " . position
                    );
                }

                return value;

            /**
             * If the argument type is 'instance', we assign the value as it is
             */
            case "instance":

                if unlikely !fetch name, argument["className"] {
                    throw new Exception(
                        "Service 'className' is required in parameter on position " . position
                    );
                }

                if unlikely typeof container != "object" {
                    throw new Exception(
                        "The dependency injector container is not valid"
                    );
                }

                if fetch instanceArguments, argument["arguments"] {
                    /**
                     * Build the instance with arguments
                     */
                    return container->get(name, instanceArguments);
                }

                /**
                 * The instance parameter does not have arguments for its
                 * constructor
                 */
                return container->get(name);

            default:
                /**
                 * Unknown parameter type
                 */
                throw new Exception(
                    "Unknown service type in parameter on position " . position
                );
        }
    }

    /**
     * Resolves an array of parameters
     */
    private function buildParameters(<DiInterface> container, array! arguments) -> array
    {
        var position, argument;
        array buildArguments;

        let buildArguments = [];

        for position, argument in arguments {
            let buildArguments[] = this->buildParameter(
                container,
                position,
                argument
            );
        }

        return buildArguments;
    }
}

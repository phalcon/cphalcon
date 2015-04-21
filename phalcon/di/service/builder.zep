
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Di\Service;

use Phalcon\Di\Exception;
use Phalcon\DiInterface;

/**
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
class Builder
{

	/**
	 * Resolves a constructor/call parameter
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param int position
	 * @param array argument
	 * @return mixed
	 */
	private function _buildParameter(<DiInterface> dependencyInjector, int position, array! argument)
	{
		var type, name, value, instanceArguments;

		/**
		 * All the arguments must have a type
		 */
		if !fetch type, argument["type"] {
			throw new Exception("Argument at position " . position . " must have a type");
		}

		switch type {

			/**
			 * If the argument type is 'service', we obtain the service from the DI
			 */
			case "service":
				if !fetch name, argument["name"] {
					throw new Exception("Service 'name' is required in parameter on position " . position);
				}
				if typeof dependencyInjector != "object" {
					throw new Exception("The dependency injector container is not valid");
				}
				return dependencyInjector->get(name);

			/**
			 * If the argument type is 'parameter', we assign the value as it is
			 */
			case "parameter":
				if !fetch value, argument["value"] {
					throw new Exception("Service 'value' is required in parameter on position " . position);
				}
				return value;

			/**
			 * If the argument type is 'instance', we assign the value as it is
			 */
			case "instance":

				if !fetch name, argument["className"] {
					throw new Exception("Service 'className' is required in parameter on position " . position);
				}

				if typeof dependencyInjector != "object" {
					throw new Exception("The dependency injector container is not valid");
				}

				if fetch instanceArguments, argument["arguments"] {
					/**
					 * Build the instance with arguments
					 */
					return dependencyInjector->get(name, instanceArguments);
				}

				/**
				 * The instance parameter does not have arguments for its constructor
				 */
				return dependencyInjector->get(name);

			default:
				/**
				 * Unknown parameter type
				 */
				throw new Exception("Unknown service type in parameter on position " . position);
		}
	}

	/**
	 * Resolves an array of parameters	 	 
	 */
	private function _buildParameters(<DiInterface> dependencyInjector, array! arguments) -> array
	{
		var position, argument, buildArguments;

		let buildArguments = [];
		for position, argument in arguments {
			let buildArguments[] = this->_buildParameter(dependencyInjector, position, argument);
		}
		return buildArguments;
	}

	/**
	 * Builds a service using a complex service definition
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param array definition
	 * @param array parameters
	 * @return mixed
	 */
	public function build(<DiInterface> dependencyInjector, array! definition, parameters = null)
	{
		var className, arguments, paramCalls, methodPosition, method,
			methodName, methodCall, instance, propertyPosition, property,
			propertyName, propertyValue, reflection;

		/**
		 * The class name is required
		 */
		if !fetch className, definition["className"] {
			throw new Exception("Invalid service definition. Missing 'className' parameter");
		}

		if typeof parameters == "array" {

			/**
			 * Build the instance overriding the definition constructor parameters
			 */
			if count(parameters) {
				if is_php_version("5.6") {
					let reflection = new \ReflectionClass(className),
						instance = reflection->newInstanceArgs(parameters);
				} else {
					let instance = create_instance_params(className, parameters);
				}
			} else {
				if is_php_version("5.6") {
					let reflection = new \ReflectionClass(className),
						instance = reflection->newInstance();
				} else {
					let instance = create_instance(className);
				}
			}

		} else {

			/**
			 * Check if the argument has constructor arguments
			 */
			if fetch arguments, definition["arguments"] {

				/**
				 * Create the instance based on the parameters
				 */
				let instance = create_instance_params(className, this->_buildParameters(dependencyInjector, arguments));

			} else {
				if is_php_version("5.6") {
					let reflection = new \ReflectionClass(className),
						instance = reflection->newInstance();
				} else {
					let instance = create_instance(className);
				}
			}
		}

		/**
		 * The definition has calls?
		 */
		if fetch paramCalls, definition["calls"] {

			if typeof instance != "object" {
				throw new Exception("The definition has setter injection parameters but the constructor didn't return an instance");
			}

			if typeof paramCalls != "array" {
				throw new Exception("Setter injection parameters must be an array");
			}

			/**
			 * The method call has parameters
			 */
			for methodPosition, method in paramCalls {

				/**
				 * The call parameter must be an array of arrays
				 */
				if typeof method != "array" {
					throw new Exception("Method call must be an array on position " . methodPosition);
				}

				/**
				 * A param 'method' is required
				 */
				if !fetch methodName, method["method"] {
					throw new Exception("The method name is required on position " . methodPosition);
				}

				/**
				 * Create the method call
				 */
				let methodCall = [instance, methodName];

				if fetch arguments, method["arguments"] {

					if typeof arguments != "array" {
						throw new Exception("Call arguments must be an array " . methodPosition);
					}

					if count(arguments) {

						/**
						 * Call the method on the instance
						 */
						call_user_func_array(methodCall, this->_buildParameters(dependencyInjector, arguments));

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

			if typeof instance != "object" {
				throw new Exception("The definition has properties injection parameters but the constructor didn't return an instance");
			}

			if typeof paramCalls != "array" {
				throw new Exception("Setter injection parameters must be an array");
			}

			/**
			 * The method call has parameters
			 */
			for propertyPosition, property in paramCalls {

				/**
				 * The call parameter must be an array of arrays
				 */
				if typeof property != "array" {
					throw new Exception("Property must be an array on position " . propertyPosition);
				}

				/**
				 * A param 'name' is required
				 */
				if !fetch propertyName, property["name"] {
					throw new Exception("The property name is required on position " . propertyPosition);
				}

				/**
				 * A param 'value' is required
				 */
				if !fetch propertyValue, property["value"] {
					throw new Exception("The property value is required on position " . propertyPosition);
				}

				/**
				 * Update the public property
				 */
				let instance->{propertyName} = this->_buildParameter(dependencyInjector, propertyPosition, propertyValue);
			}

		}

		return instance;
	}
}

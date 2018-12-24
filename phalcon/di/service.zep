
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\DiInterface;
use Phalcon\Di\Exception;
use Phalcon\Di\Exception\ServiceResolutionException;
use Phalcon\Di\ServiceInterface;
use Phalcon\Di\Service\Builder;

/**
 * Phalcon\Di\Service
 *
 * Represents individually a service in the services container
 *
 *<code>
 * $service = new \Phalcon\Di\Service(
 *     "request",
 *     "Phalcon\\Http\\Request"
 * );
 *
 * $request = service->resolve();
 *</code>
 */
class Service implements ServiceInterface
{

	protected _definition;

	protected _shared = false;

	protected _resolved = false;

	protected _sharedInstance;

	/**
	 * Phalcon\Di\Service
	 *
	 * @param mixed definition
	 */
	public final function __construct(definition, bool shared = false)
	{
		let this->_definition = definition,
			this->_shared = shared;
	}

	/**
	 * Sets if the service is shared or not
	 */
	public function setShared(bool shared) -> void
	{
		let this->_shared = shared;
	}

	/**
	 * Check whether the service is shared or not
	 */
	public function isShared() -> bool
	{
		return this->_shared;
	}

	/**
	 * Sets/Resets the shared instance related to the service
	 *
	 * @param mixed sharedInstance
	 */
	public function setSharedInstance(sharedInstance) -> void
	{
		let this->_sharedInstance = sharedInstance;
	}

	/**
	 * Set the service definition
	 *
	 * @param mixed definition
	 */
	public function setDefinition(definition) -> void
	{
		let this->_definition = definition;
	}

	/**
	 * Returns the service definition
	 *
	 * @return mixed
	 */
	public function getDefinition()
	{
		return this->_definition;
	}

	/**
	 * Resolves the service
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public function resolve(parameters = null, <DiInterface> dependencyInjector = null)
	{
		bool found;
		var shared, definition, sharedInstance, instance, builder;

		let shared = this->_shared;

		/**
		 * Check if the service is shared
		 */
		if shared {
			let sharedInstance = this->_sharedInstance;
			if sharedInstance !== null {
				return sharedInstance;
			}
		}

		let found = true,
			instance = null;

		let definition = this->_definition;
		if typeof definition == "string" {

			/**
			 * String definitions can be class names without implicit parameters
			 */
			if class_exists(definition) {
				if typeof parameters == "array" {
					if count(parameters) {
						let instance = create_instance_params(definition, parameters);
					} else {
						let instance = create_instance(definition);
					}
				} else {
					let instance = create_instance(definition);
				}
			} else {
				let found = false;
			}
		} else {

			/**
			 * Object definitions can be a Closure or an already resolved instance
			 */
			if typeof definition == "object" {
				if definition instanceof \Closure {

					/**
					 * Bounds the closure to the current DI
					 */
					if typeof dependencyInjector == "object" {
						let definition = \Closure::bind(definition, dependencyInjector);
					}

					if typeof parameters == "array" {
						let instance = call_user_func_array(definition, parameters);
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
						instance = builder->build(dependencyInjector, definition, parameters);
				} else {
					let found = false;
				}
			}
		}

		/**
		 * If the service can't be built, we must throw an exception
		 */
		if found === false {
			throw new ServiceResolutionException();
		}

		/**
		 * Update the shared instance if the service is shared
		 */
		if shared {
			let this->_sharedInstance = instance;
		}

		let this->_resolved = true;

		return instance;
	}

	/**
	 * Changes a parameter in the definition without resolve the service
	 */
	public function setParameter(int position, array! parameter) -> <ServiceInterface>
	{
		var definition, arguments;

		let definition = this->_definition;
		if typeof definition != "array" {
			throw new Exception("Definition must be an array to update its parameters");
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
		let this->_definition = definition;

		return this;
	}

	/**
	 * Returns a parameter in a specific position
	 *
	 * @return array
	 */
	public function getParameter(int position)
	{
		var definition, arguments, parameter;

		let definition = this->_definition;
		if typeof definition != "array" {
			throw new Exception("Definition must be an array to obtain its parameters");
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
		return this->_resolved;
	}

	/**
	 * Restore the internal state of a service
	 */
	public static function __set_state(array! attributes) -> <ServiceInterface>
	{
		var definition, shared;

		if !fetch definition, attributes["_definition"] {
			throw new Exception("The attribute '_definition' is required");
		}

		if !fetch shared, attributes["_shared"] {
			throw new Exception("The attribute '_shared' is required");
		}

		return new self(definition, shared);
	}
}

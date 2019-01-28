
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Service;

use Phalcon\Service\LocatorInterface;

/**
 * Phalcon\Service\Locator
 *
 * Lazy loads, stores and exposes objects
 */
class Locator implements LocatorInterface
{
	/**
	 * @var array
	 */
	protected services = [];

	/**
	 * @var array
	 */
	protected mapper = [];

	/**
	 * Key value pairs with name as the key and a callable as the value for
	 * the service object
	 */
	public function __construct(array! mapper = []) -> void
	{
		let this->mapper = mapper;
	}

	/**
	 * Services being called via magic methods
	 */
	public function __call(string name, array parameters) -> var
	{
		var service;

		let service = this->get(name);
		return call_user_func_array(service, parameters);
	}

	/**
	 * Get a service. If it is not in the mapper array, create a new object,
	 * set it and then return it.
	 */
	public function get(string! name) -> object
	{
		var definition, service;

		if (true !== this->has(name)) {
			throw new Exception("The service " . name . " has not been found in the locator");
		}

		if (true !== isset(this->services[name])) {
			let definition = this->mapper[name];

			if typeof definition == "string" {
				let service = new {definition}();
			} else {
				let service = definition;
			}

			let this->services[name] = service;
		}

		return this->services[name];
	}

	/**
	 * Checks if a service exists in the map array
	 */
	public function has(string! name) -> bool
	{
		return isset(this->mapper[name]);
	}

	/**
	 * Set a new service to the mapper array
	 */
	public function set(string! name, callable service) -> void
	{
		let this->mapper[name] = service;

		unset(this->services[name]);
	}
}

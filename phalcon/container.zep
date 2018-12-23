
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Psr\Container\ContainerInterface;
use Phalcon\DiInterface;

class Container implements ContainerInterface
{
	/**
	 * @var <DiInterface>
	 */
	protected container;

	/**
	 * Phalcon\Di constructor
	 */
	public function __construct(<DiInterface> container)
	{
		let this->container = container;
	}

	/**
	 * Return the service
	 */
	public function get(var name) -> var
	{
		return this->container->getService(name);
	}

	/**
	 * Whether a service exists or not in the container
	 */
	public function has(var name) -> bool
	{
		return this->container->has(name);
	}
}

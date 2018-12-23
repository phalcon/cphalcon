
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

/**
 * Phalcon\Di\InjectionAwareInterface
 *
 * This interface must be implemented in those classes that uses internally the Phalcon\Di that creates them
 */
interface InjectionAwareInterface
{

	/**
	 * Sets the dependency injector
	 */
	public function setDI(<DiInterface> dependencyInjector);

	/**
	 * Returns the internal dependency injector
	 */
	public function getDI() -> <DiInterface>;
}

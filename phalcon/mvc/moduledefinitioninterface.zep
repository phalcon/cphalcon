
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\DiInterface;

/**
 * Phalcon\Mvc\ModuleDefinitionInterface
 *
 * This interface must be implemented by class module definitions
 */
interface ModuleDefinitionInterface
{

	/**
	 * Registers an autoloader related to the module
	 */
	public function registerAutoloaders(<DiInterface> dependencyInjector = null);

	/**
	 * Registers services related to the module
	 */
	public function registerServices(<DiInterface> dependencyInjector);
}

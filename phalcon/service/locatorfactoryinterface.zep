
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
 * Phalcon\Service\LocatorFactoryInterface
 *
 * Interface for a Locator Factory
 */
interface LocatorFactoryInterface
{
	/**
	 * New instance of the locator
	 */
	public function newInstance() -> <LocatorInterface>;
}

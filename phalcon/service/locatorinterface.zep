
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
 * Phalcon\Service\LocatorInterface
 *
 * Interface for the Locator
 */
interface LocatorInterface
{
	/**
	 * Get a helper. If it is not in the mapper array, create a new object,
	 * set it and then return it.
	 */
	public function get(string! name) -> object;

	/**
	 * Checks if a helper exists in the map array
	 */
	public function has(string! name) -> bool;

	/**
	 * Set a new helper to the mapper array
	 */
	public function set(string! name, callable helper) -> void;
}

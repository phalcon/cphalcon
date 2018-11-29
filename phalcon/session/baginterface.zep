/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

/**
 * Phalcon\Session\BagInterface
 *
 * Interface for Phalcon\Session\Bag
 */
interface BagInterface
{
	/**
	 * Getter of values
	 */
	public function __get(string! property) -> var;

	/**
	 * Isset property
	 */
	public function __isset(string! property) -> bool;

	/**
	 * Setter of values
	 */
	public function __set(string! property, var value);

	/**
	 * Destroys the session bag
	 */
	public function destroy();

	/**
	 * Getter of values
	 */
	public function get(string! property, defaultValue = null) -> var;

	/**
	 * Isset property
	 */
	public function has(string! property) -> bool;

	/**
	 * Initializes the session bag. This method must not be called directly, the
	 * class calls it when its internal data is accessed
	 */
	public function initialize();

	/**
	 * Setter of values
	 */
	public function set(string! property, var value);
}

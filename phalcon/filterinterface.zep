
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\FilterInterface
 *
 * Interface for Phalcon\Filter
 */
interface FilterInterface
{

	/**
	 * Adds a user-defined filter
	 */
	public function add(string! name, handler) -> <FilterInterface>;

	/**
	 * Sanizites a value with a specified single or set of filters
	 */
	public function sanitize(value, filters) -> var;

	/**
	 * Return the user-defined filters in the instance
	 */
	public function getFilters() -> array;
}

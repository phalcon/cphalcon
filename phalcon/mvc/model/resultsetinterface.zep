
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Cache\BackendInterface;
use Phalcon\Messages\MessageInterface;

/**
 * Phalcon\Mvc\Model\ResultsetInterface
 *
 * Interface for Phalcon\Mvc\Model\Resultset
 */
interface ResultsetInterface
{
	/**
	 * Returns the internal type of data retrieval that the resultset is using
	 */
	public function getType() -> int;

	/**
	 * Get first row in the resultset
	 */
	public function getFirst() -> <ModelInterface> | bool;

	/**
	 * Get last row in the resultset
	 */
	public function getLast() -> <ModelInterface> | bool;

	/**
	 * Set if the resultset is fresh or an old one cached
	 */
	public function setIsFresh(bool isFresh);

	/**
	 * Tell if the resultset if fresh or an old one cached
	 */
	public function isFresh() -> bool;

	/**
	 * Returns the associated cache for the resultset
	 */
	public function getCache() -> <BackendInterface>;

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does.
	 */
	public function toArray() -> array;

	/**
	 * Sets the hydration mode in the resultset
	 */
	public function setHydrateMode(int hydrateMode) -> <Resultset>;

	/**
	 * Returns the current hydration mode
	 */
	public function getHydrateMode() -> int;

	/**
	 * Returns the error messages produced by a batch operation
	 */
	public function getMessages() -> <MessageInterface[]>;

	/**
	 * Updates every record in the resultset
	 *
	 * @param array data
	 */
	public function update(var data, <\Closure> conditionCallback = null) -> bool;

	/**
	 * Deletes every record in the resultset
	 */
	public function delete(<\Closure> conditionCallback = null) -> bool;

	/**
	 * Filters a resultset returning only those the developer requires
	 *
	 *<code>
	 * $filtered = $robots->filter(
	 *     function ($robot) {
	 *         if ($robot->id < 3) {
	 *             return $robot;
	 *         }
	 *     }
	 * );
	 *</code>
	 *
	 * @return \Phalcon\Mvc\Model[]
	 */
	public function filter(callable filter) -> array;
}

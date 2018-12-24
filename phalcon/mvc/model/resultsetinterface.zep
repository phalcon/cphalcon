
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
}

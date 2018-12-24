
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\QueryInterface
 *
 * Interface for Phalcon\Mvc\Model\Query
 */
interface QueryInterface
{

	/**
	 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
	 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
	 */
	public function parse() -> array;

	/**
	 * Sets the cache parameters of the query
	 */
	public function cache(array cacheOptions) -> <QueryInterface>;

	/**
	 * Returns the current cache options
	 */
	public function getCacheOptions() -> array;

	/**
	 * Tells to the query if only the first row in the resultset must be returned
	 */
	public function setUniqueRow(bool uniqueRow) -> <QueryInterface>;

	/**
	 * Check if the query is programmed to get only the first row in the resultset
	 */
	public function getUniqueRow() -> bool;

	/**
	 * Executes a parsed PHQL statement
	 *
	 * @param array bindParams
	 * @param array bindTypes
	 * @return mixed
	 */
	public function execute(bindParams = null, bindTypes = null);
}

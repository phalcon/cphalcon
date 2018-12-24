
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

/**
 * Phalcon\Paginator\AdapterInterface
 *
 * Interface for Phalcon\Paginator adapters
 */
interface AdapterInterface
{
	/**
	 * Set the current page number
	 */
	public function setCurrentPage(int page);

	/**
	 * Returns a slice of the resultset to show in the pagination
	 */
	public function paginate() -> <RepositoryInterface>;

	/**
	 * Set current rows limit
	 */
	public function setLimit(int limit);

	/**
	 * Get current rows limit
	 */
	public function getLimit() -> int;
}

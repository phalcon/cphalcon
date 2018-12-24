
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
 * Phalcon\Paginator\RepositoryInterface
 *
 * Interface for the repository of current state Phalcon\Paginator\AdapterInterface::getPaginate()
 */
interface RepositoryInterface
{
	const PROPERTY_ITEMS            = "items";
	const PROPERTY_TOTAL_ITEMS      = "total_items";
	const PROPERTY_LIMIT            = "limit";
	const PROPERTY_FIRST_PAGE       = "first";
	const PROPERTY_PREVIOUS_PAGE    = "previous";
	const PROPERTY_CURRENT_PAGE     = "current";
	const PROPERTY_NEXT_PAGE        = "next";
	const PROPERTY_LAST_PAGE        = "last";

	/**
	 * Sets values for properties of the repository
	 */
	public function setProperties(array properties) -> <RepositoryInterface>;

	/**
	 * Sets the aliases for properties repository
	 */
	public function setAliases(array aliases) -> <RepositoryInterface>;

	/**
	 * Gets the aliases for properties repository
	 */
	public function getAliases() -> array;

	/**
	 * Gets the items on the current page
	 */
	public function getItems() -> var;

	/**
	 * Gets the total number of items
	 */
	public function getTotalItems() -> int;

	/**
	 * Gets current rows limit
	 */
	public function getLimit() -> int;

	/**
	 * Gets number of the first page
	 */
	public function getFirst() -> int;

	/**
	 * Gets number of the previous page
	 */
	public function getPrevious() -> int;

	/**
	 * Gets number of the current page
	 */
	public function getCurrent() -> int;

	/**
		 * Gets number of the next page
	 */
	public function getNext() -> int;

	/**
	 * Gets number of the last page
	 */
	public function getLast() -> int;
}

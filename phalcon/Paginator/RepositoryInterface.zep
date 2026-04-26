
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

/**
 * Phalcon\Paginator\RepositoryInterface
 *
 * Interface for the repository of current state
 * Phalcon\Paginator\AdapterInterface::paginate()
 */
interface RepositoryInterface
{
    /**
     * @var string
     */
    const PROPERTY_CURRENT_PAGE  = "current";
    /**
     * @var string
     */
    const PROPERTY_FIRST_PAGE    = "first";
    /**
     * @var string
     */
    const PROPERTY_ITEMS         = "items";
    /**
     * @var string
     */
    const PROPERTY_LAST_PAGE     = "last";
    /**
     * @var string
     */
    const PROPERTY_LIMIT         = "limit";
    /**
     * @var string
     */
    const PROPERTY_NEXT_PAGE     = "next";
    /**
     * @var string
     */
    const PROPERTY_PREVIOUS_PAGE = "previous";
    /**
     * @var string
     */
    const PROPERTY_TOTAL_ITEMS   = "total_items";

    /**
     * Gets the aliases for properties repository
     */
    public function getAliases() -> array;

    /**
     * Gets number of the current page
     */
    public function getCurrent() -> int;

    /**
     * Gets number of the first page
     */
    public function getFirst() -> int;

    /**
     * Gets the items on the current page
     */
    public function getItems() -> var;

    /**
     * Gets number of the last page
     */
    public function getLast() -> int;

    /**
     * Gets current rows limit
     */
    public function getLimit() -> int;

    /**
     * Gets number of the next page
     */
    public function getNext() -> int;

    /**
     * Gets number of the previous page
     */
    public function getPrevious() -> int;

    /**
     * Gets the total number of items
     */
    public function getTotalItems() -> int;

    /**
     * Sets the aliases for properties repository
     */
    public function setAliases(array aliases) -> <RepositoryInterface>;

    /**
     * Sets values for properties of the repository
     */
    public function setProperties(array properties) -> <RepositoryInterface>;
}
